#pragma once
#include "SDLGameObject.h"
#include "LoaderParams.h"
#include <iostream>
#include <vector>
class Wall : public SDLGameObject

{

public:
	void draw();
	void update();
	void clean();
	Wall(const LoaderParams * params);
	std::vector<Wall*> getWalls() const;
private:
	std::vector<Wall*> _walls;
};