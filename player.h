#include <SFML\Graphics.hpp>

using namespace sf;


class PLAYER {

public:

	float offsetX = 0;
	float offsetY = 0;
	float dx;
	float dy;
	int ground = 800;
	bool onGround;
	bool LeftOrRightNavigation = 0;
	bool flagOfWin;
	bool flagOfLose;
	float currentFrame;


	FloatRect rect;
	Sprite spriteHero;
	PLAYER(Texture &image);

	/**
		*	Метод устанавливает игрока в стартовую позицию
	*/
	void RestarPosition();

	/**
		*	Метод смещает позицию игрока и задает анимацию
		*	+ поворот в сторону последнего смещения
	*/
	void PLAYER::update(float time, sf::String TileMap[]);

	void Hit(float time); //пока не реализован
	/**
	*	Метод реализует прыжок
	*	+ поворот в сторону последнего смещения
	*/
	void Jamp();
	/**
	*	Метод-обработчик столкновений с картой
	*/
	void Collision(int XOrY, sf::String TileMap[]);

};
