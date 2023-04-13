#include "SquareBricks.h"
#include <iostream>
#include <string>


SquareBricks::SquareBricks(SDL_Renderer* renderer, MainArea* area, int posX, int posY) :ShapeBricks{ renderer, area, posX , posY , posX + area->GetCellSize() , posY , posX, posY + area->GetCellSize(), posX + area->GetCellSize() , posY + area->GetCellSize() , SDL_Color(255, 255, 102, 255) }
{
}
SquareBricks::SquareBricks(const SquareBricks& other) :ShapeBricks{ other } {

}
void SquareBricks::SetPosCoord(int x, int y)
{
	SetShapeBrickPos(x, y, x + mainArea->GetCellSize(), y, x, y + mainArea->GetCellSize(), x + mainArea->GetCellSize(), y + mainArea->GetCellSize());
}
void SquareBricks::RotateBricks() {

}
