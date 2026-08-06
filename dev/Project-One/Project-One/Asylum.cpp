#include "Asylum.h"

Asylum::Asylum()
{
	width = 0;
	height = 0;
}

Asylum::Asylum(int _width, int _height)
{
	width = _width;
	height = _height;

	grid.resize(height);
	for (int r = 0; r < height; r++)
	{
		grid[r].resize(width);
	}
}

Room& Asylum::GetRoom(int row, int col)
{
	return grid[row][col];
}

int Asylum::GetWidth() const
{
	return width;
}

int Asylum::GetHeight() const
{
	return height;
}

bool Asylum::IsValidPosition(int row, int col) const
{
	return (row >= 0 && row < height && col >= 0 && col < width);
}