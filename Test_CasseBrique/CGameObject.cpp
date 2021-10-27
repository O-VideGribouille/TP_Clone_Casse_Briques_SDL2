#include "CGameObject.h"
#include "CTextureManager.h"

CGameObject::CGameObject()
{
	//this->m_textureID = "";

	this->m_currentFrame = 0;
	this->m_currentRow = 0;
	
	this->m_x = 0;
	this->m_y = 0;

	this->m_w = 0;
	this->m_h = 0;
}

CGameObject::CGameObject(string m_textureID, int m_currentFrame, int m_currentRow, int m_x, int m_y, int m_w, int m_h)
{
	//this->m_textureID = m_textureID;

	this->m_currentFrame = m_currentFrame;
	this->m_currentRow = m_currentRow;
	
	this->m_x = m_x;
	this->m_y = m_y;

	this->m_w = m_w;
	this->m_h = m_h;
}

CGameObject::~CGameObject()
{
}

//Acesseurs
int CGameObject::getX()
{
	return m_x;
}

int CGameObject::getY()
{
	return m_y;
}

int CGameObject::getW()
{
	return m_w;
}

int CGameObject::getH()
{
	return m_h;
}


//Mutateurs
void CGameObject::setX(int m_x)
{
	this->m_x = m_x;
}

void CGameObject::setY(int m_y)
{
	this->m_y = m_y;
}

void CGameObject::setW(int m_w)
{
	this->m_w = m_w;
}

void CGameObject::setH(int m_h)
{
	this->m_h = m_h;
}



/*inline void CGameObject::load(int n_x, int n_y, int n_w, int n_h, string str_textureID)
{

	m_x = n_x;
	m_y = n_y;
	m_w = n_w;
	m_h = n_h;
	m_textureID = str_textureID;

	m_currentRow = 1;
	m_currentFrame = 1;

}

inline void CGameObject::draw(SDL_Renderer* pRenderer, CTextureManager m_textureManager)
{
	m_textureManager.drawFrame(m_textureID, m_x, m_y, m_w, m_h, m_currentRow, m_currentFrame, pRenderer);
	
}

inline void CGameObject::update()
{
	m_x += 1;
}

inline void CGameObject::clean()
{
}*/
