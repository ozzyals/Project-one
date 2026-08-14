// Project-One.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include "Helper.h"
#include "Player.h"
#include "Asylum.h"
#include "Room.h"

// Forward declarations
void Move(Player& player, Asylum& asylum);
void LookAround(Player& player, Asylum& asylum, bool& canInteract);
void CheckInventory(Player& player);
void CheckStats(Player& player);
void Interact(Player& player, Asylum& asylum, bool& canInteract);

int main()
{
	std::cout << R"(		 __      __       .__                                  __               
		/  \    /  \ ____ |  |   ____  ____   _____   ____   _/  |_  ____       
		\   \/\/   // __ \|  | _/ ___\/  _ \ /     \_/ __ \  \   __\/  _ \      
		 \        /\  ___/|  |_\  \__(  <_> )  Y Y  \  ___/   |  | (  <_> )     
		  \__/\  /  \___  >____/\___  >____/|__|_|  /\___  >  |__|  \____/      
		       \/       \/          \/            \/     \/                     
		___________.__                _____                 .__                 
		\__    ___/|  |__   ____     /  _  \   _________.__.|  |  __ __  _____  
		  |    |   |  |  \_/ __ \   /  /_\  \ /  ___<   |  ||  | |  |  \/     \ 
		  |    |   |   Y  \  ___/  /    |    \\___ \ \___  ||  |_|  |  /  Y Y  \
		  |____|   |___|  /\___  > \____|__  /____  >/ ____||____/____/|__|_|  /
				\/     \/	   \/     \/ \/                      \/  
------------------..............................------------------......-.--------------------------
--------------------.............................-----------------........--------------------------
----------------------.....................-.....------------.............--------------------------
------------------------.----.............++-.--------------................------------------------
----------------------------.............-+++--------.....--.................--------------..-------
-----------------------------..........-######-------...-.-.................----....---......-------
-----------------------...--..........-########--..--.................--------.............------+++
------------------....................-########-...--................--...................----..----
-------------------....................+##++##+-.......................................--...--------
--------------------.......++-.........-+#++#++......................................---..---+++---+
--------------------......++#++++......-++#++++......................................-------.....+++
------------.............+++++--++++...+##+++++.......................................-----....-++++
--------------..........-+#++#+-++###++++##++++...........................-..............--....-##++
...--------------......-+#+-+#+-+++++###++++#++++++-......--.............-+-..-.........---------+--
........------........-+++--++-+---+++++-----+++#++###++-...............-+##-..........-++++######--
..............--......++++-+-+-----+-+#+-------+++++++#####++-..........+#+#-.-..-----+###+##+#++#--
---...........--.......-+-----+++--+--+--------#+---++++++++####++--....-+++........+++#+-+##+++++--
-------.....--++-...--++----+#-----+--++-------++---++++-++++++++#####+-++++------++####+-++++---+--
............+###+-.--+++-+#--------+--++-------++--+-#+++++---++++++######+#++#####++++#+-++++++++--
............-+##+-----+#--------------++------+++----++++-+----++---+++##+##-##++++--++#++++++++++--
+----+#+---.-+++--+++--+-----+-++--+-----------##-++#++++#+##++++----+###+++-+#-----++++---++#####--
##############+++++++--+--++++----++-+++------++###++++#++++++++++++++#+++++-+#+++----+++++####+++-+
++++##++########+++---++--+--+-+++++++++------########+######+####+++++++###+++-++-++##+---+++#+++++
+-----+---++##+++++++---++++#+-++-++--++-----+#+#+####+######+#####+####+########+--+#++---+++++++++
+--+##+##++##+++++-++-+++++-++-++-++--+--+#+-+++#+####+######+#####+####+######+#+-++++----++####+++
++-+#+++++#++++----++-+++++-++-+++#+--++--++++#+#+##+##+###########+####+#####++#+-++++++##+++++++++
++++##+#++#+++++++----+++++-+++#+++++++---++++++##+-++#+++++++++++++++############+++++----++###++-+
+++##++++++++++++++++-++##+++----+++-++---++++####++#+-++++++++++++++######+++###++++##++##+##++++++
+++##+#######++++++++-+++++-+++#++++++#+--+--+#####++#-###+#+++###++++++++#######++-+##+----++++#+-+
#++##++#+##++++++++++-+++#+-++-+++++-++---++-+#+#+#+##-######++####+####+########++++#++---++####+++
#################++++-+++++-+--+++++-+++--++++++#+#++#-#####+++####+####+########++++##+++++#####+++
#################+#++-+++++-+--++++++++--+++++++#+####+######+#####+#########################+++++++
#++##+##+##++++++++++++++++++++++++++##+--++#####+++++++++++++######+++###############+++++++#######
+#+##+#####++##+++##++#+++++++++++##++++++#+++######++++#+##################+###+###################
+#######################+#++++########################+#####################+############++#######++
#########################+++#+#++###########################################+#######################
##########################++##############################++########################################
			__________                                            
			\______   \_______   ____   ______ ______             
			 |     ___/\_  __ \_/ __ \ /  ___//  ___/             
			 |    |     |  | \/\  ___/ \___ \ \___ \              
			 |____|     |__|    \___  >____  >____  >             
						\/     \/     \/              
			___________       __                 ___________      
			\_   _____/ _____/  |_  ___________  \__    ___/___   
			 |    __)_ /    \   __\/ __ \_  __ \   |    | /  _ \  
			 |        \   |  \  | \  ___/|  | \/   |    |(  <_> ) 
			/_______  /___|  /__|  \___  >__|      |____| \____/  
	                        \/     \/          \/                         
			__________                                       .___ 
			\______   \_______  ____   ____  ____   ____   __| _/ 
			 |     ___/\_  __ \/  _ \_/ ___\/ __ \_/ __ \ / __ |  
			 |    |     |  | \(  <_> )  \__\  ___/\  ___// /_/ |  
			 |____|     |__|   \____/ \___  >___  >\___  >____ |  
					              \/    \/     \/     \/                 )";
	std::cout << "\n";
	
	std::cin.get();
	
	Helper::ClearConsol();

	std::cout << "\n";

    

	std::cout << "\n";
	std::cout << "===================================\n";
	std::cout << "         FALL SHELL ASYLUM\n";
	std::cout << "===================================\n\n";

	std::cout << "You wake up on a cold concrete floor, the smell of rust and\n";
	std::cout << "antiseptic thick in the air. Fluorescent lights flicker\n";
	std::cout << "somewhere down the hall. You don't remember how you got here.\n\n";

	std::cout << "You don't remember much at all.\n\n";

	std::cout << "The heavy door behind you has already sealed shut.\n";
	std::cout << "The only way out... is through.\n\n";

	std::cout << "Find a way out of Fall Shell Asylum before it's too late.\n";
	std::cout << "Your Health and Sanity will guide how far you can go.\n\n";
	//std::cout << "Press Enter to Continue.\n\n";

	std::cout << "===================================\n\n";

	Player player("Survivor", 100);
	Asylum asylum(5, 5);
	asylum.BuildLayout();

	asylum.GetRoom(4, 2);
	player.SetPosition(4, 2);

	bool running = true;
	bool canInteract = false;

	//might replace with difrent initial description
	LookAround(player, asylum, canInteract);

	while (running)
	{
		std::cout << "\n--- What would you like to do? ---\n";
		std::cout << "1. Move\n";
		std::cout << "2. Look Around\n";
		std::cout << "3. Check Inventory\n";
		std::cout << "4. Check Stats\n";
		std::cout << "5. View Map\n";
		
		if (canInteract)
			std::cout << "6. Interact\n";
		
		std::cout << "0. Quit\n";
		std::cout << "Enter choice: ";

		std::vector<int> validChoices = { 0, 1, 2, 3, 4, 5 };
		if (canInteract)
			validChoices.push_back(6);

		int choice = Helper::GetMenuChoice(validChoices);

		switch (choice)
		{
		case 1:
			Move(player, asylum);
			canInteract = false;
			//Temporary for easier testing automatically looks around room when moving 
			LookAround(player, asylum, canInteract);
			break;
		case 2:
			LookAround(player, asylum, canInteract);
			break;
		case 3:
			CheckInventory(player);
			break;
		case 4:
			CheckStats(player);
			break;
		case 5:
			asylum.PrintMap(player.GetRow(), player.GetCol());
			break;
		case 6:
			Interact(player, asylum, canInteract);
			break;
		case 0:
			running = false;
			break;
		}
	}

	std::cout << "\nThanks for playing.\n";

	return 0;
	
}

