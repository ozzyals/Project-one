#include "GameEndings.h"
#include <iostream>

bool GameEndings::CheckSanityLoss(Player& player)
{
	if (player.GetSanity() <= 0)
	{
		PrintLossEnding();
		return true;
	}

	return false;
}

bool GameEndings::CheckDoorEnding(Player& player, Asylum& asylum)
{
	bool hasKey = player.HasItem("Rusted Key");
	bool hasFile = player.HasItem("Patient File");
	bool hasJournal = player.HasItem("Old Journal");

	if (hasKey && hasFile && hasJournal)
	{
		PrintTrueEnding();
		return true;
	}
	else if (hasKey)
	{
		PrintBittersweetEnding();
		return true;
	}

	return false;
}

// ... PrintLossEnding, PrintBittersweetEnding, PrintTrueEnding unchanged ...

void GameEndings::PrintLossEnding()
{
	std::cout << "\n===================================\n";
	std::cout << "Your mind gives way. The walls seem to breathe, and the\n";
	std::cout << "voices that were once distant whispers are now all you can\n";
	std::cout << "hear. You are no longer sure where the asylum ends and you\n";
	std::cout << "begin.\n\n";
	std::cout << "YOU LOSE.\n";
	std::cout << "===================================\n\n";
}

void GameEndings::PrintBittersweetEnding()
{
	std::cout << "\n===================================\n";
	std::cout << "The key turns in the lock. The door swings open, and cold\n";
	std::cout << "air rushes in. You step outside.\n\n";
	std::cout << "You made it out.\n\n";
	std::cout << "But something is still nagging at you. A question left\n";
	std::cout << "unanswered, a room left unseen. Despite every urge to run,\n";
	std::cout << "you find yourself turning back toward the door.\n\n";
	std::cout << "You walk back into the asylum. The door slams shut behind\n";
	std::cout << "you.\n\n";
	std::cout << "GAME OVER.\n";
	std::cout << "===================================\n\n";
}

void GameEndings::PrintTrueEnding()
{
	std::cout << "\n===================================\n";
	std::cout << "You stand at the door, the file and journal heavy in your\n";
	std::cout << "hands. It all makes sense now, the names, the dates, the\n";
	std::cout << "quiet horror hidden in the margins. You understand what\n";
	std::cout << "happened here, and you understand that you are meant to\n";
	std::cout << "carry it out with you.\n\n";
	std::cout << "The key turns easily. The door opens onto grey morning\n";
	std::cout << "light. You step through, and this time, nothing pulls you\n";
	std::cout << "back.\n\n";
	std::cout << "YOU HAVE ESCAPED FALL SHELL ASYLUM.\n";
	std::cout << "===================================\n\n";
}