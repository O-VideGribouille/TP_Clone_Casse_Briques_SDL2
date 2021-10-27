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

using namespace std;


class CBricks : public CGameObject {
public:
	CBricks();
	~CBricks();

	//const int T_TAILLE;

	bool casse;

	//assesseurs
	bool getcasse();

	//mutateurs
	void setcasse(bool casse);

private:

};