#pragma once
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <SDL.h>
#include <SDL_image.h>

//AJOUT INCLUDE
#include "CTextureManager.h"


using namespace std;

class CGameObject {
public:
	CGameObject();
	CGameObject(string m_textureID, int m_currentFrame, int m_currentRow, int m_x, int m_y, int m_w, int m_h);
	~CGameObject();

	/*void load(int n_x, int n_y, int n_w, int n_h, string str_textureID);

	void draw(SDL_Renderer* pRenderer, CTextureManager m_textureManager);

	void update();
	void clean();*/

	//Acesseurs
	int getX();
	int getY();
	int getW();
	int getH();

	//Mutateurs

	void setX(int m_x);
	void setY(int m_y);
	void setW(int m_w);
	void setH(int m_h);

protected:
	//string m_textureID;

	int m_currentFrame;
	int m_currentRow;
	
	int m_x;
	int m_y;

	int m_w;
	int m_h;


};

