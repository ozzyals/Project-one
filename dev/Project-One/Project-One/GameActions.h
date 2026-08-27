#pragma once

#include "Player.h"
#include "Asylum.h"

class GameActions
{
public:
	static void Move(Player& player, Asylum& asylum, char direction, bool& canInteract, bool& running);
	static void CheckInventory(Player& player, Asylum& asylum, bool& canInteract);
	static void CheckStats(Player& player, Asylum& asylum, bool& canInteract);
	static void Interact(Player& player, Asylum& asylum, bool& canInteract, bool& running);
	static void RefreshView(Player& player, Asylum& asylum, bool& canInteract);

private:
	static void UpdateRoomState(Player& player, Asylum& asylum, bool& canInteract);
	static void LookAround(Player& player, Asylum& asylum, bool& canInteract);
	
};