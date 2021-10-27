#pragma once
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <SDL.h>
#include <SDL_image.h>

#include <vector>
#include <typeinfo>

//AJOUT INCLUDE
#include "CTextureManager.h"
#include "CGameObject.h"
#include "CPlayer.h"
#include "CBall.h"
#include "CBricks.h"
#include "CText.h"
#include "state.h"


using namespace std;

#define T_H  5
#define T_W  8

#ifndef __Game__
#define __Game__



class CGame {
public:
	CGame();
	CGame(SDL_Window* m_pWindow, SDL_Renderer* m_pRenderer, int m_CurrentFrame, bool m_bRunning);
	~CGame();
	//INITIALISATION
	bool init(const char* chr_title, int n_x, int n_y, int n_h, int n_w, int n_flags);

	//AFFICHAGE
	void render();

	//UPDATE
	void update();

	//HANDLEEVENT
	void handleEvents();

	//LIBERATION MEMOIRE
	void clean();

	bool running() { return m_bRunning; }




private:

	SDL_Window* m_pWindow;
	SDL_Renderer* m_pRenderer;

	int m_CurrentFrame; // pour l'animation d'un sprite
	CTextureManager m_textureManager;

	CPlayer m_player;
	CBall m_ball;
	
	CBricks m_bricks[T_H][T_W];
	
	CText m_text1;
	CText m_text2;
	CText m_text3;
	CText m_text4;

	bool m_bRunning;

};


#endif // !__Game__
