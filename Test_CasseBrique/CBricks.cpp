#include "CBricks.h"

#include "CGameObject.h"
#include "CTextureManager.h"

CBricks::CBricks()
{
	this->casse = false;
}

CBricks::~CBricks()
{
}

bool CBricks::getcasse()
{
	return casse;
}

void CBricks::setcasse(bool casse)
{
	this->casse = casse;
}
