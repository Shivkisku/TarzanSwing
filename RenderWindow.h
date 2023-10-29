#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#include <vector>
#include <set>
#include "Object.hpp"
#include "Me.hpp"
#include "LTexture.hpp"
#include "Lava.hpp"

class RenderWindow
{
public:
    RenderWindow(const char* p_title, int p_w, int p_h);
    SDL_Texture* loadTexture(const char* p_filePath);
    void cleanUp();
    void clear();
    void render(SDL_Texture* p_tex);
    void display();
    void drawObject(Me* obj);
    void drawEnemyObject(std::vector<Object*> enemyList);
    void drawFrendObject(std::vector<Object*> frendList);
    void drawLine(Me* o1, Object* o2);
    void main_menu(LTexture* TextTexture1, LTexture* TextTexture2, LTexture* TextTexture3);
    void score_menu(int TotalScore, LTexture* TextTexture1, LTexture* TextTexture2);
    void end_menu(int TotalScore,  set<int> ScoreSet, LTexture* TextTexture, LTexture* TextTexture1, LTexture* TextTexture2, LTexture* TextTexture3, LTexture* TextTexture4, LTexture* TextTexture5, LTexture* TextTexture6, LTexture* TextTexture61, LTexture* TextTexture62, LTexture* TextTexture63);
    void drawLava(Lava* lava);
    SDL_Window* get_renderer_window();
    SDL_Renderer* get_SDL_renderer();
private:
    SDL_Window* window;
    SDL_Renderer* renderer;
};
