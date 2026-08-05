#pragma once

#include <iostream>
#include <cctype>
#include <algorithm>
#include <vector>
#include <cstdlib>
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


}