void Move(Player& player, Asylum& asylum)
{
	std::cout << "\nWhich direction? (N/S/E/W): ";
	char direction;
	std::cin >> direction;

	int row = player.GetRow();
	int col = player.GetCol();

	if (direction == 'N' || direction == 'n')
		row--;
	else if (direction == 'S' || direction == 's')
		row++;
	else if (direction == 'E' || direction == 'e')
		col++;
	else if (direction == 'W' || direction == 'w')
		col--;
	else
	{
		std::cout << "Invalid direction.\n";
		return;
	}

	if (!asylum.IsValidPosition(row, col))
	{
		std::cout << "You can't go that way.\n";
		return;
	}

	player.SetPosition(row, col);
	std::cout << "You move into " << asylum.GetRoom(row, col).GetName() << ".\n";
}

void LookAround(Player& player, Asylum& asylum, bool& canInteract)
{
	Room& room = asylum.GetRoom(player.GetRow(), player.GetCol());

	room.SetExplored(true);
	//std::cout << "[DEBUG] Player at row=" << player.GetRow() << ", col=" << player.GetCol() << "\n";
	std::cout << "\n" << room.GetName() << "\n";
	std::cout << room.GetDescription() << "\n\n";
	//std::cout << "[DEBUG] Grid size: " << asylum.GetWidth() << " x " << asylum.GetHeight() << "\n";

	std::cout << "Exits: ";
	if (asylum.IsValidPosition(player.GetRow() - 1, player.GetCol())) std::cout << "North ";
	if (asylum.IsValidPosition(player.GetRow() + 1, player.GetCol())) std::cout << "South ";
	if (asylum.IsValidPosition(player.GetRow(), player.GetCol() - 1)) std::cout << "West ";
	if (asylum.IsValidPosition(player.GetRow(), player.GetCol() + 1)) std::cout << "East ";
	std::cout << "\n";

	if (room.HasItems())
	{
		std::cout << "\nYou notice:\n";
		for (Item& item : room.GetItems())
		{
			std::cout << " - " << item.GetName() << "\n";
		}
		canInteract = true;
	}
	else
	{
		canInteract = false;
	}
}

