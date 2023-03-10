#include "MyMap.h"
#include <string>


MyMap::MyMap(Texture &mapTexture)
{	
	initializationMap(TileMap);	

	spriteMap.setTexture(mapTexture);
	spriteMap.setTextureRect(IntRect(40, 35, 70, 150));
}

void MyMap::initializationMap(sf::String TileMap[])
{
	
	TileMap[0] = "BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB";		//1
	TileMap[1] = "B                                                 B";		//2
	TileMap[2] = "B                                                 B";		//3
	TileMap[3] = "B                                                 B";		//4
	TileMap[4] = "B                                             W   B";		//5
	TileMap[5] = "B                       BBBBBBBBBBBBBBBBBBBBBBBBBBB";		//6
	TileMap[6] = "B                BBBB                             B";		//7
	TileMap[7] = "B         BBBB                                    B";		//8
	TileMap[8] = "B   BBBB                                          B";		//9
	TileMap[9] = "B                BBBB                 BBBB        B";		//10
	TileMap[10] = "B                                                 B";	//11
	TileMap[11] = "B          BBBB           0000                    B";	//12
	TileMap[12] = "B                                                 B";	//13
	TileMap[13] = "B  BBBBB                           BBBB           B";	//14
	TileMap[14] = "B                    0000                         B";	//15
	TileMap[15] = "B       BBBB                          BBBB        B";	//16
	TileMap[16] = "B                                                 B";	//17
	TileMap[17] = "B            BBBB            BBBB                 B";	//18
	TileMap[18] = "B                                                 B";	//19
	TileMap[19] = "B                  BBBB                           B";	//20
	TileMap[20] = "B                                                 B";	//21
	TileMap[21] = "BBBBBB                                            B";	//22
	TileMap[22] = "B      VVVVVV                                     B";	//23
	TileMap[23] = "BVVVVVVBBBBBBVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVB";	//24
	TileMap[24] = "BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB";	//25
}



void MyMap::DrawMap(RenderWindow &TheWindow, float X, float Y, bool flagOfWin)
{	
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < wight; j++)
		{
			if (TileMap[i][j] == 'B')
			{
				spriteMap.setTextureRect(IntRect(318, 481, 64, 64));
			}
			else if (TileMap[i][j] == '0')
			{
				spriteMap.setTextureRect(IntRect(455, 342, 64, 64));
			}
			else if (TileMap[i][j] == ' ')
			{
				spriteMap.setTextureRect(IntRect(820, 480, 64, 64));
			}
			else if (TileMap[i][j] == 'V')
			{
				spriteMap.setTextureRect(IntRect(177, 411, 64, 64));
			}
			else if (TileMap[i][j] == 'W')
			{
				spriteMap.setTextureRect(IntRect(176, 133, 64, 64));
				if (flagOfWin == 1)
				{
					spriteMap.setTextureRect(IntRect(246, 133, 64, 64));
				}
			}
			
			spriteMap.setPosition(j * 64 - X, i * 64 - Y);
			TheWindow.draw(spriteMap);
		}
	}
}


void MyMap::EasilyDrawMap(RenderWindow &TheWindow, float X, float Y)
{
	RectangleShape rectangle(sf::Vector2f(32, 32));

	for (int i = 0; i < height; i++)
	for (int j = 0; j < wight; j++)
	{
		if (TileMap[i][j] == 'B')
			rectangle.setFillColor(Color::Black);
		else if (TileMap[i][j] == '0')
			rectangle.setFillColor(Color::Green);
		else if (TileMap[i][j] == ' ')
			continue;

		rectangle.setPosition(j * 32 - X, i * 32 - Y);
		TheWindow.draw(rectangle);
	}
}