#pragma once

//Is not completed
namespace SALibrary
{
	template<class T>
	__interface IEnumerator
	{
		T Current(void);
		void MoveNext(void);
	};

	template<class T>
	__interface IEnumrable
	{
		const IEnumerator<T>* GetEnumerator(void);
	};
}