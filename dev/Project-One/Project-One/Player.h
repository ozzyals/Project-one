#pragma once

#include <string>
#include <vector>
#include "Item.h"

class Player
{
public:
	Player();
	Player(const std::string& _name, int _health, int _sanity);

	std::string GetName() const;
	int GetHealth() const;
	int GetSanity() const;
	int GetRow() const;
	int GetCol() const;
	std::vector<Item>& GetInventory();

	void SetHealth(int _health);
	void SetSanity(int _sanity);
	void SetPosition(int _row, int _col);
	void AddItem(const Item& item);

private:
	std::string name;
	int health;
	int sanity;
	int row;
	int col;
	std::vector<Item> inventory;
};
