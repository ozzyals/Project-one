#pragma once

#include <string>
#include <vector>
#include "Item.h"

class Room
{
public:
	Room();
	Room(const std::string& _name, const std::string& _description);

	std::string GetName() const;
	std::string GetDescription() const;
	std::vector<Item>& GetItems();
	bool IsExplored() const;

	bool IsBlocked() const;
	void SetBlocked(bool _blocked);

	void SetExplored(bool _explored);
	void AddItem(const Item& item);
	void RemoveItem(const std::string& itemName);
	bool HasItems() const;

private:
	std::string name;
	std::string description;
	std::vector<Item> items;
	bool explored;
	bool blocked;
};