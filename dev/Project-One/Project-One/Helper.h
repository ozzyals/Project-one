#pragma once

#include <iostream>
#include <cctype>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <string>

namespace Color
{
	const std::string Reset = "\033[0m";

	// Standard colors
	const std::string Black = "\033[30m";
	const std::string Red = "\033[31m";
	const std::string Green = "\033[32m";
	const std::string Yellow = "\033[33m";
	const std::string Blue = "\033[34m";
	const std::string Magenta = "\033[35m";
	const std::string Cyan = "\033[36m";
	const std::string White = "\033[37m";
	const std::string Gray = "\033[90m";

	// Bright/bold variants
	const std::string BrightRed = "\033[91m";
	const std::string BrightGreen = "\033[92m";
	const std::string BrightYellow = "\033[93m";
	const std::string BrightBlue = "\033[94m";
	const std::string BrightMagenta = "\033[95m";
	const std::string BrightCyan = "\033[96m";
	const std::string BrightWhite = "\033[97m";

	// Text styles (combine with a color, e.g. Bold + Red)
	const std::string Bold = "\033[1m";
	const std::string Underline = "\033[4m";
	const std::string Dim = "\033[2m";
}

namespace Helper {
	
	static bool IsInteger(const char* input) {
		if (input == nullptr || input[0] == '\0')
			return false;

		int i = 0;

		if (input[0] == '+' || input[0] == '-')
			i = 1;

		if (input[i] == '\0')
			return false;

		for (; input[i] != '\0'; i++) {
			if (!std::isdigit(static_cast<unsigned char>(input[i])))
				return false;
		}
		return true;
	}

	static void PrintIntegerBinary(int* num) {
		if (num == nullptr)
			return;

		unsigned int value = static_cast<unsigned int>(*num);

		unsigned int bitmask = 1u << 31;

		for (int bitPosition = 31; bitPosition >= 0; bitPosition--) {
			std::cout << ((value & bitmask) ? '1' : '0');
			bitmask >>= 1;
		}
		std::cout << std::endl;
	}

	static void BubbleSort(int* arr, int size) {
		if (arr == nullptr || size <= 1)
			return;

		for (int i = 0; i < size - 1; i++) {
			for (int j = 0; j < size - 1 - i; j++) {
				if (arr[j] > arr[j + 1]) {
					std::swap(arr[j], arr[j + 1]);
				}
			}
		}
	}

	static void ClearConsol() {
		system("cls");
	}

	static int VectorSum(const std::vector<int>& vect) {
		int sum = 0;
		for (int i = 0; i < vect.size(); i++) {
			sum += vect[i];
		}
		return sum;
	}

	static int GetMenuChoice(const std::vector<int>& validChoices) {
		std::string input;
		int value = 0;
		bool valid = false;

		while (!valid)
		{
			std::cin >> input;

			if (IsInteger(input.c_str()))
			{
				value = std::stoi(input);

				for (int choice : validChoices)
				{
					if (choice == value)
					{
						valid = true;
						break;
					}
				}
			}

			if (!valid)
				std::cout << "Invalid choice, please try again: ";
		}

		return value;
	}

	static int GetValidIndex(int max) {
		std::string input;
		int value = 0;
		bool valid = false;

		while (!valid)
		{
			std::cout << "Enter an index (0 to " << max - 1 << "): ";
			std::getline(std::cin, input);

			if (IsInteger(input.c_str()))
			{
				value = std::stoi(input);

				if (value >= 0 && value < max)
				{
					valid = true;
				}
				else
				{
					std::cout << "Index out of range.\n";
				}
			}
			else
			{
				std::cout << "That's not a valid integer.\n";
			}
		}

		return value;
	}





}

