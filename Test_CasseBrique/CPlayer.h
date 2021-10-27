#pragma once
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <SDL.h>
#include <SDL_image.h>

//AJOUT INCLUDE
#include "CGameObject.h"
#include "state.h"

using namespace std;

class CPlayer : public CGameObject {
public:
	CPlayer();
	~CPlayer();

	eState getState();

	void setState(eState);



	/*void load(int n_x, int n_y, int n_w, int n_h, string str_textureID);

	void draw(SDL_Renderer* pRenderer, CTextureManager m_textureManager); // héritage de CGameObject à CPlayer

	void update();

	void clean();*/

private:

	eState State;

};


