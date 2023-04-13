#pragma once
#include<SDL.h>
#include<memory>
 
#include"MainArea.h"
#include"ShapeBricks.h"
#include "IBricks.h"
#include "Tbricks.h"
#include "JBricks.h"
#include "SBricks.h"
#include "SquareBricks.h"
#include "ZBricks.h"
#include "LBricks.h"
#include "Brick.h"
#include<SDL_ttf.h>
#include<SDL_mixer.h>

class MainWindow
{
public:
	MainWindow();
	~MainWindow();
	void setup();
	void update();
	void makeArea(int x, int y, Uint8 r, Uint8 g, Uint8 b, Uint8 a);
	void makeGrill(int x, int y, Uint8 r, Uint8 g, Uint8 b, Uint8 a);
	void CreateNewBrick(bool status);
	void BrickMovementEnd();
	void ChangePosVector();
	bool IsGameOver();
	void AddVectorElement();
	void AddBrickFromBrickVecTosetBrick();
	void DestroyBlock();
	void ResetMatrixBecomePair(int _howCellIsComplete);
	void RenderUpdate();
	int CalculatePoint(int);
	void DrawTextSDL(const char* text, int x, int y, SDL_Color color);
	ShapeBricks* GenerateBricks();

private:
	SDL_Window* window;
	SDL_Renderer* renderer;
	TTF_Font* font = nullptr;
	Mix_Music* bgMusic;
	Mix_Chunk* sounfEffect;
	Mix_Chunk* brickSfx;
	Mix_Chunk* gameOverEffect;
	std::unique_ptr<MainArea> MyArea;
	std::vector<ShapeBricks*> brickVec;
	std::vector < std::shared_ptr<Brick>> setBrick;
	bool isRunning = false;
	int areaMaxX = 300;
	int areaMaxY = 600;
	bool isCreateNewBrick = false;
	int sumPoint = 0;
};
 