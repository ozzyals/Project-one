#include "Asylum.h"
#include "Helper.h"

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
	grid[4][2] = Room("Entrance Hall", "A dim, dust-covered hall. The air is still. This is where you entered.");

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

	//items
	grid[0][1].AddItem(Item("Patient File",
		"The file is thick enough to strain the folder. Several pages have \n"
		"been replaced, their edges cut cleanly from the binding. The earliest \n"
		"notes are ordinary: insomnia, anxiety, difficulty concentrating. \n"
		"Nothing unusual. Nothing that explains why the patient was sent here. \n\n"

		"Three months later, the language changes. 'Agitation.' 'Paranoia.' \n"
		"'Fixation on matters outside the patient's concern.' The notes become \n"
		"shorter as the treatment becomes harsher. Sedation increased. \n"
		"Isolation extended. Visitors prohibited. Correspondence restricted. \n\n"

		"One page contains a list of questions the patient repeatedly asked: \n"
		"Who authorized the transfers? Where did the money go? Why were the \n"
		"names removed from the records? Beside each question, someone has \n"
		"written the same word in red ink: 'Delusion.' \n\n"

		"The procedure log continues for several pages. Some entries have \n"
		"dates but no explanation. Others have explanations but no signature. \n"
		"Several signatures appear to belong to the same person, though the \n"
		"names are different. \n\n"

		"Near the back of the file, a typed memorandum has been folded in \n"
		"half. It contains no diagnosis. No treatment plan. Only an order \n"
		"to maintain the patient's confinement until further notice. \n\n"

		"The final medical assessment is remarkably brief. \n\n"

		"'Patient demonstrates improved compliance. Resistant beliefs no \n"
		"longer expressed. Continued observation unnecessary.' \n\n"

		"Below it, written by hand in a different ink: \n\n"

		"'Do not release.'\n",
		ItemEffect::None, 0));
	grid[0][0].AddItem(Item("Sedative", "A vial of clear liquid. Might help calm your nerves.", ItemEffect::SanityBoost, 15));
	grid[0][4].AddItem(Item("Pill Bottle", "Half-empty, label worn away.", ItemEffect::SanityBoost, 10));
	grid[4][0].AddItem(Item("Old Journal",
		"The journal is small enough to fit inside a coat pocket. The first \n"
		"pages are ordinary. Medication rounds. Broken lamps. Arguments over \n"
		"shift changes. Complaints about the heating. Names of patients who \n"
		"have since disappeared from the records. \n\n"

		"Then the handwriting changes. \n"

		"'Patient in 14B keeps asking about the same thing. Not the usual \n"
		"questions. Names. Dates. Payments. He says someone altered the \n"
		"admission records.' \n\n"

		"A few pages later: \n"

		"'I checked. I shouldn't have. There are records missing from the \n"
		"filing room. Not misplaced. Removed.' \n\n"

		"The next entry has been written so hard that the pen has torn the \n"
		"paper. \n\n"

		"'The order for his admission didn't come from a doctor.' \n\n"

		"Several lines have been crossed out. One remains visible beneath \n"
		"them: 'It came from the mayor's office.' \n\n"

		"The following pages are dated several weeks apart. The nurse writes \n"
		"about medications she was told to administer, procedures she was \n"
		"told not to question, and visitors who never sign the visitor log. \n"
		"She begins referring to the patient simply as '14B.' \n\n"

		"Then: \n\n"

		"'I found the records he was talking about. Payments from the city. \n"
		"Contracts awarded to companies that don't exist. Names appearing \n"
		"in three places when they should appear in one. Money disappearing \n"
		"between offices.' \n\n"

		"The handwriting becomes smaller after that. \n\n"

		"'He wasn't imagining it.' \n\n"

		"A final entry begins several days later. \n\n"

		"'They know I looked. Dr. Vale told me to forget what I found. \n"
		"He said the patient was dangerous because he couldn't stop \n"
		"telling the truth. I asked him what that made us.' \n\n"

		"The rest of the page is blank. \n\n"

		"On the last page, written almost illegibly: \n\n"

		"'They are moving him tonight. I don't know where. I hid the \n"
		"copies in the records room. If anyone finds this, please understand \n"
		"that he was never sick. They needed him to look sick because'\n\n"
		"The last mark trails off the page.\n",
		ItemEffect::None, 0));
	grid[0][3].AddItem(Item("Rusted Key", "A heavy iron key, caked in rust.", ItemEffect::Key, 0));
	grid[4][2].AddItem(Item("Front Door", "The heavy door you first came through. It's shut tight.", ItemEffect::None, 0));
	grid[4][4].AddItem(Item("Scalpel", "A surgical blade, still gleaming despite the dust.", ItemEffect::SanityDrain, 20));

	//sanity drain
	grid[0][0].SetEntrySanityCost(8);  // Padded Cell
	grid[4][4].SetEntrySanityCost(10); // Surgical Ward
}


void Asylum::PrintMap(int playerRow, int playerCol)
{
	std::cout << Color::BrightBlue;
	std::cout << "\n--- Map ---\n\n";
	std::cout << Color::Reset;

	const int cellWidth = 16;

	for (int r = 0; r < height; r++)
	{
		for (int c = 0; c < width; c++)
		{
			bool adjacentExplored = false;

			if (r > 0 && grid[r - 1][c].IsExplored()) adjacentExplored = true;
			if (r < height - 1 && grid[r + 1][c].IsExplored()) adjacentExplored = true;
			if (c > 0 && grid[r][c - 1].IsExplored()) adjacentExplored = true;
			if (c < width - 1 && grid[r][c + 1].IsExplored()) adjacentExplored = true;

			std::string label;
			std::string labelColor;

			if (r == playerRow && c == playerCol)
			{
				label = "[YOU]";
				labelColor = Color::Green;
			}
			else if (grid[r][c].IsBlocked())
			{
				if (adjacentExplored)
				{
					label = "Wall";
					labelColor = Color::Red;
				}
				else
				{
					label = "???";
					labelColor = Color::Gray;
				}
			}
			else if (grid[r][c].IsExplored())
			{
				label = grid[r][c].GetName();
				labelColor = Color::Cyan;
			}
			else
			{
				label = "???";
				labelColor = Color::Gray;
			}

			if (label.length() > cellWidth - 1)
				label = label.substr(0, cellWidth - 1);

			std::cout << labelColor << label << Color::Reset;

			for (size_t pad = label.length(); pad < cellWidth; pad++)
				std::cout << " ";
		}
		std::cout << "\n\n";
	}

	std::cout << Color::Gray;
	std::cout << "[YOU] = Your location    ??? = Unexplored\n";
	std::cout << Color::Reset;
}