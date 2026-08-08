#include "Player.h"

Player::Player()
{
	name = "Player";
	sanity = 100;
	row = 0;
	col = 0;
}

Player::Player(const std::string& _name, int _sanity)
{
	name = _name;
	sanity = _sanity;
	row = 0;
	col = 0;
}

std::string Player::GetName() const
{
	return name;
}

int Player::GetSanity() const
{
	return sanity;
}

int Player::GetRow() const
{
	return row;
}

int Player::GetCol() const
{
	return col;
}

std::vector<Item>& Player::GetInventory()
{
	return inventory;
}

void Player::SetSanity(int _sanity)
{
	sanity = (_sanity < 0) ? 0 : _sanity;
}

void Player::SetPosition(int _row, int _col)
{
	row = _row;
	col = _col;
}

void Player::AddItem(const Item& item)
{
	inventory.push_back(item);
}