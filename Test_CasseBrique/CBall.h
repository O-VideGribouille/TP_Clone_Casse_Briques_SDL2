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

class CBall : public CGameObject {
public:
	CBall();
	~CBall();

protected :

	float speedX;
	float speedY;

public :

	//Accesseurs

	float getspeedX()const;
	float getspeedY()const;


	//Mutateurs
	void setspeedX(float speedX);
	void setspeedY(float speedY);


	//Prototypes
	//Changement de la direction de la balle
	void DplcmntB();

private:

};

