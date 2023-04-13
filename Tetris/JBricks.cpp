#include "JBricks.h"
#include <iostream>
#include <string>

 
JBricks::JBricks(SDL_Renderer* renderer, MainArea* area, int posX, int posY) :ShapeBricks{ renderer, area, posX + area->GetCellSize() , posY , posX + area->GetCellSize() , posY + area->GetCellSize() , posX + area->GetCellSize() , posY + area->GetCellSize() * 2, posX, posY + area->GetCellSize() * 2  , SDL_Color(255, 153, 51, 255) }
{
}
JBricks::JBricks(const JBricks& other) :ShapeBricks{ other } {

}
void JBricks::SetPosCoord(int x, int y)
{
	SetShapeBrickPos(x + mainArea->GetCellSize(), y, x + mainArea->GetCellSize(), y + mainArea->GetCellSize(), x + mainArea->GetCellSize(), y + mainArea->GetCellSize() * 2, x, y + mainArea->GetCellSize() * 2);
}
void JBricks::RotateBricks() {
	if (!isCollidingDown) {
		turnCount++;
		AllBrickResetVector();
		switch (turnCount) {
		case 0: // |-
			brick1->SetBrickCoord(brick1->GetPosX() + mainArea->GetCellSize(), brick1->GetPosY() - mainArea->GetCellSize());
			brick2->SetBrickCoord(brick2->GetPosX() , brick2->GetPosY());
			brick3->SetBrickCoord(brick3->GetPosX() - mainArea->GetCellSize(), brick3->GetPosY() + mainArea->GetCellSize());
			brick4->SetBrickCoord(brick4->GetPosX() - mainArea->GetCellSize() * 2, brick4->GetPosY());
			break;
		case 1://T
			brick1->SetBrickCoord(brick1->GetPosX() + mainArea->GetCellSize(), brick1->GetPosY() + mainArea->GetCellSize());
			brick2->SetBrickCoord(brick2->GetPosX(), brick2->GetPosY());
			brick3->SetBrickCoord(brick3->GetPosX() - mainArea->GetCellSize(), brick3->GetPosY() - mainArea->GetCellSize());
			brick4->SetBrickCoord(brick4->GetPosX(), brick4->GetPosY() - mainArea->GetCellSize() * 2);
			break;
		case 2:
			brick1->SetBrickCoord(brick1->GetPosX() - mainArea->GetCellSize(), brick1->GetPosY() + mainArea->GetCellSize());
			brick2->SetBrickCoord(brick2->GetPosX() , brick2->GetPosY());
			brick3->SetBrickCoord(brick3->GetPosX() + mainArea->GetCellSize(), brick3->GetPosY() - mainArea->GetCellSize());
			brick4->SetBrickCoord(brick4->GetPosX() + mainArea->GetCellSize() * 2, brick4->GetPosY() );
			break;
		case 3:
			brick1->SetBrickCoord(brick1->GetPosX() - mainArea->GetCellSize(), brick1->GetPosY() - mainArea->GetCellSize());
			brick2->SetBrickCoord(brick2->GetPosX() , brick2->GetPosY());
			brick3->SetBrickCoord(brick3->GetPosX() + mainArea->GetCellSize(), brick3->GetPosY() + mainArea->GetCellSize());
			brick4->SetBrickCoord(brick4->GetPosX(), brick4->GetPosY() + mainArea->GetCellSize() * 2);
			turnCount = -1;
			break;
		}
	}
}
