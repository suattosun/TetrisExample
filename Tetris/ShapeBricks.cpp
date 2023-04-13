#include "ShapeBricks.h"
#include <random>
#include <iostream>

ShapeBricks::ShapeBricks(SDL_Renderer* renderer, MainArea* area, int brickX1, int brickY1, int brickX2, int brickY2, int brickX3, int brickY3, int brickX4, int brickY4,SDL_Color color) :isCollidingDown{ false }, mRenderer { renderer }, mainArea{ area }, mName{ NameCreater() }, brick1{ new Brick(mRenderer,mainArea,mName,color,brickX1, brickY1 , brickSize, brickSize) }, brick2{ new Brick(mRenderer,mainArea, mName, color, brickX2, brickY2  , brickSize, brickSize) },
brick3{ new Brick(mRenderer,mainArea,mName,color,brickX3,brickY3, brickSize, brickSize) }, brick4{ new Brick(mRenderer,mainArea,mName,color,brickX4,brickY4 ,brickSize, brickSize) }
{
	std::cout << "ctor\n";
}
std::string ShapeBricks::NameCreater() {
	std::mt19937 eng{ std::random_device()() };
	return  std::to_string(eng());
}
 
auto timer1 = std::chrono::steady_clock::now();
void ShapeBricks::MoveAutoBricks()
{

	if (!isCollidingDown) {

		auto timer2 = std::chrono::steady_clock::now();
		if (mainArea->IsMoveDown(brick1->GetPosX(), brick1->GetPosY()) &&
			mainArea->IsMoveDown(brick2->GetPosX(), brick2->GetPosY()) &&
			mainArea->IsMoveDown(brick3->GetPosX(), brick3->GetPosY()) &&
			mainArea->IsMoveDown(brick4->GetPosX(), brick4->GetPosY())) {
			if (timer2 - timer1 > std::chrono::seconds(1) || quiclyBrickDown) {
				AllBrickResetVector();
				brick1->BrickAutoMove();
				brick2->BrickAutoMove();
				brick3->BrickAutoMove();
				brick4->BrickAutoMove();
				timer1 = std::chrono::steady_clock::now();
			//	mainArea->showConsoleArea();

			}
		}
		else
		{
			CollidingDedect();
			isCollidingDown = true;

		}
	}
}
void ShapeBricks::GetBrickSharedCount() {
	//std::cout << brick1.use_count() << " " << brick2.use_count() << " " << brick3.use_count() << " " << brick4.use_count() <<  "\n";
}
bool ShapeBricks::DestroyControl() {
	if ((brick1.use_count() <= 1) && (brick2.use_count() <= 1) && (brick3.use_count() <= 1) && (brick4.use_count() <= 1))
		return true;
	return false;
}
 
void ShapeBricks::CollidingDedect() {
	SDL_Event event;
	event.type = SDL_USEREVENT;
	event.user.code = 1;
	event.user.data1 = nullptr;
	event.user.data2 = nullptr;
	SDL_PushEvent(&event);
}
std::string ShapeBricks::GetName()
{
	return mName;
}



void ShapeBricks::SetShapeBrickPos(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4)
{
	brick1->SetBrickCoord(x1, y1);
	brick2->SetBrickCoord(x2, y2);
	brick3->SetBrickCoord(x3, y3);
	brick4->SetBrickCoord(x4, y4);
}
 
std::shared_ptr<Brick> ShapeBricks::getBrick(int i)
{
	switch (i) {
		case 1:
			return brick1;
		case 2:
			return brick2;
		case 3:
			return brick3;
		case 4:
			return brick4;
			 
	}
}
void ShapeBricks::destroy()
{
	delete this;
}
void ShapeBricks::MoveManuelBricks(const Uint8* keyState)
{
	if (!isCollidingDown) {
		MoveManuelLeft(keyState[SDL_SCANCODE_LEFT]);
		MoveManuelRight(keyState[SDL_SCANCODE_RIGHT]);
	//	MoveManuelUp(keyState[SDL_SCANCODE_UP]);
		MoveManuelDown(keyState[SDL_SCANCODE_DOWN]);
		MoveManuelSpace(keyState[SDL_SCANCODE_SPACE]);
		MoveManuelRotate(keyState[SDL_SCANCODE_Z]);
		BricksUpdate();
		//mainArea->showConsoleArea();
	}

}
void ShapeBricks::MoveManuelLeft(const Uint8 state)
{

	if (state) {
		if (mainArea->IsMoveLeft(brick1->GetPosX(), brick1->GetPosY()) && mainArea->IsMoveLeft(brick2->GetPosX(), brick2->GetPosY()) && mainArea->IsMoveLeft(brick3->GetPosX(), brick3->GetPosY()) &&
			mainArea->IsMoveLeft(brick4->GetPosX(), brick4->GetPosY())) {
			AllBrickResetVector();
			brick1->BrickManuelMoveLeft();
			brick2->BrickManuelMoveLeft();
			brick3->BrickManuelMoveLeft();
			brick4->BrickManuelMoveLeft();
		}
	}
}
void ShapeBricks::MoveManuelRight(const Uint8 state)
{

	if (state) {
		if (mainArea->IsMoveRight(brick1->GetPosX(), brick1->GetPosY()) && mainArea->IsMoveRight(brick2->GetPosX(), brick2->GetPosY()) && mainArea->IsMoveRight(brick3->GetPosX(), brick3->GetPosY()) &&
			mainArea->IsMoveRight(brick4->GetPosX(), brick4->GetPosY())) {
			AllBrickResetVector();
			brick1->BrickManuelMoveRight();
			brick2->BrickManuelMoveRight();
			brick3->BrickManuelMoveRight();
			brick4->BrickManuelMoveRight();
		}
	}
}
void ShapeBricks::MoveManuelDown(const Uint8 state)
{

	if (state) {
		if (mainArea->IsMoveDown(brick1->GetPosX(), brick1->GetPosY()) && mainArea->IsMoveDown(brick2->GetPosX(), brick2->GetPosY()) && mainArea->IsMoveDown(brick3->GetPosX(), brick3->GetPosY()) &&
			mainArea->IsMoveDown(brick4->GetPosX(), brick4->GetPosY())) {
			AllBrickResetVector();
			brick1->BrickManuelMoveDown();
			brick2->BrickManuelMoveDown();
			brick3->BrickManuelMoveDown();
			brick4->BrickManuelMoveDown();
		}
	}
}

