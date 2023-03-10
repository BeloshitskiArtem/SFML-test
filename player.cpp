#include "player.h"
#include "MyMap.h"

PLAYER::PLAYER(Texture &image)
{
	spriteHero.setTexture(image);
	spriteHero.setTextureRect(IntRect(40, 35, 70, 150));
	RestarPosition();
}


void PLAYER::RestarPosition()
{
	spriteHero.setColor(Color::White);
	rect = FloatRect(200, ground, 70, 120);
	dx = dy = 0;
	currentFrame = 0;

	flagOfLose = 0;
	flagOfWin = 0;
}


void PLAYER::update(float time, sf::String TileMap[])
{

	rect.left += dx * time;

	Collision(0, TileMap);

	if (!onGround) dy = dy + 0.0005*time;
	rect.top += dy*time;
	onGround = false;

	Collision(1, TileMap);

	currentFrame += 0.005 * time;
	if (currentFrame > 6) currentFrame -= 6;

	if (dx > 0 && onGround == 1)
	{
		spriteHero.setTextureRect(IntRect(145 * int(currentFrame) + 125, 325, -125, 120));
		LeftOrRightNavigation = 1;
	}
	if (dx < 0 && onGround == 1)
	{
		spriteHero.setTextureRect(IntRect(145 * int(currentFrame), 325, 125, 120));
		LeftOrRightNavigation = 0;
	}
	if (dx == 0 && LeftOrRightNavigation == 0 && onGround == 1)
	{
		spriteHero.setTextureRect(IntRect(40, 35, 70, 150));
	}
	if (dx == 0 && LeftOrRightNavigation == 1 && onGround == 1)
	{
		spriteHero.setTextureRect(IntRect(40 + 70, 35, -70, 150));
	}

	spriteHero.setPosition(rect.left - offsetX, rect.top - offsetY);
	dx = 0;
}




void PLAYER::Jamp()
{
	if (LeftOrRightNavigation)
		spriteHero.setTextureRect(IntRect(600 + 90, 180, -90, 100));

	else if (LeftOrRightNavigation == 0)
		spriteHero.setTextureRect(IntRect(600, 180, 90, 100));
}




/*void PLAYER::Hit(float time)
{
	if (currentFrame < 4)
	{
		rect.left += -0.07 * time;
		spriteHero.setTextureRect(IntRect(10 * int(currentFrame), 470, 70, 150));
	}
}*/



void PLAYER::Collision(int XOrY, sf::String TileMap[])
{
	for (int i = rect.top/64; i<(rect.top+rect.height)/64; i++)
		for (int j = rect.left/64; j<(rect.left + rect.width)/64; j++)
		{
			if (TileMap[i][j] == 'B')
			{
				if (dx>0 && XOrY==0)
					rect.left = j * 64 - rect.width;

				if (dx<0 && XOrY == 0)
					rect.left = j * 64 + 64;

				if (dy>0 && XOrY == 1)
				{
					rect.top = i * 64 - rect.height;
					dy = 0;
					onGround = true;
				}

				if (dy<0 && XOrY == 1)
				{
					rect.top = i * 64 + 64;
					dy = 0;
				}
			}
			if (TileMap[i][j] == '0')
			{
				TileMap[i][j] = ' ';
				Jamp();
			}
			if (TileMap[i][j] == 'V')
			{
				flagOfLose = 1;
			}
			if (TileMap[i][j] == 'W')
			{
				flagOfWin = 1;
			}
		}
}
