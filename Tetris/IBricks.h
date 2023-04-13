#pragma once
 
#include"ShapeBricks.h"
class IBricks: public ShapeBricks
{
public:
	IBricks(SDL_Renderer* renderer, MainArea* area, int posX , int posY );
	void RotateBricks()override;
	IBricks(const IBricks& ohter);
	void SetPosCoord(int x, int y)override;

private:
	int turnCount = 0;
	 
};

