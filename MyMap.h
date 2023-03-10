#include <SFML\Graphics.hpp>


using namespace sf;

	const int height = 25;
	const int wight = 51;

class MyMap
{

public:

	sf::String TileMap[height];
	Sprite spriteMap;

	MyMap(Texture &mapTexture);
	void MyMap::initializationMap(sf::String TileMap[]);
	void DrawMap(RenderWindow &TheWindow, float X, float Y, bool flagOfWin);
	void EasilyDrawMap(RenderWindow &TheWindow, float X, float Y); 
};