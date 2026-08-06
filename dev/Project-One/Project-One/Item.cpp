#include "Item.h"

Item::Item()
{
	name = "";
	description = "";
	effect = ItemEffect::None;
	value = 0;
}

Item::Item(const std::string& _name, const std::string& _description, ItemEffect _effect, int _value)
{
	name = _name;
	description = _description;
	effect = _effect;
	value = _value;
}

std::string Item::GetName() const
{
	return name;
}

std::string Item::GetDescription() const
{
	return description;
}

ItemEffect Item::GetEffect() const
{
	return effect;
}

int Item::GetValue() const
{
	return value;
}