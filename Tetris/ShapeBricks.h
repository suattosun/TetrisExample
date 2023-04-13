#pragma once
#include <SDL_syswm.h>
#include"Brick.h"
#include <chrono>
class ShapeBricks
{
public:
	ShapeBricks(SDL_Renderer* renderer, MainArea* area, int brickX1, int brickY1, int brickX2, int brickY2, int brickX3, int brickY3, int brickX4, int brickY4, SDL_Color color);
	virtual ~ShapeBricks();
	virtual void RotateBricks() = 0;
	virtual void MoveManuelBricks(const Uint8* keyState);
	virtual void MoveManuelLeft(const Uint8 state);
	virtual void MoveManuelRight(const Uint8 state);
	virtual void MoveManuelDown(const Uint8 state);
	virtual void MoveManuelUp(const Uint8 state);
	virtual void MoveManuelSpace(const Uint8 state);
	virtual void MoveManuelRotate(const Uint8 state);
	virtual void MoveAutoBricks();
	virtual void BricksUpdate();
	void CollidingDedect();
	std::string NameCreater();
	std::string GetName();
	bool DestroyControl();
	void AllBrickResetVector();
	std::shared_ptr<Brick>  getBrick(int i);
	void destroy();
	void GetBrickSharedCount();
	virtual void SetPosCoord(int x, int y) = 0;
protected:
	void SetShapeBrickPos(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4);

	SDL_Renderer* mRenderer;
	MainArea* mainArea;
	bool isCollidingDown;
	std::string mName;
	int brickSize = 30;
	std::shared_ptr<Brick> brick1;
	std::shared_ptr<Brick> brick2;
	std::shared_ptr<Brick> brick3;
	std::shared_ptr<Brick> brick4;
	bool quiclyBrickDown = false;
private:
	 
};

