#pragma once
#include"ShapeBricks.h"
#include<SDL.h>
class SquareBricks : public ShapeBricks
{
public:
	SquareBricks(SDL_Renderer* renderer, MainArea* area, int posX , int posY);
	void RotateBricks()override;
	SquareBricks(const SquareBricks& other);
	void SetPosCoord(int x, int y)override;
private:


	int turnCount = 0;



};