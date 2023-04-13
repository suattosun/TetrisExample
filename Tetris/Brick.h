#pragma once
#include<SDL.h>
#include<compare>
#include "MainArea.h"
class Brick
{
public:
	Brick(SDL_Renderer* surface, MainArea *area ,std::string name, SDL_Color color,int x, int y, int w, int h);
	~Brick();
	void ResetVectorData(int x, int y);
	void BrickAutoMove();
	void BrickUpdate();
	void BrickManuelMoveRight();
	void BrickManuelMoveLeft();
	void BrickManuelMoveDown();
	void BrickManuelMoveUp();
	void BrickDestroyEffect();
	void SetBrickCoord(int x, int y);
	int GetPosX();
	int GetPosY();
	void Move();
	std::string GetName();
	void CellCalculate();
	auto operator<=>(const Brick* p1)const;
	bool operator==(int s)const;
	bool operator!=(int s)const;
	int GetCellNo();

 
private:
	SDL_Renderer* brickrenderer;
	MainArea* myArea;
	std::string mName;
	int brickX, brickY, brickH, brickW;
	SDL_Rect brickRect;
	int cell ;
	SDL_Color mColor;

 
};

