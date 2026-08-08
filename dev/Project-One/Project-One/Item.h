#pragma once

#include <string>

enum class ItemEffect
{
	None,
	Heal,
	SanityBoost,
	SanityDrain,
	Key
};

class Item
{
public:
	Item();
	Item(const std::string& _name, const std::string& _description, ItemEffect _effect, int _value);

	std::string GetName() const;
	std::string GetDescription() const;
	ItemEffect GetEffect() const;
	int GetValue() const;

private:
	std::string name;
	std::string description;
	ItemEffect effect;
	int value;
};
