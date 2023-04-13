#pragma once
#include<random>
#include<SDL.h>
#include"ShapeBricks.h"
class LBricks : public ShapeBricks
{
public:
	LBricks(SDL_Renderer* renderer, MainArea* area, int posX , int posY );
	LBricks(const LBricks& other);
	void RotateBricks()override;
	void SetPosCoord(int x, int y)override;

private:


	int turnCount = 0;
 


};

