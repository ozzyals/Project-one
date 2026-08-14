// Project-One.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include "Helper.h"
#include "Player.h"
#include "Asylum.h"
#include "Room.h"
#include "GameEndings.h"

// Forward declarations
void Move(Player& player, Asylum& asylum);
void LookAround(Player& player, Asylum& asylum, bool& canInteract);
void CheckInventory(Player& player);
void CheckStats(Player& player);
void Interact(Player& player, Asylum& asylum, bool& canInteract, bool& running);

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

			if (GameEndings::CheckSanityLoss(player))
			{
				running = false;
			}
			else
			{
				LookAround(player, asylum, canInteract);
				asylum.PrintMap(player.GetRow(), player.GetCol());
			}

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
			Interact(player, asylum, canInteract, running);
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
	player.SetSanity(player.GetSanity() - 2);

	Room& newRoom = asylum.GetRoom(row, col);
	if (newRoom.GetEntrySanityCost() > 0)
	{
		player.SetSanity(player.GetSanity() - newRoom.GetEntrySanityCost());
		std::cout << "\nSomething about this place unsettles you.\n";
	}
	
	std::cout << "You move into " << asylum.GetRoom(row, col).GetName() << ".\n";
	std::cout << "(-2 Sanity)\n";
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

void Interact(Player& player, Asylum& asylum, bool& canInteract, bool& running)
{
	Room& room = asylum.GetRoom(player.GetRow(), player.GetCol());

	if (!room.HasItems())
	{
		std::cout << "\nThere's nothing left to interact with here.\n";
		canInteract = false;
		return;
	}

	std::vector<Item>& items = room.GetItems();

	std::cout << "\nWhich item would you like to interact with?\n";
	for (size_t i = 0; i < items.size(); i++)
	{
		std::cout << i << ": " << items[i].GetName() << "\n";
	}

	int index = Helper::GetValidIndex(static_cast<int>(items.size()));

	Item chosen = items[index];

	if (chosen.GetName() == "Front Door")
	{
		if (!player.HasItem("Rusted Key"))
		{
			std::cout << "\nThe door is locked shut. Despite your best efforts to\n";
			std::cout << "open it, the door does not budge.\n";
			return;
		}

		if (GameEndings::CheckDoorEnding(player, asylum))
			running = false;

		return;
	}

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

		if (chosen.GetName() == "Scalpel")
		{
			std::cout << "\nYour fingers close around the handle.\n";
			std::cout << "For a moment, the surgical ward disappears.\n\n";

			std::cout << "White walls.\n";
			std::cout << "A light above you, painfully bright.\n";
			std::cout << "Something is strapped across your chest.\n\n";

			std::cout << "You try to move.\n";
			std::cout << "You can't.\n\n";

			std::cout << "Someone stands beside you. You can't see their face.\n";
			std::cout << "\"Hold still.\"\n\n";

			std::cout << "The words sound familiar.\n";
			std::cout << "Not because you've heard them before.\n";
			std::cout << "Because you've been here before.\n\n";

			std::cout << "You look down.\n";
			std::cout << "A hand is resting beside you.\n";
			std::cout << "Your hand.\n\n";

			std::cout << "It is holding a scalpel.\n\n";

			std::cout << "You try to scream.\n";
			std::cout << "The hand moves.\n\n";

			std::cout << "You blink.\n\n";

			std::cout << "The surgical ward is back.\n";
			std::cout << "You are standing where you were.\n";
			std::cout << "The scalpel is on the floor.\n\n";

			std::cout << "You stare at your wrist.\n";
			std::cout << "There is no wound. No blood. Nothing.\n\n";

			std::cout << "But your wrist aches as though something happened to it.\n\n";

			std::cout << "For several seconds, you cannot remember which room you\n";
			std::cout << "were standing in before the white walls appeared.\n";
		}
		else
		{
			std::cout << "Reading it leaves you shaken.\n";
		}

		std::cout << "(-" << chosen.GetValue() << " Sanity)\n";
	}

	room.RemoveItem(chosen.GetName());

	canInteract = room.HasItems();
}