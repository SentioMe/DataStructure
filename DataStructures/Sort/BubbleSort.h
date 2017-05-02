#pragma once
#include "../Utility/CommonUtil.h"

namespace SALibrary
{
	template<typename T>
	class BubbleSort
	{
	public:
		static void Execute(T collections[], int size, bool isPrint = false)
		{
			for (int i = 0; i < size; ++i)
			{
				for (int j = 0; j < (size - i) - 1; ++j)
				{
					if (collections[j] > collections[j + 1])
						Swap(collections[j], collections[j + 1]);
				}
			}


			if (isPrint)
				PrintCollections(collections, size);
		}
	};
}
