#include "brick.h"
#include <iostream>
 
Brick::Brick(SDL_Renderer* renderer, MainArea* area, std::string name, SDL_Color color, int x, int y, int w, int h) :cell{ 0 }, brickrenderer{ renderer }, myArea{ area }, mName{ name }, brickX{ x }, brickY{ y }, brickH{ h }, brickW{ w }, brickRect{ SDL_Rect{ brickX,brickY,brickH,brickW } },mColor{ color }{
}

Brick::~Brick()
{
}
 

void Brick::BrickAutoMove()
{ 

	brickY += myArea->GetCellSize();
	cell = ((brickX - myArea->GetStartPos().first) / myArea->GetCellSize()) + ((brickY - myArea->GetStartPos().second) / myArea->GetCellSize()) * (myArea->GetCellCount().first);
	myArea->NewLocationAssign(cell, mName);
}

void Brick::BrickUpdate()
{
	SDL_Rect rect;
	rect.x = brickX;
	rect.y = brickY;
	rect.w = brickW;
	rect.h = brickH;
	SDL_SetRenderDrawColor( brickrenderer, mColor.r, mColor.g, mColor.b, mColor.a);
	SDL_RenderFillRect(brickrenderer, &rect);

}
void Brick::BrickDestroyEffect() {
	SDL_Rect rect;
	rect.x = brickX;
	rect.y = brickY;
	rect.w = brickW;
	rect.h = brickH;
	for (int i = 255; i >= 0; i--) {
		SDL_SetRenderDrawColor(brickrenderer, mColor.r, mColor.g, mColor.b, i);
		SDL_RenderFillRect(brickrenderer, &rect);
		SDL_Delay(1); 
	}
}
void Brick::BrickManuelMoveRight()
{
		brickX += myArea->GetCellSize();
		cell = ((brickX - myArea->GetStartPos().first) / myArea->GetCellSize()) + ((brickY - myArea->GetStartPos().second) / myArea->GetCellSize()) * (myArea->GetCellCount().first);
		myArea->NewLocationAssign(cell, mName);
}
void Brick::BrickManuelMoveLeft()
{
		brickX -= myArea->GetCellSize();
		cell = ((brickX - myArea->GetStartPos().first) / myArea->GetCellSize()) + ((brickY - myArea->GetStartPos().second) / myArea->GetCellSize()) * (myArea->GetCellCount().first);
		myArea->NewLocationAssign(cell, mName);
}
void Brick::BrickManuelMoveUp()
{
		brickY -= myArea->GetCellSize();
		cell = ((brickX - myArea->GetStartPos().first) / myArea->GetCellSize()) + ((brickY - myArea->GetStartPos().second) / myArea->GetCellSize()) * (myArea->GetCellCount().first);
		myArea->NewLocationAssign(cell, mName);
}
void Brick::BrickManuelMoveDown()
{
		brickY += myArea->GetCellSize();
		cell = ((brickX - myArea->GetStartPos().first) / myArea->GetCellSize()) + ((brickY - myArea->GetStartPos().second) / myArea->GetCellSize()) * (myArea->GetCellCount().first);
		myArea->NewLocationAssign(cell,mName);	 
 }

void Brick::ResetVectorData(int x, int y) {
	const auto preCell = ((x - myArea->GetStartPos().first) / myArea->GetCellSize()) + ((y - myArea->GetStartPos().second) / myArea->GetCellSize()) * (myArea->GetCellCount().first);
	myArea->ResetData(preCell);
}

void Brick::SetBrickCoord(int x, int y) {
	brickX = x;
	brickY = y;
	const auto preCell = ((x - myArea->GetStartPos().first) / myArea->GetCellSize()) + ((y - myArea->GetStartPos().second) / myArea->GetCellSize()) * (myArea->GetCellCount().first);
	myArea->NewLocationAssign(preCell, mName);
}

int Brick::GetPosX()
{
	return brickX;
}

int Brick::GetPosY()
{
	return brickY;
}

std::string Brick::GetName()
{
	return mName;
}

int Brick::GetCellNo() {
	return cell;
}
auto Brick::operator<=>(const Brick* p1)const{
	return cell <=> p1->cell;
}
bool Brick::operator==(int s)const {
	return cell == s;
}

bool Brick::operator!=(int s)const {
	return cell == s;
}
 