#pragma once
#include<random>
#include<SDL.h>
#include"ShapeBricks.h"
class SBricks : public ShapeBricks
{
public:
	SBricks(SDL_Renderer* renderer, MainArea* area, int posX , int posY);
	SBricks(const SBricks& other);
	void RotateBricks()override;
	void SetPosCoord(int x, int y)override;
private:


	int turnCount = 0;
 


};

