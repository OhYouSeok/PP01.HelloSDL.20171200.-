#pragma once
#include "GameObject.h"
#include "Vector2D.h"

class SDLGameObject : public GameObject
{
public:
	Vector2D m_position;
	Vector2D m_velocity;
	Vector2D m_acceleration;
	SDLGameObject(const LoaderParams* pParams);
	virtual void draw();
	virtual void update() = 0;
	virtual void clean() = 0;

protected:
	int m_width;
	int m_height;
	int m_currentRow;
	int m_currentFrame;
	std::string m_textureID;
};
