#include "Room.h"

Room::Room()
{
	name = "Empty Room";
	description = "";
	explored = false;
	blocked = false;
}

Room::Room(const std::string& _name, const std::string& _description)
{
	name = _name;
	description = _description;
	explored = false;
	blocked = false;
}

bool Room::IsBlocked() const
{
	return blocked;
}

void Room::SetBlocked(bool _blocked)
{
	blocked = _blocked;
}

std::string Room::GetName() const
{
	return name;
}

std::string Room::GetDescription() const
{
	return description;
}

std::vector<Item>& Room::GetItems()
{
	return items;
}

bool Room::IsExplored() const
{
	return explored;
}

void Room::SetExplored(bool _explored)
{
	explored = _explored;
}

void Room::AddItem(const Item& item)
{
	items.push_back(item);
}

void Room::RemoveItem(const std::string& itemName)
{
	for (size_t i = 0; i < items.size(); i++)
	{
		if (items[i].GetName() == itemName)
		{
			items.erase(items.begin() + i);
			return;
		}
	}
}

bool Room::HasItems() const
{
	return !items.empty();
}