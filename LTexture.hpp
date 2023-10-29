#include<SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include<iostream>
#include<SDL2/SDL_ttf.h>

class LTexture
{
    public:
		//Initializes variables
		LTexture();

		//Deallocates memory
		~LTexture();
		
		//Creates image from font string
		bool loadFromRenderedText(std::string textureText, SDL_Color textColor, SDL_Renderer* gRenderer, TTF_Font* gFont);
            

		//Deallocates texture
		void free();
		//Renders texture at given point
		void render(int x, int y, SDL_Renderer* gRenderer);
           
		//Gets image dimensions
		int getWidth();
		int getHeight();

	private:
		//The actual hardware texture
		SDL_Texture* mTexture;

		//Image dimensions
		int mWidth;
		int mHeight;
};