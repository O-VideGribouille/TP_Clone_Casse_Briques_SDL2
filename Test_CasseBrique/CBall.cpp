#include "CBall.h"

#include "CGameObject.h"
#include "CTextureManager.h"

CBall::CBall()
{
	this->speedX = 0;
	this->speedY = 0;
}

CBall::~CBall()
{
}

float CBall::getspeedX() const
{
	return speedX;
}

float CBall::getspeedY() const
{
	return speedY;
}

void CBall::setspeedX(float speedX)
{
	this->speedX = speedX;
}

void CBall::setspeedY(float speedY)
{
	this->speedY = speedY;
}

void CBall::DplcmntB()
{
	if (speedX >= -0.01f && speedX <= 0.01f) {
		speedX = 1.0f;
	}
	if (speedY >= -0.01f && speedY <= 0.01f) {
		speedY = -1.0f;
	}
}
