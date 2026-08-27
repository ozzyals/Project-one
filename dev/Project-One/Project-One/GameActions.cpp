#include "GameActions.h"
#include "GameEndings.h"
#include "Helper.h"
#include <iostream>

void GameActions::UpdateRoomState(Player& player, Asylum& asylum, bool& canInteract)
{
	Room& room = asylum.GetRoom(player.GetRow(), player.GetCol());
	room.SetExplored(true);
	canInteract = room.HasItems();
}

void GameActions::LookAround(Player& player, Asylum& asylum, bool& canInteract)
{
	Room& room = asylum.GetRoom(player.GetRow(), player.GetCol());

	std::cout << "\n" << Color::Cyan << room.GetName() << Color::Reset << "\n";
	std::cout << Color::BrightMagenta;
	std::cout << room.GetDescription() << "\n\n";
	std::cout << Color::Reset;

	std::cout << Color::Yellow << "Exits: ";
	if (asylum.IsValidPosition(player.GetRow() - 1, player.GetCol())) std::cout << "North ";
	if (asylum.IsValidPosition(player.GetRow() + 1, player.GetCol())) std::cout << "South ";
	if (asylum.IsValidPosition(player.GetRow(), player.GetCol() - 1)) std::cout << "West ";
	if (asylum.IsValidPosition(player.GetRow(), player.GetCol() + 1)) std::cout << "East ";
	std::cout << Color::Reset << "\n";

	if (room.HasItems())
	{
		std::cout << Color::BrightYellow;
		std::cout << "\nYou notice:\n";
		std::cout << Color::Reset;
		for (Item& item : room.GetItems())
		{
			std::cout << Color::BrightMagenta;
			std::cout << " - " << item.GetName() << Color::Reset << "\n";
			std::cout << Color::Reset;
		}
	}
}

void GameActions::RefreshView(Player& player, Asylum& asylum, bool& canInteract)
{
	UpdateRoomState(player, asylum, canInteract);
	asylum.PrintMap(player.GetRow(), player.GetCol());
	LookAround(player, asylum, canInteract);
}

void GameActions::Move(Player& player, Asylum& asylum, char direction, bool& canInteract, bool& running)
{
	int row = player.GetRow();
	int col = player.GetCol();

	if (direction == 'W')
		row--;
	else if (direction == 'S')
		row++;
	else if (direction == 'A')
		col--;
	else if (direction == 'D')
		col++;

	if (!asylum.IsValidPosition(row, col))
	{
		RefreshView(player, asylum, canInteract);
		std::cout << Color::BrightYellow;
		std::cout << "\nYou can't go that way.\n";
		std::cout << Color::Reset;
		return;
	}

	player.SetPosition(row, col);
	player.SetSanity(player.GetSanity() - 2);

	Room& newRoom = asylum.GetRoom(row, col);
	int entryCost = newRoom.GetEntrySanityCost();

	if (entryCost > 0)
	{
		player.SetSanity(player.GetSanity() - entryCost);
	}

	if (GameEndings::CheckSanityLoss(player))
	{
		running = false;
	}
	else
	{
		RefreshView(player, asylum, canInteract);

		std::cout << "\n" << Color::Red << "(-2 Sanity)" << Color::Reset << "\n\n";

		if (entryCost > 0)
		{
			std::cout << Color::BrightYellow;
			std::cout << "Something about this place unsettles you.\n";
			std::cout << Color::BrightRed;
			std::cout << "(-" << entryCost << " Sanity)\n";
			std::cout << Color::Reset;
		}
	}
}

void GameActions::CheckInventory(Player& player, Asylum& asylum, bool& canInteract)
{
	Helper::ClearConsol();

	RefreshView(player, asylum, canInteract);
	std::cout << Color::BrightYellow;
	std::cout << "\n--- Inventory ---\n";

	if (player.GetInventory().empty())
	{
		std::cout << Color::BrightRed;
		std::cout << "You have nothing.\n";
		std::cout << Color::Reset;
		return;
	}

	for (Item& item : player.GetInventory())
	{
		std::cout << Color::BrightMagenta;
		std::cout << " - " << item.GetName() << "\n";
		std::cout << Color::Reset;
	}
}

