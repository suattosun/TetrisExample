#include "SBricks.h"
#include <iostream>
#include <string>


SBricks::SBricks(SDL_Renderer* renderer, MainArea* area, int posX, int posY) :ShapeBricks{ renderer, area, posX , posY + area->GetCellSize(), posX + area->GetCellSize(), posY + area->GetCellSize(), posX + area->GetCellSize(), posY , posX + area->GetCellSize() * 2, posY  ,SDL_Color(0, 204, 0, 255) }
{
}
SBricks::SBricks(const SBricks& other) :ShapeBricks{ other } {

}
void SBricks::SetPosCoord(int x, int y)
{
	SetShapeBrickPos(x, y + mainArea->GetCellSize(), x + mainArea->GetCellSize(), y + mainArea->GetCellSize(), x + mainArea->GetCellSize(), y, x + mainArea->GetCellSize() * 2, y);
}
void SBricks::RotateBricks() {
	if (!isCollidingDown) {
		turnCount++;
		AllBrickResetVector();
		switch (turnCount) {
		case 0: // |-
			brick1->SetBrickCoord(brick1->GetPosX() - mainArea->GetCellSize(), brick1->GetPosY() - mainArea->GetCellSize());
			brick2->SetBrickCoord(brick2->GetPosX() , brick2->GetPosY() );
			brick3->SetBrickCoord(brick3->GetPosX() + mainArea->GetCellSize(), brick3->GetPosY() - mainArea->GetCellSize());
			brick4->SetBrickCoord(brick4->GetPosX() + mainArea->GetCellSize() * 2, brick4->GetPosY());
			break;
		case 1://T
			brick1->SetBrickCoord(brick1->GetPosX() + mainArea->GetCellSize(), brick1->GetPosY() - mainArea->GetCellSize());
			brick2->SetBrickCoord(brick2->GetPosX() , brick2->GetPosY());
			brick3->SetBrickCoord(brick3->GetPosX() + mainArea->GetCellSize(), brick3->GetPosY() + mainArea->GetCellSize());
			brick4->SetBrickCoord(brick4->GetPosX() , brick4->GetPosY() + mainArea->GetCellSize() * 2);
			break;
		case 2:
			brick1->SetBrickCoord(brick1->GetPosX() + mainArea->GetCellSize(), brick1->GetPosY() + mainArea->GetCellSize());
			brick2->SetBrickCoord(brick2->GetPosX() , brick2->GetPosY());
			brick3->SetBrickCoord(brick3->GetPosX() - mainArea->GetCellSize(), brick3->GetPosY() + mainArea->GetCellSize());
			brick4->SetBrickCoord(brick4->GetPosX() - mainArea->GetCellSize() * 2, brick4->GetPosY() );
			break;
		case 3:
			brick1->SetBrickCoord(brick1->GetPosX() - mainArea->GetCellSize(), brick1->GetPosY() + mainArea->GetCellSize());
			brick2->SetBrickCoord(brick2->GetPosX() , brick2->GetPosY());
			brick3->SetBrickCoord(brick3->GetPosX() - mainArea->GetCellSize(), brick3->GetPosY() - mainArea->GetCellSize());
			brick4->SetBrickCoord(brick4->GetPosX() , brick4->GetPosY() - mainArea->GetCellSize() * 2);
			turnCount = -1;
			break;
		}
	}
}
