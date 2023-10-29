#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>

#include <iostream>
#include <vector>
#include <set>
#include <fstream>

#include "RenderWindow.h"
#include "Object.hpp"
#include "Me.hpp"
#include "Rope.hpp"
#include "EventManager.hpp"
#include "ObjectManager.hpp"
#include "Lava.hpp"

using namespace std;

#define WindowWidth 1280
#define WindowHeight 720


int main(int argc, char* args[])
{
    
    
//    ofstream outputFile("ScoreBoard.txt");
    set<int> ScoreSet;
    
    Mix_OpenAudio(MIX_DEFAULT_FREQUENCY,MIX_DEFAULT_FORMAT,2,4096);
    Mix_Music *music = NULL;
    Mix_Chunk *sound = NULL;
    Mix_Chunk *blast = NULL;
    
    music = Mix_LoadMUS("BGMgameOriginal.mp3");
    sound = Mix_LoadWAV("sound.wav");
    blast = Mix_LoadWAV("blast.mp3");
    Mix_PlayMusic(music,-1);
    
    if(SDL_Init(SDL_INIT_VIDEO) > 0)
        std::cout << "HEY.. SDL_Init HAS FAILED. SDL_ERROR: " << SDL_GetError() << std::endl;

    if(!(IMG_Init(IMG_INIT_PNG)))
        std::cout << "IMG_init has failed. Error: " << SDL_GetError() << std::endl;

    //Initialize SDL_ttf
    if(TTF_Init() == -1)
    std::cout << "SDL_ttf could not initialize! SDL_ttf Error: " << SDL_GetError() << std::endl;

    RenderWindow window("TARZAN SWING", WindowWidth, WindowHeight);
    SDL_Window* gWindow = window.get_renderer_window();
    SDL_Renderer* gRenderer = window.get_SDL_renderer();

    bool gameRunning = true;
    bool main_game = false;             // it will be true when we enteres into main game
    bool end_menu = false;
    int HighScore = 0;

    statement2:
    bool Roped = false;
    int Quadrant;
    int TotalScore = 0;

    LTexture gTextTexture;
    LTexture gTextTexture1;
    LTexture gTextTexture2;
    LTexture gTextTexture3;
    LTexture gTextTexture4;
    LTexture gTextTexture5;
    LTexture gTextTexture6;
    LTexture gTextTexture61;
    LTexture gTextTexture62;
    LTexture gTextTexture63;
    
    LTexture gTextTexture7;
    LTexture gTextTexture8;

    class Me* mainObject = NULL;
    std::vector<class Object*> enemyList;
    std::vector<class Object*> frendList;

    mainObject = new Me(600,400,20,0,0);
//    class Lava* lava = new Lava(0, 625, 500, 1280);

    class Rope* aRope = new Rope();
    class eventManager* anEvent = new eventManager();
    bool collided = false;
    int ScoredObjectIndex;

    SDL_Event event;

    if(main_game == false && end_menu == false){
        window.main_menu(&gTextTexture1, &gTextTexture2, &gTextTexture3);
    }
    
    class ObjectManager* om = new ObjectManager(WindowWidth, WindowHeight, mainObject);
    int spawnCounter=0;   

    statement:
    if(main_game == true && end_menu == false){
        for(int i=0;i<7;i++){
            om->Spawn(enemyList, frendList, spawnCounter*WindowWidth);
            spawnCounter++;
        }                   
    }
    class Lava* lava = new Lava(0, 700, 500, 1280);
    
    SDL_Texture* grassTexture = window.loadTexture("BLACK.jpg");

    
    
    while(gameRunning)
    {
        // Get our controls and events
        while(SDL_PollEvent(&event))
        {
            if(event.type == SDL_QUIT)
                gameRunning = false;
        
            if(event.type == SDL_MOUSEBUTTONDOWN)
            {
                if(main_game == false && end_menu == false)
                {
                    int x, y;
                    SDL_GetMouseState(&x, &y);
                    int k1 = gTextTexture3.getWidth();
                    int k2 = gTextTexture2.getWidth();
                    gameRunning = anEvent->Exit_MouseClick(x, y, 600, k1, WindowWidth);
                    main_game = anEvent->Play_MouseClick(x, y, k2, WindowWidth);
                    if(main_game == true) goto statement;
                }

                else if(main_game == true && end_menu == false)
                    Roped = anEvent->MouseClick(event.button, aRope, mainObject, enemyList, frendList);

                else if(main_game == false && end_menu == true){
                    int x, y;
                    SDL_GetMouseState(&x, &y);
                    int k1 = gTextTexture5.getWidth();
                    int k2 = gTextTexture4.getWidth();
                    gameRunning = anEvent->Exit_MouseClick(x, y, 540, k1, WindowWidth);
                    end_menu = anEvent->Retry_MouseClick(x, y, k2, WindowWidth);
                    if(end_menu == false)
                    {
                        main_game = true;
                        window.clear();
                        free(mainObject); mainObject = NULL;
                        free(aRope); aRope = NULL;
                        free(anEvent); anEvent = NULL;
                        free(lava); lava = NULL;
                        free(om); om = NULL;
                        //free(grassTexture); grassTexture = NULL;
                        goto statement2;
                    }
                }
            }
            if(event.type == SDL_MOUSEBUTTONUP)
            {
                if(main_game == true && end_menu == false)
                    Roped = anEvent->MouseClick(event.button, aRope, mainObject, enemyList, frendList);
            }
        }

        if(main_game == false && end_menu == false)
        {
			window.clear();
//            cout<<"Loophole"<<endl;
			//Render current frame
			gTextTexture1.render((WindowWidth - gTextTexture1.getWidth()) / 2, 100, gRenderer);
			gTextTexture2.render((WindowWidth - gTextTexture2.getWidth()) / 2, 350, gRenderer);
			gTextTexture3.render((WindowWidth - gTextTexture3.getWidth()) / 2, 600, gRenderer);

            //Update screen
			SDL_RenderPresent(gRenderer);
        }

        else if(main_game == true && end_menu == false)
        {
            window.clear();
            
            //checkCollision, if collision occurs, end program
            collided = mainObject->CheckCollision(mainObject, enemyList, lava);
            //collided = lava->CheckCollision(frendList);
            ScoredObjectIndex = mainObject->CheckScoreHit(mainObject, frendList);
            if(ScoredObjectIndex != -1)
            {
                Mix_PlayChannel(-1,sound,0);
                TotalScore += 100;
                std::cout<<TotalScore<<std::endl; 
                delete(frendList[ScoredObjectIndex]);
                frendList[ScoredObjectIndex] = NULL;
                frendList.erase(frendList.begin()+ScoredObjectIndex);
            }
        
            if(!collided)
            {
                window.render(grassTexture);
                window.drawObject(mainObject);
                window.drawEnemyObject(enemyList);
                window.drawFrendObject(frendList);
                window.drawLava(lava);
                if(Roped)
                {
                    mainObject->setAcc_y(0);
                    window.drawLine(mainObject, aRope->getTarget());
                    Roped = aRope->RopeCalculus(Roped,enemyList,frendList, lava);
                }
                if(Roped == false)
                {
                    for(auto it:enemyList)
                    {
                        it->setAcc_y(-1*gravity);
                        it->setAcc_x(0);
                    }
                    
                    for(auto it:frendList)
                    {
                        it->setAcc_y(-1*gravity);
                        it->setAcc_x(0);
                    }
                    lava->setAcc_x(0);
                    lava->setAcc_y(-1*gravity);
                }

                for(auto it:enemyList) it->UpdatePosn();
                for(auto it:frendList) it->UpdatePosn(); 
                lava->UpdatePosn();
            }
            else if(collided)
            {
                Mix_PlayChannel(-1,blast,0);
                end_menu = true;
                main_game = false;
                if(TotalScore > HighScore) HighScore = TotalScore;
                
                
                string filename("ScoreBoard.txt");
//                    vector<int> numbers;
                    int number;

                    ifstream input_file(filename);
                    if (!input_file.is_open()) {
                        cerr << "Could not open the file - '"
                             << filename << "'" << endl;
//                        return EXIT_FAILURE;
                    }
                    
                    else
                    {
                        while (input_file >> number) {
                            ScoreSet.insert(number);
                        }
                        ScoreSet.insert(HighScore);
//                        sort(ScoreSet.begin(), ScoreSet.end(), greater<int>() );
                        for (const auto &i : ScoreSet) {
                            cout << i << "; ";
                        }
                        cout << endl;
                    }
                    input_file.close();
                
                
                ofstream OutputFile;
                //File open
                OutputFile.open("ScoreBoard.txt", std::ofstream::out | std::ofstream::trunc);
                
                for(int it: ScoreSet)
                {
                    OutputFile<<it<<endl;
                }
                
                
                //File close
                OutputFile.close();
                
                
                window.end_menu(TotalScore, ScoreSet, &gTextTexture, &gTextTexture1, &gTextTexture2, &gTextTexture3, &gTextTexture4, &gTextTexture5, &gTextTexture6 ,&gTextTexture61, &gTextTexture62, &gTextTexture63);
                
            }
            window.score_menu(TotalScore, &gTextTexture7, &gTextTexture8);
            gTextTexture7.render(1100, 10, gRenderer);
            gTextTexture8.render(30, 10, gRenderer);
            window.display();
        }

        if(main_game == false && end_menu == true)
        {
            SDL_RenderClear(gRenderer);

			//Render current frame
			gTextTexture.render(755, 98, gRenderer);
            gTextTexture1.render((WindowWidth - gTextTexture1.getWidth()) / 2, 100, gRenderer);
			gTextTexture2.render(500, 220, gRenderer);
			gTextTexture3.render(500, 280, gRenderer);
            gTextTexture6.render(720, 220, gRenderer);
            
            gTextTexture61.render(760, 250, gRenderer);
            gTextTexture62.render(760, 280, gRenderer);
            gTextTexture63.render(760, 310, gRenderer);
            
            gTextTexture4.render((WindowWidth - gTextTexture4.getWidth()) / 2, 400, gRenderer);
            gTextTexture5.render((WindowWidth - gTextTexture5.getWidth()) / 2, 540, gRenderer);

			//Update screen
			SDL_RenderPresent(gRenderer);
        }
    }

    window.cleanUp();

    gTextTexture.free();
    gTextTexture1.free();
	gTextTexture2.free();
	gTextTexture3.free();
    gTextTexture4.free();
    gTextTexture5.free();
    gTextTexture6.free();
    gTextTexture7.free();
    gTextTexture8.free();
    
    Mix_FreeMusic(music);
    Mix_CloseAudio();
    Mix_FreeChunk(sound);
    Mix_FreeChunk(blast);

    TTF_Quit();
    IMG_Quit();
    SDL_Quit();
    Mix_Quit();

    return 0;
}
