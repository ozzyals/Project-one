#include "GameEndings.h"
#include <iostream>
#include "Helper.h"

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
		PrintFalseEnding();
		return true;
	}

	return false;
}

// PrintLossEnding, PrintFalseEnding, PrintTrueEnding

void GameEndings::PrintLossEnding()
{
	std::cout << Color::Red;
	std::cout << "\n===================================\n";
	std::cout << "Something inside you finally gives way.\n\n";

	std::cout << "The walls are moving now.\n";
	std::cout << "Not breathing. Moving.\n";
	std::cout << "The corridor stretches away from you, impossibly long, while\n";
	std::cout << "the lights above flicker in a rhythm you somehow recognize.\n\n";

	std::cout << "There are voices everywhere.\n";
	std::cout << "Doctors.\n";
	std::cout << "Nurses.\n";
	std::cout << "Someone crying.\n";
	std::cout << "Someone calling your name.\n\n";

	std::cout << "You try to remember your name.\n\n";

	std::cout << "Nothing comes.\n\n";

	std::cout << "You try to remember why you came here.\n\n";

	std::cout << "Nothing.\n\n";

	std::cout << "Then you notice the door at the end of the corridor.\n";
	std::cout << "You have been walking toward it for what feels like hours.\n\n";

	std::cout << "A figure is standing beside it.\n\n";

	std::cout << "\"Back to your room.\"\n\n";

	std::cout << "You want to run.\n";
	std::cout << "Instead, you follow.\n\n";

	std::cout << "The last thing you hear is the sound of a key turning in a lock.\n\n";

	std::cout << "===================================\n";
	std::cout << "YOU LOSE.\n";
	std::cout << "===================================\n\n";
	std::cout << Color::Reset;
}

void GameEndings::PrintFalseEnding()
{
	std::cout << Color::Yellow;
	std::cout << "\n===================================\n";

	std::cout << "The key turns.\n\n";

	std::cout << "For a moment, nothing happens.\n\n";

	std::cout << "Then the lock gives way.\n";
	std::cout << "The door swings open, and cold night air rushes across your face.\n\n";

	std::cout << "You step outside.\n\n";

	std::cout << "The asylum stands behind you, silent and dark.\n";
	std::cout << "For the first time since you woke up inside, there is nothing\n";
	std::cout << "between you and the outside world.\n\n";

	std::cout << "You made it out.\n\n";

	std::cout << "You start walking.\n\n";

	std::cout << "But after a few steps, something begins to bother you.\n\n";

	std::cout << "You don't know what it is.\n";
	std::cout << "Not exactly.\n\n";

	std::cout << "There is a thought at the edge of your memory.\n";
	std::cout << "A question you were supposed to answer.\n";
	std::cout << "Something you were supposed to find.\n\n";

	std::cout << "You stop.\n\n";

	std::cout << "Behind you, the asylum waits.\n\n";

	std::cout << "You tell yourself to keep walking.\n";
	std::cout << "You don't.\n\n";

	std::cout << "Slowly, you turn around.\n\n";

	std::cout << "The front door is still open.\n\n";

	std::cout << "You walk back toward it.\n\n";

	std::cout << "You don't remember deciding to go inside.\n\n";

	std::cout << "The moment you cross the threshold, the door slams shut behind you.\n\n";

	std::cout << "The lock turns.\n\n";

	std::cout << "From somewhere deep inside the asylum, a bell begins to ring.\n\n";

	std::cout << "===================================\n";
	std::cout << "GAME OVER.\n";
	std::cout << "===================================\n\n";
	std::cout << Color::Reset;
}

void GameEndings::PrintTrueEnding()
{
	std::cout << Color::Green;
	std::cout << "\n===================================\n";

	std::cout << "You stand before the door with the key in your hand.\n\n";

	std::cout << "The file is tucked beneath your arm.\n";
	std::cout << "The journal is open to its final page.\n\n";

	std::cout << "For a long moment, you simply stand there.\n\n";

	std::cout << "The names.\n";
	std::cout << "The dates.\n";
	std::cout << "The missing records.\n";
	std::cout << "The orders without signatures.\n";
	std::cout << "The treatments that were never meant to treat anything.\n\n";

	std::cout << "And suddenly, the question that has followed you through every\n";
	std::cout << "corridor no longer feels like a question.\n\n";

	std::cout << "You were never here to be cured.\n\n";

	std::cout << "You were here because someone needed you to disappear.\n\n";

	std::cout << "The asylum was never meant to keep you safe.\n";
	std::cout << "It was meant to make sure no one would believe you.\n\n";

	std::cout << "You look back down the corridor.\n\n";

	std::cout << "For the first time, the silence doesn't frighten you.\n\n";

	std::cout << "There is nothing left here that you need to understand.\n";
	std::cout << "Nothing left that they can take from you.\n\n";

	std::cout << "You turn the key.\n\n";

	std::cout << "The lock opens.\n\n";

	std::cout << "The door swings outward onto a grey morning sky.\n";
	std::cout << "Cold air fills your lungs.\n\n";

	std::cout << "You step outside.\n\n";

	std::cout << "Behind you, the asylum remains silent.\n\n";

	std::cout << "You don't look back.\n\n";

	std::cout << "This time, nothing calls you inside.\n\n";

	std::cout << "You walk away carrying the truth with you.\n\n";

	std::cout << "===================================\n";
	std::cout << "YOU HAVE ESCAPED FALL SHELL ASYLUM.\n";
	std::cout << "===================================\n\n";
	std::cout << Color::Reset;
}