void ShapeBricks::MoveManuelSpace(const Uint8 state) {
	static bool isDownButtonPress = false;
	static bool isDownButtonPressPre = true;
	if (state) {
		if (mainArea->IsMoveDown(brick1->GetPosX(), brick1->GetPosY()) && mainArea->IsMoveDown(brick2->GetPosX(), brick2->GetPosY()) && mainArea->IsMoveDown(brick3->GetPosX(), brick3->GetPosY()) &&
			mainArea->IsMoveDown(brick4->GetPosX(), brick4->GetPosY())) {
			isDownButtonPress = true;
		}
		else
		{
			CollidingDedect();
			isCollidingDown = true;
		}
	}
	else
	{
		isDownButtonPress = false;
	}
	if (isDownButtonPress && !isDownButtonPressPre) {
		quiclyBrickDown = true;
	}
	isDownButtonPressPre = isDownButtonPress;
}
void ShapeBricks::MoveManuelUp(const Uint8 state) 
{
	if (state) {
		if (mainArea->IsMoveUp(brick1->GetPosX(), brick1->GetPosY()) && mainArea->IsMoveUp(brick2->GetPosX(), brick2->GetPosY()) && mainArea->IsMoveUp(brick3->GetPosX(), brick3->GetPosY()) &&
			mainArea->IsMoveUp(brick4->GetPosX(), brick4->GetPosY())) {
			AllBrickResetVector();
			brick1->BrickManuelMoveUp();
			brick2->BrickManuelMoveUp();
			brick3->BrickManuelMoveUp();
			brick4->BrickManuelMoveUp();
		}
	}
}
void ShapeBricks::MoveManuelRotate(const Uint8 state)
{
	static bool zPressed = false;

	if (state && !zPressed) {
		if (mainArea->IsMoveUp(brick1->GetPosX(), brick1->GetPosY()) && mainArea->IsMoveUp(brick2->GetPosX(), brick2->GetPosY()) && mainArea->IsMoveUp(brick3->GetPosX(), brick3->GetPosY()) &&
			mainArea->IsMoveUp(brick4->GetPosX(), brick4->GetPosY()) && mainArea->IsMoveDown(brick1->GetPosX(), brick1->GetPosY()) && mainArea->IsMoveDown(brick2->GetPosX(), brick2->GetPosY()) &&
			mainArea->IsMoveDown(brick3->GetPosX(), brick3->GetPosY()) && mainArea->IsMoveDown(brick4->GetPosX(), brick4->GetPosY()) && mainArea->IsMoveRight(brick1->GetPosX(), brick1->GetPosY()) &&
			mainArea->IsMoveRight(brick2->GetPosX(), brick2->GetPosY()) && mainArea->IsMoveRight(brick3->GetPosX(), brick3->GetPosY()) && mainArea->IsMoveRight(brick4->GetPosX(), brick4->GetPosY()) &&
			mainArea->IsMoveLeft(brick1->GetPosX(), brick1->GetPosY()) && mainArea->IsMoveLeft(brick2->GetPosX(), brick2->GetPosY()) && mainArea->IsMoveLeft(brick3->GetPosX(), brick3->GetPosY()) &&
			mainArea->IsMoveLeft(brick4->GetPosX(), brick4->GetPosY())) {
			RotateBricks();
			zPressed = true;
		}
	}
	else if (!state) {
		zPressed = false;
	}

}

void ShapeBricks::AllBrickResetVector() 
{
	brick1->ResetVectorData(brick1->GetPosX(), brick1->GetPosY());
	brick2->ResetVectorData(brick2->GetPosX(), brick2->GetPosY());
	brick3->ResetVectorData(brick3->GetPosX(), brick3->GetPosY());
	brick4->ResetVectorData(brick4->GetPosX(), brick4->GetPosY());
}
void ShapeBricks::BricksUpdate()
{
	if(brick1.use_count() > 1)
		brick1->BrickUpdate();
	if(brick2.use_count() > 1)
		brick2->BrickUpdate();
	if(brick3.use_count() > 1)
		brick3->BrickUpdate();
	if(brick4.use_count() > 1)
		brick4->BrickUpdate();
}
ShapeBricks::~ShapeBricks() {
	std::cout << "delete\n";
}