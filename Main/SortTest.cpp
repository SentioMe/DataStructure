#include "stdafx.h"
#include "SortTest.h"


SortTest::SortTest(void)
{
}


SortTest::~SortTest(void)
{
}

void SortTest::Test(void)
{
	srand(time(NULL));

	int datas1[COUNT];
	int datas2[COUNT];
	int datas3[COUNT];
	for (int i = 0; i < COUNT; ++i)
	{
		int value = rand() % COUNT;
		datas1[i] = value;
		datas2[i] = value;
		datas3[i] = value;
	}

	SALibrary::Stopwatch stopwatch;

	stopwatch.Start();
	SALibrary::BubbleSort<int>::Execute(datas1, COUNT, false);
	std::cout << "BubbleSort : ";
	stopwatch.Record(true);

	stopwatch.Start();
	SALibrary::MergeSort<int>::Execute(datas2, COUNT, false);
	std::cout << "MergeSort : ";
	stopwatch.Record(true);

	stopwatch.Start();
	SALibrary::QuickSort<int>::Execute(datas3, COUNT, false);
	std::cout << "QuickSort : ";
	stopwatch.Record(true);

	int A[] = { 5, 10, 18, 7, 8, 3 };
	SALibrary::QuickSort<int>::Execute(A, 6, true);
}
