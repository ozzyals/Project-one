#pragma once

#include "Player.h"
#include "Asylum.h"

class GameEndings
{
public:
	static bool CheckSanityLoss(Player& player);
	static bool CheckDoorEnding(Player& player, Asylum& asylum);

private:
	static void PrintLossEnding();
	static void PrintFalseEnding();
	static void PrintTrueEnding();
};