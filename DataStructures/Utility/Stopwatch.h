#pragma once
#include "CommonUtil.h"
#include <ctime>
#include <vector>

namespace SALibrary
{
	class Stopwatch
	{
		typedef std::vector<std::clock_t> RecordVector;
	private:
		std::clock_t _startTime;
		RecordVector _recordVector;

	public:
		void Start()
		{
			_startTime = std::clock();
			_recordVector.clear();
		}

		double Record(bool isPrint)
		{
			std::clock_t recordTime = std::clock();
			_recordVector.push_back(recordTime);
			
			double durationFromStart = (recordTime - _startTime) / (double)CLOCKS_PER_SEC;
			if (isPrint)
			{
				std::cout << "Record [" << _recordVector.size() - 1 << "] = " << durationFromStart << std::endl;
			}
			
			return durationFromStart;
		}
	};
}