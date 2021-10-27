#include "CTextureManager.h"

CTextureManager::CTextureManager()
{
}


CTextureManager::~CTextureManager()
{
}

bool CTextureManager::load(string strg_fileName, string strg_id, SDL_Renderer* pRenderer)
{
	SDL_Surface* pTempSurface = SDL_LoadBMP(strg_fileName.c_str());

	if (pTempSurface == 0) {
		return false;
	}

	SDL_Texture* pTexture = SDL_CreateTextureFromSurface(pRenderer, pTempSurface);// Nouvelles textures

	SDL_FreeSurface(pTempSurface);

	//Quand tout est ok, ajouter la texture dans la liste
	if (pTempSurface != 0) {
		m_textureMap[strg_id] = pTexture;
		return true;
	}

	//recherche quelque chose de faux
	return false;
}

void CTextureManager::draw(string strg_id, int n_x, int n_y, int n_w, int n_h, SDL_Renderer* pRenderer, SDL_RendererFlip flip)
{
	//SDL_Rect srcRect; // le premier rectangle
	SDL_Rect destRect;//les autres rectangles

	//srcRect.x = 0;
	//srcRect.y = 0;
	//srcRect.w = destRect.w = n_w;
	//srcRect.h = destRect.h = n_h;
	destRect.x = n_x;
	destRect.y = n_y;

	destRect.w = n_w;
	destRect.h = n_h;

	SDL_RenderCopyEx(pRenderer, m_textureMap[strg_id], NULL, &destRect, 0, 0, flip);

}

/*void CTextureManager::drawFrame(string strg_id, int n_x, int n_y, int n_w, int n_h, int n_currentRow, int n_CurrentFrame, SDL_Renderer* pRenderer, SDL_RendererFlip flip)
{
	SDL_Rect srcRect;
	SDL_Rect destRect;

	srcRect.x = n_w * n_CurrentFrame;
	srcRect.y = n_h * (n_currentRow - 1);
	srcRect.w = destRect.w = n_w;
	srcRect.h = destRect.h = n_h;
	destRect.x = n_x;
	destRect.y = n_y;

	SDL_RenderCopyEx(pRenderer, m_textureMap[strg_id], &srcRect, &destRect, 0, 0, flip);

}*/


//CTextureManager* CTextureManager::s_pInstance = 0; // Abandon du singleton
