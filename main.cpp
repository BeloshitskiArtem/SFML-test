#include <iostream>
#include <sstream>

#include <SFML\Graphics.hpp>
//#include "SFML\Graphics\Font.hpp"
//#include <Font.hpp>

#include "player.h"
#include "MyMap.h"

using namespace sf;

/**
	*	Функция-обработчик событий конца игрый
	*	(столконовение с шипами либо с кнопкой)
*/
void TheEndOfGame(std::string message,  
				RenderWindow &TheWindow,
				PLAYER &player,
				MyMap &map)
{	
	//Font font;
	//font.loadFromFile("CyrilicOld.ttf");
	//Text text;
	//text.setColor(Color::Red);
	//text.setStyle(Text::Bold);

	//std::ostringstream messageEnd;
	//messageEnd << message;
	//text.setString(message);
	//text.setPosition(100, 100);
	//TheWindow.draw(text);

	static bool IsBurronClickFlag = 0;
	if (IsBurronClickFlag == 0)
	{
		std::cout << message << " Click on Enter for restar game, or ESC for close game!!!" << std::endl;
		IsBurronClickFlag = 1;
	}
	if (Keyboard::isKeyPressed(Keyboard::Enter))
	{
		player.RestarPosition();
		IsBurronClickFlag = 0;
	}
	else if (Keyboard::isKeyPressed(Keyboard::Escape))
	{
		TheWindow.close();
	}
}


void StartGame()
{
	float currentFrame = 0;
	RenderWindow window(VideoMode(700, 700), "SFML-Project");

	Clock clock;

	/**
	*	текстурка ГГ
	*/
	Texture heroTexture;
	heroTexture.loadFromFile("image/test.png");

	/**
	*	текстурка для прорисовки карты
	*/
	Texture mapTexture;
	mapTexture.loadFromFile("image/setmap.png");

	PLAYER player(heroTexture);
	MyMap map(mapTexture);

	while (window.isOpen())
	{
		float timerTick = clock.getElapsedTime().asMicroseconds();
		clock.restart();
		timerTick /= 1100;

		Event event;

		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

		if (player.flagOfLose == 0 && player.flagOfWin == 0)
		{

			if (Keyboard::isKeyPressed(Keyboard::Left))
			{
				player.dx = -0.25;
			}
			if (Keyboard::isKeyPressed(Keyboard::Right))
			{
				player.dx = 0.25;
			}
			if (Keyboard::isKeyPressed(Keyboard::Up))
			{
				if (player.onGround == 1)
				{
					player.dy = -0.4;
					player.Jamp();
					player.onGround = false;
				}
			}
			/*if (Keyboard::isKeyPressed(Keyboard::Enter))
			{
				player.Hit(timerTick);
			}*/
		}
		else if (player.flagOfLose == 1)
		{
			player.spriteHero.setColor(Color::Red);
			TheEndOfGame("Game Lose!", window, player, map);
		}
		else if (player.flagOfWin == 1)
		{
			player.spriteHero.setColor(Color::Green);
			TheEndOfGame("Game Win!", window, player, map);
		}
		

		player.update(timerTick, map.TileMap);

		if (player.rect.left < 2570) player.offsetX = player.rect.left - height / 2;
			player.offsetY = player.rect.top - wight / 2;


		window.clear(Color::White);
		map.DrawMap(window, player.offsetX, player.offsetY, player.flagOfWin);
		window.draw(player.spriteHero);
		window.display();
	}
}


int main() 
{
	StartGame();
	return 0;

}