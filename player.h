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
		*	����� ������������� ������ � ��������� �������
	*/
	void RestarPosition();

	/**
		*	����� ������� ������� ������ � ������ ��������
		*	+ ������� � ������� ���������� ��������
	*/
	void PLAYER::update(float time, sf::String TileMap[]);

	void Hit(float time); //���� �� ����������
	/**
	*	����� ��������� ������
	*	+ ������� � ������� ���������� ��������
	*/
	void Jamp();
	/**
	*	�����-���������� ������������ � ������
	*/
	void Collision(int XOrY, sf::String TileMap[]);

};
