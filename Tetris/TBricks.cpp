#include "TBricks.h"
#include <iostream>
#include <string>
 

TBricks::TBricks(SDL_Renderer* renderer, MainArea* area, int posX,int posY) :ShapeBricks{  renderer, area, posX + area->GetCellSize(), posY + area->GetCellSize(), posX, posY + area->GetCellSize() * 2, posX, posY + area->GetCellSize(), posX, posY,  SDL_Color(204, 0, 204, 255) }
{
}
TBricks::TBricks(const TBricks& other) :ShapeBricks{ other } {

}
void TBricks::SetPosCoord(int x, int y)
{
	SetShapeBrickPos(x + mainArea->GetCellSize(), y + mainArea->GetCellSize(), x, y + mainArea->GetCellSize() * 2, x, y + mainArea->GetCellSize(), x, y);
}
void TBricks::RotateBricks(){
	if (!isCollidingDown) {
		turnCount++;
		AllBrickResetVector();
		switch (turnCount) {
		case 0: // |-
			brick1->SetBrickCoord(brick1->GetPosX() + mainArea->GetCellSize(), brick1->GetPosY() + mainArea->GetCellSize());
			brick2->SetBrickCoord(brick2->GetPosX() - mainArea->GetCellSize(), brick2->GetPosY() + mainArea->GetCellSize());
			brick3->SetBrickCoord(brick3->GetPosX(), brick3->GetPosY());
			brick4->SetBrickCoord(brick4->GetPosX() + mainArea->GetCellSize(), brick4->GetPosY() - mainArea->GetCellSize());
			break;
		case 1://T
			brick1->SetBrickCoord(brick1->GetPosX() - mainArea->GetCellSize(), brick1->GetPosY() + mainArea->GetCellSize());
			brick2->SetBrickCoord(brick2->GetPosX() - mainArea->GetCellSize(), brick2->GetPosY() - mainArea->GetCellSize());
			brick3->SetBrickCoord(brick3->GetPosX(), brick3->GetPosY());
			brick4->SetBrickCoord(brick4->GetPosX() + mainArea->GetCellSize(), brick4->GetPosY() + mainArea->GetCellSize());
			break;
		case 2:
			brick1->SetBrickCoord(brick1->GetPosX() - mainArea->GetCellSize(), brick1->GetPosY() - mainArea->GetCellSize());
			brick2->SetBrickCoord(brick2->GetPosX() + mainArea->GetCellSize(), brick2->GetPosY() - mainArea->GetCellSize());
			brick3->SetBrickCoord(brick3->GetPosX(), brick3->GetPosY());
			brick4->SetBrickCoord(brick4->GetPosX() - mainArea->GetCellSize(), brick4->GetPosY() + mainArea->GetCellSize());
			break;
		case 3:
			brick1->SetBrickCoord(brick1->GetPosX() + mainArea->GetCellSize(), brick1->GetPosY() - mainArea->GetCellSize());
			brick2->SetBrickCoord(brick2->GetPosX() + mainArea->GetCellSize(), brick2->GetPosY() + mainArea->GetCellSize());
			brick3->SetBrickCoord(brick3->GetPosX(), brick3->GetPosY());
			brick4->SetBrickCoord(brick4->GetPosX() - mainArea->GetCellSize(), brick4->GetPosY() - mainArea->GetCellSize());
			turnCount = -1;
			break;
		}
	}
}
 
/*
mName{ NameCreater() }, brick1{ new Brick(mRenderer,mainArea,mName,posX + mainArea->GetCellSize(),posY + mainArea->GetCellSize() , mainArea->GetCellSize(), mainArea->GetCellSize()) }, brick2{ new Brick(mRenderer,mainArea, mName ,posX, posY + +mainArea->GetCellSize() * 2  , mainArea->GetCellSize(), mainArea->GetCellSize()) },
brick3{ new Brick(mRenderer,mainArea,mName,posX,posY + mainArea->GetCellSize(), mainArea->GetCellSize(), mainArea->GetCellSize()) }, brick4{ new Brick(mRenderer,mainArea,mName,posX,posY , mainArea->GetCellSize(), mainArea->GetCellSize()) }
{
 */