void CheckInventory(Player& player)
{
	std::cout << "\n--- Inventory ---\n";

	if (player.GetInventory().empty())
	{
		std::cout << "You have nothing.\n";
		return;
	}

	for (Item& item : player.GetInventory())
	{
		std::cout << " - " << item.GetName() << "\n";
	}
}

void CheckStats(Player& player)
{
	std::cout << "\n--- Stats ---\n";
	std::cout << "Sanity: " << player.GetSanity() << "\n";
}

void Interact(Player& player, Asylum& asylum, bool& canInteract)
{
	Room& room = asylum.GetRoom(player.GetRow(), player.GetCol());

	if (!room.HasItems())
	{
		std::cout << "\nThere's nothing left to interact with here.\n";
		canInteract = false;
		return;
	}

	std::vector<Item>& items = room.GetItems();

	std::cout << "\nWhich item would you like to pick up?\n";
	for (size_t i = 0; i < items.size(); i++)
	{
		std::cout << i << ": " << items[i].GetName() << "\n";
	}

	int index = Helper::GetValidIndex(static_cast<int>(items.size()));

	Item chosen = items[index];
	player.AddItem(chosen);

	std::cout << "\nYou picked up: " << chosen.GetName() << "\n";
	std::cout << chosen.GetDescription() << "\n";

	if (chosen.GetEffect() == ItemEffect::SanityBoost)
	{
		player.SetSanity(player.GetSanity() + chosen.GetValue());
		std::cout << "Your sanity improves slightly. (+" << chosen.GetValue() << " Sanity)\n";
	}
	else if (chosen.GetEffect() == ItemEffect::SanityDrain)
	{
		player.SetSanity(player.GetSanity() - chosen.GetValue());
		std::cout << "Reading it leaves you shaken. (-" << chosen.GetValue() << " Sanity)\n";
	}

	room.RemoveItem(chosen.GetName());

	canInteract = room.HasItems();
}