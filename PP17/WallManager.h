#pragma once
#include <vector>
#include "Wall.h"

class WallManager
{
public:
	static WallManager * getInstance();
	std::vector<Wall*> getWalls() const;
	void PushBackWall(Wall * wall);
	void DeleteWall(Wall * wall);
	void draw();

	void update();

	void clean();
private:

	WallManager() {}

	static WallManager * _instance;

	std::vector<Wall*> _walls;

};