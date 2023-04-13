#pragma once
#include<random>
#include<SDL.h>
#include"ShapeBricks.h"
class JBricks : public ShapeBricks
{
public:
	JBricks(SDL_Renderer* renderer, MainArea* area, int posX , int posY );
	JBricks(const JBricks& other);
	void RotateBricks()override;
	void SetPosCoord(int x, int y)override;

private:

	 
	int turnCount = 0;



};

