#pragma once

#include <string>
#include <vector>
#include "Item.h"

class Player
{
public:
	Player();
	Player(const std::string& _name, int _sanity);
	bool HasItem(const std::string& itemName) const;

	std::string GetName() const;
	int GetSanity() const;
	int GetRow() const;
	int GetCol() const;
	std::vector<Item>& GetInventory();

	void SetSanity(int _sanity);
	void SetPosition(int _row, int _col);
	void AddItem(const Item& item);

private:
	std::string name;
	int sanity;
	int row;
	int col;
	std::vector<Item> inventory;
};
