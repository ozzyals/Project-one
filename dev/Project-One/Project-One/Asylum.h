#pragma once

#include <vector>
#include "Room.h"

class Asylum
{
public:
	Asylum();
	Asylum(int _width, int _height);

	Room& GetRoom(int row, int col);
	int GetWidth() const;
	int GetHeight() const;
	bool IsValidPosition(int row, int col) const;

private:
	std::vector<std::vector<Room>> grid;
	int width;
	int height;
};