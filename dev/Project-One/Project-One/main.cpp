// Project-One.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include "Helper.h"
#include "Player.h"
#include "Asylum.h"
#include "Room.h"
#include "GameEndings.h"
#include "GameActions.h"



//Opening screen
int main()
{
	bool playAgain = true;

	while (playAgain)
	{
		Helper::ClearConsol();

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

    
	// Initial Description
	

	//Player stats and map size
	Player player("Survivor", 100);
	Asylum asylum(5, 5);
	asylum.BuildLayout();

	//Starting room
	asylum.GetRoom(4, 2);
	player.SetPosition(4, 2);

	bool running = true;
	bool canInteract = false;

	GameActions::RefreshView(player, asylum, canInteract);



	// Initial Description
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


	std::cout << "===================================\n\n";


	while (running)
	{
		std::cout << "\n--- What would you like to do? ---\n\n";
		std::cout << "W. Move North\n";
		std::cout << "S. Move South\n";
		std::cout << "A. Move West\n";
		std::cout << "D. Move East\n";
		std::cout << "1. Check Inventory\n";
		std::cout << "2. Check Stats\n";
		
		
		if (canInteract)
			std::cout << "3. Interact\n";
		
		std::cout << "0. Quit\n";
		std::cout << "Enter choice: ";

		std::string input;
		std::getline(std::cin, input);

		if (input.length() != 1)
		{
			Helper::ClearConsol();
			GameActions::RefreshView(player, asylum, canInteract);
			std::cout << "\nInvalid choice, please try again.\n";
			continue;
		}

		char choice = std::toupper(input[0]);

		if (choice == 'W' || choice == 'A' || choice == 'S' || choice == 'D')
		{
			Helper::ClearConsol();
			GameActions::Move(player, asylum, choice, canInteract, running);
			
		}
	
		else if (choice == '1')
		{
			GameActions::CheckInventory(player, asylum, canInteract);
			
		}
		else if (choice == '2')
		{
			GameActions::CheckStats(player, asylum, canInteract);
			
		}
		
		else if (choice == '3' && canInteract)
		{
			GameActions::Interact(player, asylum, canInteract, running);

		}
		else if (choice == '0')
		{
			running = false;
		}
		else
		{
			Helper::ClearConsol();

			GameActions::RefreshView(player, asylum, canInteract);
			std::cout << "\nInvalid choice, please try again.\n";
		}
	}

	// End-of-game prompt
	std::cout << "\n--- Game Over ---\n";
	std::cout << "1. Play Again\n";
	std::cout << "0. Exit\n";
	std::cout << "Enter choice: ";

	std::string endChoice;
	std::getline(std::cin, endChoice);

	if (endChoice != "1")
	{
		playAgain = false;
	}
	}

	std::cout << "\nThanks for playing.\n";

	return 0;
}
