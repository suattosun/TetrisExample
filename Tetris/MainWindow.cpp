#include "MainWindow.h"
#include <iostream>
 
 
 
MainWindow::MainWindow() : MyArea{ new MainArea } {
	SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
	window = SDL_CreateWindow("My SDL Window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1080, 720, SDL_WINDOW_SHOWN);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    TTF_Init();
    font = TTF_OpenFont("Arial.ttf", 28);
    //surface = SDL_GetWindowSurface(window);
    if(Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,2,2048)<0)
        std::cout<<"error : "<<Mix_GetError()<<"\n";
    bgMusic = Mix_LoadMUS("bgm.mp3");
    sounfEffect = Mix_LoadWAV("sfx.wav");
    gameOverEffect = Mix_LoadWAV("gameover.wav");
    brickSfx = Mix_LoadWAV("brickSfx.wav");
    Mix_PlayMusic(bgMusic, -1);
}
void MainWindow::setup() {
}

void MainWindow::DrawTextSDL(const char* text, int x, int y, SDL_Color color) {
 
    SDL_Surface* surface = TTF_RenderText_Solid(font, text, color);
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_Rect destRect = { x, y, surface->w, surface->h };
    SDL_RenderCopy(renderer, texture, nullptr, &destRect);
    SDL_FreeSurface(surface);
    SDL_DestroyTexture(texture);
 
}

void MainWindow::update() {
    const Uint8* keyState;
    AddVectorElement();
    ChangePosVector();
    AddBrickFromBrickVecTosetBrick();
    AddVectorElement();
    AddBrickFromBrickVecTosetBrick();

    while (!isRunning)
    {
        SDL_Event event;
        
     
        while (SDL_PollEvent(&event))
        {

            keyState = SDL_GetKeyboardState(NULL);
            if (event.type == SDL_USEREVENT && event.user.code == 1) {
                BrickMovementEnd();
                Mix_PlayChannel(-1, brickSfx, 0);
                if (IsGameOver()) {
                    break;
                }
                ChangePosVector();
                AddVectorElement();
                AddBrickFromBrickVecTosetBrick();
                MyArea->showConsoleArea();
            }
            switch (event.type)
            {
            case SDL_QUIT:
                isRunning = SDL_TRUE;
                break;

            }
            for (auto bricks = brickVec.begin(); bricks != (brickVec.end() - 1); ++bricks)
                (*bricks)->MoveManuelBricks(keyState);
        }
        for (auto bricks = brickVec.begin(); bricks != (brickVec.end() - 1); ++bricks){
            (*bricks)->MoveAutoBricks();

        }
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 100);
        SDL_RenderFillRect(renderer, nullptr);
        for (auto bricks = brickVec.begin();bricks != (brickVec.end() ) ; ++bricks)
            (*bricks)->BricksUpdate();
        RenderUpdate();
    }
}

