#pragma once
#include "../Utility/CommonUtil.h"

namespace SALibrary
{
	template<typename T>
	class QuickSort
	{
	public:
		static void Execute(T collections[], int size, bool isPrint = false)
		{
			Sort(collections, 0, size - 1);

			if (isPrint)
				PrintCollections(collections, size);
		}

		static void Sort(T collections[], int left, int right)
		{
			if (left > right)
				return;

			int pivot = Partition(collections, left, right);

			Sort(collections, left, pivot - 1);
			Sort(collections, pivot + 1, right);
		}

		static int Partition(T collections[], int left, int right)
		{
			T pivot = collections[left];
			int low = left + 1;
			int high = right;

			while (low <= high)
			{
				while (pivot >= collections[low] && low <= right)
					++low;
				while (pivot <= collections[high] && high >= (left + 1))
					--high;

				if (low <= high)
					Swap(collections[low], collections[high]);
			}


			Swap(collections[left], collections[high]);
			return high;
		}

	};
}
