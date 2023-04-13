#include "MainArea.h"
#include <iostream>
 
MainArea::MainArea() :areaVec(200, Point{0,""}) {}

bool MainArea::IsMoveUp(const int posX, const int posY)
{
	const auto nextCell = ((posX - startPosX) / cellSize) + ((posY - startPosY - cellSize) / cellSize) * cellCountX;
	const auto currentCell = ((posX - startPosX) / cellSize) + ((posY - startPosY) / cellSize) * cellCountX;
	if ((posY - startPosY)  > 0) {
		if (!areaVec[nextCell].coord || areaVec[currentCell].name == areaVec[nextCell].name) {
			return true;
		}
	}
	return false;
}

bool MainArea::IsMoveDown(const int posX,const int posY )
{
	const auto nextCell = ((posX - startPosX) / cellSize) + ((posY - startPosY + cellSize) / cellSize) * cellCountX;
	const auto currentCell = ((posX - startPosX) / cellSize) + ((posY - startPosY) / cellSize) * cellCountX;
	if ((posY ) / cellSize < cellCountY ) {
		if (!areaVec[nextCell].coord || areaVec[currentCell].name == areaVec[nextCell].name){
			return true;
		}
	}
	return false;
}

bool MainArea::IsMoveRight(const int posX, const int posY)
{
	const auto nextCell = ((posX - startPosX + cellSize) / cellSize) + ((posY - startPosY ) / cellSize) * cellCountX;
	const auto currentCell = ((posX - startPosX) / cellSize) + ((posY - startPosY) / cellSize) * cellCountX;
	
	if (((posX ) / cellSize < cellCountX)) {
		if (!areaVec[nextCell].coord || areaVec[currentCell].name == areaVec[nextCell].name) {
			return true;
		}
	}
	return false;
}

bool MainArea::IsMoveLeft( const int posX, const int posY)
{
	const auto nextCell = ((posX - startPosX - cellSize) / cellSize) + ((posY - startPosY) / cellSize) * cellCountX;
	const auto currentCell = ((posX - startPosX) / cellSize) + ((posY - startPosY) / cellSize) * cellCountX;
	//if (posX - startPosX > 0)
	if ((posX - startPosX) > 0) {
		if (!areaVec[nextCell].coord || areaVec[currentCell].name == areaVec[nextCell].name) {
			return true;
		}
	}
	return false;

}


void MainArea::NewLocationAssign(int currentCell, std::string name)
{
	areaVec[currentCell].coord = 1;
	areaVec[currentCell].name = name;
}
void MainArea::ResetData(int preCell) {
 
	areaVec[preCell].coord = 0;
	areaVec[preCell].name = "";
 
}
 
int MainArea::GetCellSize()
{
	return cellSize;
}

bool MainArea::IsGameEnd()
{
	for (int i = 0; i < 20; i++) {
		if (areaVec[i].coord == 1)
			return true;
	}
	return false;
}

std::pair<bool, int> MainArea::IsThePairComplete()
{
	int count = 0;
	int startIndex = 0;
	int stepSize = 10;
	for (int column = 0; column < 20; column++) {
		for (int row = stepSize * column; row <  stepSize*(column+1); row++) {
			if (areaVec[row].coord) {
				count++;
			}
		}
		if (count == 10) {
			return  std::pair<bool, int>(true, (stepSize * column));
		}
			count = 0;	 
	}
	return std::pair<bool, int>(false,0);
}
void MainArea::vecDeleteRow(int rowBegin) {
	for (int index = rowBegin; index < rowBegin + 10; ++index) {
		ResetData(index);

	}
}
std::pair<int, int> MainArea::GetAreaSize()
{
	return std::pair<int, int>(areaMaxX, areaMaxY);
}
std::pair<int, int> MainArea::GetCellCount()
{
	return std::pair<int, int>(cellCountX, cellCountY);
}

std::pair<int, int> MainArea::GetStartPos()
{
	return std::pair<int, int>(startPosX, startPosY);
}

void MainArea::showConsoleArea()
{
		std::cout << "\n********************************\n";
	for (int i = 0; i < cellCountX * cellCountY; i++) {
		if(i % cellCountX == 0 && i != 0)
			 std::cout << '\n';
		std::cout << areaVec[i].coord << ' ';
	}

}
 
void MainArea::makeArea(SDL_Renderer* renderer, int x, int y, Uint8 r, Uint8 g, Uint8 b, Uint8 a)
{
	SDL_Rect areaRect{ x,y,areaMaxX, areaMaxY };
	SDL_SetRenderDrawColor(renderer, r, g, b, a);
	SDL_RenderDrawRect(renderer, &areaRect);
}
void MainArea::makeGrill(SDL_Renderer* renderer, int x, int y, Uint8 r, Uint8 g, Uint8 b, Uint8 a)
{
	SDL_SetRenderDrawColor(renderer, r, g, b, a);
	for (int y1 = y; y1 <= (areaMaxY + y); y1 += (areaMaxY / 20)) {
		int x2 = x + areaMaxX;
		SDL_RenderDrawLine(renderer, x, y1, x2, y1);
	}
	for (int x1 = x; x1 <= (areaMaxX + x); x1 += (areaMaxX / 10)) {
		int y2 = y + areaMaxY;
		SDL_RenderDrawLine(renderer, x1, y, x1, y2);
	}
 
}

void MainArea::makeNextPieceGrill(SDL_Renderer* renderer, int x, int y, Uint8 r, Uint8 g, Uint8 b, Uint8 a)
{
	SDL_SetRenderDrawColor(renderer, r, g, b, a);
	for (int y1 = y; y1 <= ((areaMaxY / 20) * 4 + y); y1 += (areaMaxY / 20)) {
		int x2 = x + ((areaMaxY / 20) * 3 );
		SDL_RenderDrawLine(renderer, x, y1, x2, y1);
	}
	for (int x1 = x; x1 <= ((areaMaxX / 10) * 3 + x); x1 += (areaMaxX / 10)) {
		int y2 = y + ((areaMaxX / 10) * 4 );
		SDL_RenderDrawLine(renderer, x1, y, x1, y2);

	}
 
}
void MainArea::makeScoreArea(SDL_Renderer* renderer, int x, int y, Uint8 r, Uint8 g, Uint8 b, Uint8 a)
{
	SDL_SetRenderDrawColor(renderer, r, g, b, a);
	SDL_Rect areaRect{ x,y, (areaMaxX / 10) * 6, (areaMaxX / 10) };
	SDL_SetRenderDrawColor(renderer, r, g, b, a);
	SDL_RenderDrawRect(renderer, &areaRect);
	 
 

}
 