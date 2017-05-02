#include "stdafx.h"
#include "CollectionsTest.h"


CollectionsTest::CollectionsTest(void)
{
}


CollectionsTest::~CollectionsTest(void)
{
}

void CollectionsTest::Test(void)
{
	SALibrary::LinkedList<int> list;
	
	auto cbInput = [](void)->int{
		printf("값을 입력해주세요 : ");
		int value = 0;
		scanf("%d", &value);

		return value;
	};

	SELECT select = AddFirst;

	while (select != End)
	{
		system("cls");

		printf("======================================================\n");
		printf("=0 : AddF, 1 : AddL, 2 : Remove, 3 : Print, 4 : Exit =\n");
		printf("======================================================\n");

		scanf("%d", &select);

		switch (select)
		{
		case AddFirst:
			list.AddFirst(cbInput());
			break;
		case AddLast:
			list.AddLast(cbInput());
			break;
		case Remove:
			if (list.Remove(cbInput()))
				printf("값이 지워졌습니다\n");
			else
				printf("값이 없습니다\n");
			break;
		case Print:
			system("cls");
			list.Print();
			printf("\n");
			break;
		}

		printf("아무 키나 눌러주세요\n");
		getch();
	}
}
