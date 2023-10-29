#include"LTexture.hpp"

//Initializes variables
LTexture::LTexture(){
	mTexture = NULL;
	mWidth = 0;
	mHeight = 0;
}

//Deallocates memory
LTexture::~LTexture(){
	free();
}

//Creates image from font string
bool LTexture::loadFromRenderedText(std::string textureText, SDL_Color textColor, SDL_Renderer* gRenderer, TTF_Font* gFont){
	//Get rid of preexisting texture
	free();

	//Render text surface
	SDL_Surface* textSurface = TTF_RenderText_Solid(gFont, textureText.c_str(), textColor);
	if(textSurface == NULL)
	{
		printf( "Unable to render text surface! SDL_ttf Error: %s\n", TTF_GetError() );
	}
	else
	{
		//Create texture from surface pixels
		mTexture = SDL_CreateTextureFromSurface(gRenderer, textSurface);
		if( mTexture == NULL )
		{
			printf( "Unable to create texture from rendered text! SDL Error: %s\n", SDL_GetError() );
		}
		else
		{
			//Get image dimensions
			mWidth = textSurface->w;
			mHeight = textSurface->h;
		}

		//Get rid of old surface
		SDL_FreeSurface(textSurface);
	}

	//Return success
	return mTexture != NULL;
}

//Deallocates texture
void LTexture::free(){
	//Free texture if it exists
	if(mTexture != NULL){
		SDL_DestroyTexture(mTexture);
		mTexture = NULL;
		mWidth = 0;
		mHeight = 0;
	}
}

//Renders texture at given point
void LTexture::render(int x, int y, SDL_Renderer* gRenderer){
	SDL_Rect* clip = NULL; 
	double angle = 0.0;
	SDL_Point* center = NULL;
	SDL_RendererFlip flip = SDL_FLIP_NONE;
	//Set rendering space and render to screen
	SDL_Rect renderQuad = {x, y, mWidth, mHeight};

	//Set clip rendering dimensions
	if(clip != NULL)
	{
		renderQuad.w = clip->w;
		renderQuad.h = clip->h;
	}

	//Render to screen
	SDL_RenderCopyEx(gRenderer, mTexture, clip, &renderQuad, angle, center, flip);
}

//Gets image dimensions
int LTexture::getWidth(){
	return mWidth;
}
int LTexture::getHeight(){
	return mHeight;
}

