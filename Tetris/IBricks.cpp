#include "IBricks.h"
 
#include <iostream>

 
IBricks::IBricks( SDL_Renderer* renderer, MainArea* area, int posX, int posY) : ShapeBricks{  renderer, area, posX , posY , posX, posY + area->GetCellSize() , posX, posY + area->GetCellSize() * 2, posX, posY + area->GetCellSize() * 3  ,SDL_Color(191, 64, 191, 255) }
{
}
IBricks::IBricks(const IBricks& other) :ShapeBricks{ other } {
 
}
void IBricks::SetPosCoord(int x, int y)
{
	SetShapeBrickPos(x, y, x, y + mainArea->GetCellSize(), x, y + mainArea->GetCellSize() * 2, x, y + mainArea->GetCellSize() * 3);
}
void IBricks::RotateBricks() {
	if (!isCollidingDown) {
		if ((mainArea->GetCellCount().first - ((brick1->GetPosX() - mainArea->GetStartPos().first) / mainArea->GetCellSize()) > 2) &&
			(mainArea->GetCellCount().second - ((brick1->GetPosY() - mainArea->GetStartPos().second) / mainArea->GetCellSize()) > 2)){
			turnCount++;
			AllBrickResetVector();
			switch (turnCount) {
			case 0: // |-
				brick1->SetBrickCoord(brick1->GetPosX() + mainArea->GetCellSize(), brick1->GetPosY() - mainArea->GetCellSize());
				brick2->SetBrickCoord(brick2->GetPosX(), brick2->GetPosY());
				brick3->SetBrickCoord(brick3->GetPosX() - mainArea->GetCellSize(), brick3->GetPosY() + mainArea->GetCellSize());
				brick4->SetBrickCoord(brick4->GetPosX() - mainArea->GetCellSize() * 2, brick4->GetPosY() + mainArea->GetCellSize() * 2);
				break;
			case 1://T
				brick1->SetBrickCoord(brick1->GetPosX() - mainArea->GetCellSize(), brick1->GetPosY() + mainArea->GetCellSize());
				brick2->SetBrickCoord(brick2->GetPosX(), brick2->GetPosY());
				brick3->SetBrickCoord(brick3->GetPosX() + mainArea->GetCellSize(), brick3->GetPosY() - mainArea->GetCellSize());
				brick4->SetBrickCoord(brick4->GetPosX() + mainArea->GetCellSize() * 2, brick4->GetPosY() - mainArea->GetCellSize() * 2);
				turnCount = -1;
				break;

			}
		}
	}
}