void GameActions::CheckStats(Player& player, Asylum& asylum, bool& canInteract)
{
	Helper::ClearConsol();

	RefreshView(player, asylum, canInteract);

	std::cout << Color::BrightYellow << "\n--- Stats ---" << Color::Reset << "\n";

	int sanity = player.GetSanity();
	std::string sanityColor = (sanity <= 25) ? Color::Red : (sanity <= 60) ? Color::Yellow : Color::Green;
	std::cout << Color::BrightMagenta;
	std::cout << "Sanity: " << sanityColor << sanity << Color::Reset << "\n";
}

void GameActions::Interact(Player& player, Asylum& asylum, bool& canInteract, bool& running)
{
	Room& room = asylum.GetRoom(player.GetRow(), player.GetCol());

	if (!room.HasItems())
	{
		std::cout << Color::BrightCyan;
		std::cout << "\nThere's nothing left to interact with here.\n";
		std::cout << Color::Reset;
		canInteract = false;
		return;
	}

	std::vector<Item>& items = room.GetItems();
	std::cout << Color::BrightCyan;
	std::cout << "\nWhich item would you like to interact with?\n";
	std::cout << Color::Gray;
	std::cout << "0: Cancel\n";
	for (size_t i = 0; i < items.size(); i++)
	{
		std::cout << (i + 1) << ": " << items[i].GetName() << "\n";
	}
	

	int choice = Helper::GetValidIndex(static_cast<int>(items.size()) + 1);
	std::cout << Color::Reset;
	Helper::ClearConsol();

	if (choice == 0)
	{
		RefreshView(player, asylum, canInteract);
		std::cout << Color::BrightYellow;
		std::cout << "\nNever mind.\n";
		std::cout << Color::Reset;
		return;
	}

	int index = choice - 1;
	Item chosen = items[index];

	if (chosen.GetName() == "Front Door")
	{
		if (!player.HasItem("Rusted Key"))
		{
			RefreshView(player, asylum, canInteract);
			std::cout << Color::BrightRed;
			std::cout << "\nThe door is locked shut. Despite your best efforts to\n";
			std::cout << "open it, the door does not budge.\n";
			std::cout << Color::Reset;
			return;
		}

		if (GameEndings::CheckDoorEnding(player, asylum))
			running = false;

		return;
	}

	player.AddItem(chosen);

	RefreshView(player, asylum, canInteract);

	std::cout << Color::BrightYellow;
	std::cout << "\nYou picked up: " << chosen.GetName() << "\n";
	std::cout << Color::BrightMagenta;
	std::cout << chosen.GetDescription() << "\n";
	std::cout << Color::Reset;

	if (chosen.GetEffect() == ItemEffect::SanityBoost)
	{
		player.SetSanity(player.GetSanity() + chosen.GetValue());
		std::cout << Color::Green;
		std::cout << "Your sanity improves slightly. (+" << chosen.GetValue() << " Sanity)\n";
		std::cout << Color::Reset;
	}
	else if (chosen.GetEffect() == ItemEffect::SanityDrain)
	{
		player.SetSanity(player.GetSanity() - chosen.GetValue());

		if (chosen.GetName() == "Scalpel")
		{
			std::cout << Color::BrightRed;
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
			std::cout << Color::Reset;
		}
		else
		{
			std::cout << Color::BrightRed;
			std::cout << "Reading it leaves you shaken.\n";
			std::cout << Color::Reset;
		}

		std::cout << Color::Red;
		std::cout << "(-" << chosen.GetValue() << " Sanity)\n";
		std::cout << Color::Reset;
	}

	room.RemoveItem(chosen.GetName());

	canInteract = room.HasItems();
}