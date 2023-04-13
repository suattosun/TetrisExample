#include "LBricks.h"
#include <iostream>
#include <string>


LBricks::LBricks(SDL_Renderer* renderer, MainArea* area, int posX, int posY) :ShapeBricks{ renderer, area, posX , posY , posX, posY + area->GetCellSize(), posX, posY + area->GetCellSize() * 2, posX + area->GetCellSize() , posY + area->GetCellSize() * 2  , SDL_Color(51, 102, 255, 255) }
{
}
LBricks::LBricks(const LBricks& other) :ShapeBricks{ other } {

}
void LBricks::SetPosCoord(int x, int y)
{
	SetShapeBrickPos(x, y, x, y + mainArea->GetCellSize(), x, y + mainArea->GetCellSize() * 2, x + mainArea->GetCellSize(), y + mainArea->GetCellSize() * 2);
}
void LBricks::RotateBricks() {
	if (!isCollidingDown) {
		turnCount++;
		AllBrickResetVector();
		switch (turnCount) {
		case 0: // |-
			brick1->SetBrickCoord(brick1->GetPosX() + mainArea->GetCellSize(), brick1->GetPosY() - mainArea->GetCellSize() );
			brick2->SetBrickCoord(brick2->GetPosX() , brick2->GetPosY() );
			brick3->SetBrickCoord(brick3->GetPosX() - mainArea->GetCellSize(), brick3->GetPosY() + mainArea->GetCellSize());
			brick4->SetBrickCoord(brick4->GetPosX(), brick4->GetPosY() + mainArea->GetCellSize() * 2);
			break;
		case 1://T
			brick1->SetBrickCoord(brick1->GetPosX() + mainArea->GetCellSize(), brick1->GetPosY() + mainArea->GetCellSize());
			brick2->SetBrickCoord(brick2->GetPosX(), brick2->GetPosY());
			brick3->SetBrickCoord(brick3->GetPosX() - mainArea->GetCellSize() , brick3->GetPosY() - mainArea->GetCellSize());
			brick4->SetBrickCoord(brick4->GetPosX() - mainArea->GetCellSize() * 2, brick4->GetPosY() );
			break;
		case 2:
			brick1->SetBrickCoord(brick1->GetPosX() - mainArea->GetCellSize(), brick1->GetPosY() + mainArea->GetCellSize());
			brick2->SetBrickCoord(brick2->GetPosX(), brick2->GetPosY() );
			brick3->SetBrickCoord(brick3->GetPosX() + mainArea->GetCellSize(), brick3->GetPosY() - mainArea->GetCellSize() );
			brick4->SetBrickCoord(brick4->GetPosX() , brick4->GetPosY() - mainArea->GetCellSize() * 2);
			break;
		case 3:
			brick1->SetBrickCoord(brick1->GetPosX() - mainArea->GetCellSize(), brick1->GetPosY() - mainArea->GetCellSize());
			brick2->SetBrickCoord(brick2->GetPosX(), brick2->GetPosY());
			brick3->SetBrickCoord(brick3->GetPosX() + mainArea->GetCellSize(), brick3->GetPosY() + mainArea->GetCellSize());
			brick4->SetBrickCoord(brick4->GetPosX() + mainArea->GetCellSize() * 2, brick4->GetPosY());
			turnCount = -1;
			break;
		}
	}
}
