#pragma once
#include<random>
#include<SDL.h>
#include"ShapeBricks.h"
class ZBricks : public ShapeBricks
{
public:
	ZBricks(SDL_Renderer* renderer, MainArea* area, int posX, int posY );
	void RotateBricks()override;
	ZBricks(const ZBricks& other);
	void SetPosCoord(int x, int y)override;

private:


	int turnCount = 0;
	 


};

