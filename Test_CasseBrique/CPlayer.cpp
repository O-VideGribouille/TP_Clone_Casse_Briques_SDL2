#include "CPlayer.h"

#include "CGameObject.h"
#include "CTextureManager.h"

CPlayer::CPlayer()
{
}

CPlayer::~CPlayer()
{
}

eState CPlayer::getState()
{
	return State;
}

void CPlayer::setState(eState State)
{
	this->State = State;
}

/*inline void CPlayer::load(int n_x, int n_y, int n_w, int n_h, string str_textureID)
{
	CGameObject::load(n_x, n_y, n_w, n_h, str_textureID);
}

inline void CPlayer::draw(SDL_Renderer* pRenderer, CTextureManager m_textureManager)
{
	CGameObject::draw(pRenderer, m_textureManager);
}

inline void CPlayer::update()
{
	m_x -= 1;
}

inline void CPlayer::clean()
{
}*/
