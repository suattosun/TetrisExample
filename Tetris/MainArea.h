#pragma once
#include <vector>
#include <SDL.h>
#include"Point.h"
 
class MainArea
{
public:
	MainArea();
	bool IsMoveUp(const int posX, const int posY);
	bool IsMoveDown(const int posX, const int posY);
	bool IsMoveRight(const int posX, const int posY);
	bool IsMoveLeft(const int posX, const int posY);
	void NewLocationAssign(int currentCell, std::string name);
	void ResetData( int );
	int GetCellSize();
	bool IsGameEnd();
	std::pair<bool, int> IsThePairComplete();
	std::pair<int, int> GetAreaSize();
	std::pair<int, int> GetCellCount();
	std::pair<int, int> GetStartPos();
	void makeArea(SDL_Renderer* renderer, int x, int y, Uint8 r, Uint8 g, Uint8 b, Uint8 a);
	void makeScoreArea(SDL_Renderer* renderer, int x, int y, Uint8 r, Uint8 g, Uint8 b, Uint8 a);
	void makeGrill(SDL_Renderer* renderer, int x, int y, Uint8 r, Uint8 g, Uint8 b, Uint8 a);
	void makeNextPieceGrill(SDL_Renderer* renderer, int x, int y, Uint8 r, Uint8 g, Uint8 b, Uint8 a);
	void showConsoleArea();
	void vecDeleteRow(int rowBegin);
 
 
private:
	std::vector<Point>areaVec;
	int areaMaxX = 300;
	int areaMaxY = 600;
	int startPosX = 50;
	int startPosY = 50;
	int cellCountX = 10;
	int cellCountY = 20;
	int cellSize = 30;
	friend class MainWindow;
 
};

