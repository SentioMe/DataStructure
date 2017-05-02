#pragma once

#include <iostream>

namespace SALibrary
{

	template<typename T>
	static void Swap(T& a, T& b)
	{
		T temp = a;
		a = b;
		b = temp;
	}

	template<typename T>
	static void PrintCollections(T collections[], int size)
	{
		for (int i = 0; i < size; ++i)
			std::cout << "Element[" << i << "] = " << collections[i] << std::endl;
	}

	static int Min(int a, int b) { return a > b ? a : b; }
}