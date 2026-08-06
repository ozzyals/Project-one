#include "Player.h"

Player::Player()
{
	name = "Player";
	health = 100;
	sanity = 100;
	row = 0;
	col = 0;
}

Player::Player(const std::string& _name, int _health, int _sanity)
{
	name = _name;
	health = _health;
	sanity = _sanity;
	row = 0;
	col = 0;
}

std::string Player::GetName() const
{
	return name;
}

int Player::GetHealth() const
{
	return health;
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

void Player::SetHealth(int _health)
{
	health = (_health < 0) ? 0 : _health;
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