#pragma once
#include"ShapeBricks.h"
#include<random>
class TBricks : public ShapeBricks
{
public:
	TBricks(SDL_Renderer* renderer, MainArea* area, int posX , int posY );
	TBricks(const TBricks& other);
	void RotateBricks();
	void SetPosCoord(int x, int y)override;
private:

 
	int turnCount = 0;

 

};

