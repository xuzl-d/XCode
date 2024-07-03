#pragma once

#include <functional>
#include <thread>
#include <vector>


class MultiThreadUtil
{
public:
	template<class T>
	static void MultiThread(const std::vector<T>& vals, std::function<std::thread(const std::vector<T>&)> fun)
	{
		if (vals.empty())
		{
			return;
		}
		size_t size = vals.size();
		const size_t threadCnt = std::thread::hardware_concurrency() > 0 && std::thread::hardware_concurrency() < size ?
			std::thread::hardware_concurrency() : size;
		const size_t nStep = size / threadCnt;
		size_t remainder = size - nStep * threadCnt;
		auto startIter = vals.begin();
		std::vector<std::thread> threads;
		for (size_t i = 0; i < threadCnt; i++)
		{
			size_t countTemp = nStep;
			if (remainder > 0)
			{
				countTemp += 1;
				remainder--;
			}
			std::vector<T> valsInThread(startIter, startIter + countTemp);
			threads.emplace_back(fun(valsInThread));
			startIter = startIter + countTemp;
		}
		for (auto& thread : threads)
		{
			thread.join();
		}
	}
};



