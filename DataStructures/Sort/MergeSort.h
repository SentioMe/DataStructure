#pragma once
#include "../Utility/CommonUtil.h"

namespace SALibrary
{
	template<typename T>
	class MergeSort
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
			if (left >= right)
				return;

			int mid = (left + right) / 2;

			Sort(collections, left, mid);
			Sort(collections, mid + 1, right);

			Merge(collections, left, mid, right);
		}

		static void Merge(T collections[], int left, int mid, int right)
		{
			int leftStart = left;
			int leftEnd = mid;

			int rightStart = mid + 1;
			int rightEnd = right;

			int index = 0;

			T* sortedArray = (T*)malloc(sizeof(T) * (right + 1));
			int sortedIndex = left;

			while ((leftStart <= leftEnd) && (rightStart <= rightEnd))
			{
				if (collections[leftStart] > collections[rightStart])
					sortedArray[sortedIndex] = collections[rightStart++];
				else
					sortedArray[sortedIndex] = collections[leftStart++];

				sortedIndex++;
			}

			if (leftStart > leftEnd)
			{
				for (index = rightStart; index <= rightEnd; ++index)
					sortedArray[sortedIndex++] = collections[index];
			}
			else
			{
				for (index = leftStart; index <= leftEnd; ++index)
					sortedArray[sortedIndex++] = collections[index];
			}

			for (index = left; index <= right; ++index)
				collections[index] = sortedArray[index];


			free(sortedArray);
		}
	};
}