void MainWindow::CreateNewBrick(bool status)
{
    isCreateNewBrick = status;
}
bool compare(std::shared_ptr<Brick> b1, std::shared_ptr<Brick>  b2) {
    return b1->GetCellNo() > b2->GetCellNo();
}
void MainWindow::BrickMovementEnd()
{
    int pointCount = 0;
    while (true) {
        auto [isPairComplete, howCellIsComplete] = MyArea->IsThePairComplete();
        if (isPairComplete) {
        
            auto removeStart = std::remove_if(setBrick.begin(), setBrick.end(),
                [=](std::shared_ptr<Brick> b) {
                    int cellNo = b->GetCellNo();
                    return cellNo >= howCellIsComplete  && cellNo < howCellIsComplete + 10 ;
                });
            int numRemoved = std::distance(removeStart, setBrick.end());
            setBrick.erase(removeStart, setBrick.end());
            if (!numRemoved)
                break;
            pointCount++;
            Mix_PlayChannel(-1, sounfEffect, 0);
            ResetMatrixBecomePair(howCellIsComplete);
        }
        else {
            break;
        }
    }
    sumPoint += CalculatePoint(pointCount);
    DestroyBlock();
    
}
bool MainWindow::IsGameOver()
{
    if (MyArea->IsGameEnd()) {
        Mix_PlayChannel(-1, gameOverEffect, 0);
        isRunning = SDL_TRUE;
        return true;
    }
    return false;
}
void MainWindow::ResetMatrixBecomePair(int _howCellIsComplete)
{
   // std::sort(setBrick.begin(), setBrick.end(), compare);
    std::partial_sort(setBrick.begin(), setBrick.end() - 4, setBrick.end(), compare);
    MyArea->vecDeleteRow(_howCellIsComplete);
    for (auto iter = setBrick.begin(); iter != setBrick.end() - 4; ++iter) {
        if ((*iter)->GetCellNo() < _howCellIsComplete) {
            (*iter)->ResetVectorData((*iter)->GetPosX(), (*iter)->GetPosY());
            (*iter)->BrickAutoMove();
        }
    }
}
void MainWindow::RenderUpdate()
{
    MyArea->makeArea(renderer, 50, 50, 0, 0, 0, 255);
    SDL_Color textColor = { 255, 255, 255, 255 };
    DrawTextSDL(std::to_string(sumPoint).c_str(), 360, 270, textColor);
    MyArea->makeScoreArea(renderer, 360, 270, 255, 255, 255, 255);
    MyArea->makeGrill(renderer, 50, 50, 255, 255, 255, 255);
    MyArea->makeNextPieceGrill(renderer, 360, 120, 255, 255, 255, 255);
    if (isRunning) {
        DrawTextSDL("GAME OVER", 100, 270, SDL_Color{ 255,255,0,255 });
        SDL_RenderPresent(renderer);
        SDL_RenderClear(renderer);
        SDL_Delay(10000);
    }
    SDL_RenderPresent(renderer);
    SDL_RenderClear(renderer);
}
int MainWindow::CalculatePoint(int count)
{
    switch (count)
    {
    case 1:
        return 100;
    case 2:
        return 400;
    case 3:
        return 900;
    case 4:
        return 2000;
    default:
        break;
    }
    return 0;
}
void ScoreText() {

}
void MainWindow::ChangePosVector()
{
    brickVec.back()->SetPosCoord(170, 50);
}
 
void MainWindow::AddVectorElement()
{
    brickVec.emplace_back(GenerateBricks());
}
void MainWindow::AddBrickFromBrickVecTosetBrick()
{
    setBrick.emplace_back(brickVec.back()->getBrick(1));
    setBrick.emplace_back(brickVec.back()->getBrick(2));
    setBrick.emplace_back(brickVec.back()->getBrick(3));
    setBrick.emplace_back(brickVec.back()->getBrick(4));
}
void MainWindow::DestroyBlock()
{
    for (auto iter = brickVec.begin(); iter != brickVec.end(); )
    {
        (*iter)->GetBrickSharedCount();
        if ((*iter)->DestroyControl()) {
            (*iter)->destroy();
            iter = brickVec.erase(iter);
        }
        else
            ++iter;
    }
}
 
ShapeBricks* MainWindow::GenerateBricks() {
    std::mt19937 eng(std::random_device{}());
    std::uniform_int_distribution dist(0, 6);

    switch (dist(eng))
    {
    case 0:
        return new IBricks(renderer, MyArea.get(),360,120);
    case 1:
        return new JBricks(renderer, MyArea.get(), 360, 120);
    case 2:
        return new LBricks(renderer, MyArea.get(), 360, 120);
    case 3:
        return new SBricks(renderer, MyArea.get(), 360, 120);
    case 4:
        return new SquareBricks(renderer, MyArea.get(), 360, 120);
    case 5:
        return new TBricks(renderer, MyArea.get(), 360, 120);
    case 6:
        return new ZBricks(renderer, MyArea.get(), 360, 120);
    default:
        break;
    }
    return nullptr;
}
 
MainWindow::~MainWindow() {
  //  SDL_FreeSurface(surface);
    for (auto block : brickVec)
        delete block;
    Mix_FreeChunk(sounfEffect);
    Mix_FreeChunk(gameOverEffect);
    Mix_FreeMusic(bgMusic);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    Mix_Quit();
    SDL_Quit();
}
