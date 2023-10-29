#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include "RenderWindow.h"

RenderWindow::RenderWindow(const char* p_title, int p_w, int p_h)
    :window(NULL), renderer(NULL)
{
    window = SDL_CreateWindow(p_title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, p_w, p_h, SDL_WINDOW_SHOWN);

    if(window == NULL)
    {
        std::cout << "Window failed to init. Error: " << SDL_GetError() << std::endl;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    
    if(renderer == NULL)
        std::cout << "Renderer could not be created! SDL Error:" << SDL_GetError() << std::endl;

}

SDL_Texture* RenderWindow::loadTexture(const char* p_filePath)
{
    SDL_Texture* texture = NULL;
    texture = IMG_LoadTexture(renderer, p_filePath);

    if (texture == NULL)
        std::cout << "Failed to load texture. Error: " << SDL_GetError() << std::endl;

    return texture;
}

void RenderWindow::drawObject(Me* obj)
{
    SDL_Rect rect;
    rect.x = obj->getPosn().x;
    rect.y = obj->getPosn().y;
    rect.w = obj->getWidth() ;
    rect.h = obj->getHeight();

    SDL_SetRenderDrawColor(renderer, 0, 255, 255, 255);
    SDL_RenderDrawRect(renderer, &rect);
    SDL_RenderFillRect(renderer, &rect);

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    
    //InnerRing
    SDL_Rect rect2;
    rect2.x = obj->getPosn().x+6;
    rect2.y = obj->getPosn().y+6;
    rect2.w = obj->getWidth()-12 ;
    rect2.h = obj->getHeight()-12;

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderDrawRect(renderer, &rect2);
    SDL_RenderFillRect(renderer, &rect2);

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    
    
}

void RenderWindow::drawEnemyObject(std::vector<Object*> enemyList)
{
    for(auto it: enemyList)
    {
        SDL_Rect rect;
        rect.x = it->getPosn().x;
        rect.y = it->getPosn().y;
        rect.w = it->getLen();
        rect.h = it->getLen();

        SDL_SetRenderDrawColor(renderer, 238, 75, 43, 255);
        SDL_RenderDrawRect(renderer, &rect);
        SDL_RenderFillRect(renderer, &rect);

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    }
}

void RenderWindow::drawFrendObject(std::vector<Object*> frendList)
{
    for(auto it: frendList)
    {
        SDL_Rect rect;
        rect.x = it->getPosn().x;
        rect.y = it->getPosn().y;
        rect.w = it->getLen();
        rect.h = it->getLen();

        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderDrawRect(renderer, &rect);
        SDL_RenderFillRect(renderer, &rect);

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    }
}

void RenderWindow::drawLine(Me* o1, Object* o2)
{
    SDL_SetRenderDrawColor(renderer, 0, 255, 255, 255);
    SDL_RenderDrawLine(renderer, o1->getPosn().x, o1->getPosn().y, o2->getPosn().x, o2->getPosn().y);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
//    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
}


void RenderWindow::main_menu(LTexture* TextTexture1, LTexture* TextTexture2, LTexture* TextTexture3)
{
    SDL_Color textColor1 = {210, 105, 30, 255};
	SDL_Color textColor2 = {0, 255, 0, 255};
	SDL_Color textColor3 = {178, 34, 34, 255};

    TTF_Font* Font1 = TTF_OpenFont("game.ttf", 52);
    TTF_Font* Font2 = TTF_OpenFont("game.ttf", 38);

    TextTexture1->loadFromRenderedText("| TARZAN SWING |", textColor1, renderer, Font1);
    TextTexture2->loadFromRenderedText("PLAY", textColor2, renderer, Font2);
    TextTexture3->loadFromRenderedText("EXIT", textColor3, renderer, Font2);

    TTF_CloseFont(Font1); Font1 = NULL;
    TTF_CloseFont(Font2); Font2 = NULL;
}

void RenderWindow::score_menu(int TotalScore, LTexture* TextTexture1, LTexture* TextTexture2)
{
    SDL_Color textColor = {255, 255, 0, 255};
    TTF_Font* Font = TTF_OpenFont("game.ttf", 26);
    std::string str1 = std::to_string(TotalScore);
    std::string str2 = std::to_string(TotalScore/100);
    TextTexture1->loadFromRenderedText("Score : "+str1, textColor, renderer, Font);
    TextTexture2->loadFromRenderedText("Kills : "+str2, textColor, renderer, Font);
    TTF_CloseFont(Font); Font = NULL;
}


void RenderWindow::end_menu(int TotalScore, set<int> ScoreSet, LTexture* TextTexture, LTexture* TextTexture1, LTexture* TextTexture2, LTexture* TextTexture3, LTexture* TextTexture4, LTexture* TextTexture5, LTexture* TextTexture6, LTexture* TextTexture61, LTexture* TextTexture62, LTexture* TextTexture63)
{
    SDL_Color textColor = {189, 183, 107, 255};
	SDL_Color textColor1 = {255, 102, 0, 255};
	SDL_Color textColor2 = {153, 204, 0, 255};
	SDL_Color textColor3 = {155, 255, 204, 255};
    SDL_Color textColor4 = {178, 34, 34, 255};

    TTF_Font* Font = TTF_OpenFont("game_2.ttf", 40);
    TTF_Font* Font1 = TTF_OpenFont("game.ttf", 52);
    TTF_Font* Font2 = TTF_OpenFont("game.ttf", 24);
    TTF_Font* Font3 = TTF_OpenFont("game.ttf", 36);

    vector<string> ScoreString;
    
    std::string str1 = std::to_string(TotalScore/100);
    std::string str2 = std::to_string(TotalScore);
//    std::string str3 = std::to_string(*ScoreVector.end());
//    std::string str4 = std::to_string(ScoreVector[1]);
//    std::string str5 = std::to_string(ScoreVector[2]);
    
    set<int>::reverse_iterator rit;
    
    for (rit = ScoreSet.rbegin(); rit != ScoreSet.rend(); rit++)
    {
        ScoreString.push_back(to_string(*rit) );
    }
    
    

    TextTexture1->loadFromRenderedText("lmao ded", textColor1, renderer, Font1);
    TextTexture->loadFromRenderedText("f", textColor, renderer, Font);
    TextTexture2->loadFromRenderedText("Kills : "+str1, textColor2, renderer, Font2);
    TextTexture3->loadFromRenderedText("Score : "+str2, textColor2, renderer, Font2);
    TextTexture6->loadFromRenderedText("LeaderBoard:", textColor2, renderer, Font2);
    TextTexture61->loadFromRenderedText("1. " + ScoreString[0], textColor1, renderer, Font2);
    TextTexture62->loadFromRenderedText("2. " + ScoreString[1], textColor1, renderer, Font2);
    TextTexture63->loadFromRenderedText("3. " + ScoreString[2], textColor1, renderer, Font2);
    
    TextTexture4->loadFromRenderedText("RETRY", textColor3, renderer, Font3);
    TextTexture5->loadFromRenderedText("EXIT", textColor4, renderer, Font3);
    
    TTF_CloseFont(Font); Font = NULL;
    TTF_CloseFont(Font1); Font1 = NULL;
    TTF_CloseFont(Font2); Font2 = NULL;
    TTF_CloseFont(Font3); Font3 = NULL;  
}

void RenderWindow::drawLava(Lava* lava)
{
    for(int i=0;i<40;i++)
    {
        SDL_Rect rect;
        rect.x = lava->getPosnX();
        rect.y = lava->getPosnY() + i*5;
        rect.w = lava->getWidth();
        rect.h = lava->getLength();
        

        SDL_SetRenderDrawColor(renderer, 150-3*i, 35, 35, 255);
        SDL_RenderDrawRect(renderer, &rect);
        SDL_RenderFillRect(renderer, &rect);

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    }
    
//    for(int i=0;i<50;i++)
//    {
//        SDL_Rect rect;
//        rect.x = lava->getPosnX();
//        rect.y = lava->getPosnY() + 70 + i*5;
//        rect.w = lava->getWidth();
//        rect.h = lava->getLength();
//
//
//        SDL_SetRenderDrawColor(renderer, 170-2*i, 35, 35, 255);
//        SDL_RenderDrawRect(renderer, &rect);
//        SDL_RenderFillRect(renderer, &rect);
//
//        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
//    }
   
}

void RenderWindow::cleanUp()
{
    SDL_DestroyWindow(window);
}

void RenderWindow::clear()
{
    SDL_RenderClear(renderer);
}

void RenderWindow::render(SDL_Texture* p_tex)
{
    SDL_RenderCopy(renderer, p_tex, NULL, NULL);
}

void RenderWindow::display()
{
    SDL_RenderPresent(renderer);
}

SDL_Window* RenderWindow::get_renderer_window()
{
    return window;
}

SDL_Renderer* RenderWindow::get_SDL_renderer()
{
    return renderer;
}
