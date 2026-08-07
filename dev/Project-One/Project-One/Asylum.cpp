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
	if (row < 0 || row >= height || col < 0 || col >= width)
		return false;

	if (grid[row][col].IsBlocked())
		return false;

	return true;
}

void Asylum::BuildLayout()
{
	bool blockedMap[5][5] =
	{
		{ false, false, true,  false, false },
		{ false, false, false, false, false },
		{ true,  true,  false, true,  true  },
		{ false, false, false, false, false },
		{ false, true,  false, true,  false }
	};

	for (int r = 0; r < 5; r++)
	{
		for (int c = 0; c < 5; c++)
		{
			if (blockedMap[r][c])
			{
				grid[r][c] = Room("Blocked Passage", "The way forward is blocked. There's no path through here.");
				grid[r][c].SetBlocked(true);
			}
		}
	}
	// Named, non-hallway rooms
	grid[0][0] = Room("Padded Cell", "The walls are soft and stained. Faint scratch marks run in long, desperate lines.");
	grid[0][1] = Room("Records Room", "Rows of collapsed shelving spill patient files across the floor.");
	grid[0][3] = Room("Nurse's Station", "An overturned desk sits beside a rusted filing cabinet. A clipboard lies open on the floor.");
	grid[0][4] = Room("Pharmacy", "Shattered glass crunches underfoot. Most of the cabinets have already been emptied.");
	grid[3][0] = Room("Chapel", "Rows of splintered pews face a cracked stained-glass window. It's unnervingly quiet here.");
	grid[4][0] = Room("Library", "Towering shelves lean at odd angles. Most of the books have long since rotted away.");
	grid[4][4] = Room("Surgical Ward", "A single operating table sits under a broken light fixture. You don't linger.");

	// Hallways - same purpose, different flavor text
	grid[1][0] = Room("Corridor", "The wallpaper here has curled away from the plaster in long, brittle strips.");
	grid[1][1] = Room("Corridor", "The hallway stretches ahead, lined with peeling wallpaper and flickering shadows.");
	grid[1][2] = Room("Corridor", "Water drips somewhere above. The corridor smells faintly of mildew.");
	grid[1][3] = Room("Corridor", "A row of dead lightbulbs hangs overhead. Your footsteps echo louder than they should.");
	grid[1][4] = Room("Corridor", "A gurney lies overturned against the wall, one wheel still slowly spinning.");
	grid[2][2] = Room("Corridor", "Gurneys, desks and chairs have been used to form a makeshift baracade. \nA narrow passage has been cleared in the center of the coridor, \nbarely wide enough to walk through comfortably.");
	grid[3][1] = Room("Corridor", "Faded signage on the wall is too worn to read anymore.");
	grid[3][2] = Room("Corridor", "The floor creaks with every step. Something skitters just out of sight.");
	grid[3][3] = Room("Corridor", "A cold draft moves through the hall, though you can't find its source.");
	grid[3][4] = Room("Corridor", "Old gurney tracks are worn into the floor, leading off in both directions.");

	// Entrance, where the player enters
	grid[4][2] = Room("Entrance Hall", "A dim, dust-covered hall. The air is still. This is where you entered.");
}