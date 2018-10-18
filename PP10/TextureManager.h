#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <map>

class TextureManager {
public:
	bool load(std::string fileName, std::string ID, SDL_Renderer * renderer);
	void draw(std::string ID, int x, int y, int width, int height, SDL_Renderer * renderer, SDL_RendererFlip flip = SDL_FLIP_NONE);
	void drawFrame(std::string id, int x, int y, int width, int height, int currentRow, int currentFrame, SDL_Renderer*pRenderer, SDL_RendererFlip flip = SDL_FLIP_NONE);

	std::map < std::string, SDL_Texture * > m_TextureMap;

	static TextureManager * Instance() {
		if (pInstance == 0) {
			pInstance = new TextureManager();
		}
		return pInstance;
	}

private:
	static TextureManager * pInstance;
};

typedef TextureManager TheTextureManager;