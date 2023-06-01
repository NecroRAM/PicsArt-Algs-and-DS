#include "D:\Downloads\Courses\Algs and Data Structs\PicsArt Academy\PicsArt-Algs-and-DS\Homework\Sorting Algs\Slow Sort.cpp"
#include "D:\Downloads\Courses\Algs and Data Structs\PicsArt Academy\PicsArt-Algs-and-DS\Homework\Sorting Algs\Selection Sort.cpp"
#include "D:\Downloads\Courses\Algs and Data Structs\PicsArt Academy\PicsArt-Algs-and-DS\Homework\Sorting Algs\Insertion Sort.cpp"
#include "D:\Downloads\Courses\Algs and Data Structs\PicsArt Academy\PicsArt-Algs-and-DS\Homework\Sorting Algs\Merge Sort.cpp"
#include "D:\Downloads\Courses\Algs and Data Structs\PicsArt Academy\PicsArt-Algs-and-DS\Homework\Sorting Algs\Quick Sort.cpp"
#include <iostream>
#include <vector>
#include <chrono>

class Timer
{
public:
	Timer()
	{
		m_StartTimepoint = std::chrono::high_resolution_clock::now();
	}

	~Timer()
	{
		Stop();
	}

	void Stop()
	{
		auto m_EndTimepoint = std::chrono::high_resolution_clock::now();

		double start = std::chrono::time_point_cast<std::chrono::nanoseconds>(m_StartTimepoint).time_since_epoch().count();
		double end = std::chrono::time_point_cast<std::chrono::nanoseconds>(m_EndTimepoint).time_since_epoch().count();

		double duration = end - start;
		double us = duration * 0.001;
		double ms = us * 0.001;
		double s = ms * 0.001;

		std::cout << duration << "ns (" << us << "us) (" << ms << "ms) (" << s << "s)" << std::endl;
	}
private:
	std::chrono::time_point<std::chrono::high_resolution_clock> m_StartTimepoint;
};

void bench(std::vector<int>& v1, int n)
{
	if (!v1.size())
	{
		std::cout << "array is empty" << std::endl;
		return;
	}
	for (int i = 0; i < v1.size() - 1; ++i)
		v1[i] = rand();
	std::vector<int> v2(n), v3(n), v4(n), v5(n), v6(n);
	v2 = v3 = v4 = v5 = v1;
	{
		std::cout << "Slow:" << std::endl;
		Timer timer;
		slowSort(v6);
	}
	{
		std::cout << "Selection:" << std::endl;
		Timer timer;
		selectionSort(v1);
	}
	{
		std::cout << "Insertion:" << std::endl;
		Timer timer;
		insertionSort(v2);
	}
	{
		std::cout << "Merge:" << std::endl;
		Timer timer;
		mergeSort(v3);
	}
	{
		std::cout << "Quick:" << std::endl;
		Timer timer;
		quickSort(v4);
	}
	{
		std::cout << "std::sort:" << std::endl;
		Timer timer;
		std::sort(v5.begin(), v5.end());
	}
}

int main()
{
	int n = 300;
	std::vector<int> v(n);
	bench(v, n);
}