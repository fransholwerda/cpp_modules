#include <iostream>
#include <vector>
#include <deque>
#include <stdlib.h>
#include <algorithm>
#include <chrono>
#include <set>

long long Jacobsthal(long long n)
{
	if (n == 0)
		return 0;

	if (n == 1)
		return 1;

	return Jacobsthal(n - 1) + 2 * Jacobsthal(n - 2);
}

template<class T>
struct Compare {
	const T& c;
	Compare(const T& set) : c(set) {}
	bool operator()(int a, int b) { return c[a] < c[b]; }
};

template<class T>
int select_median(T& vec, const std::vector<int>& medians)
{
	std::vector<int> temp = medians;
	std::sort(temp.begin(), temp.end(), Compare<T>(vec));
	return (temp[temp.size() / 2]);
}

template <class T>
static int partition(T& vec, int start, int end, int pivotIndex)
{
	std::swap(vec[pivotIndex], vec[end]);
	int storeIndex = start;
	for (int i = start; i < end; i++)
	{
		if (vec[i] < vec[end])
		{
			std::swap(vec[i], vec[storeIndex]);
			storeIndex++;
		}
	}
	std::swap(vec[storeIndex], vec[end]);
	return storeIndex;
}

template<class T>
void merge_insertion_sort(T& vec, int start, int end)
{
	if (start >= end)
		return ;
	if (end - start == 1)
	{
		if (vec[start] > vec[end])
			std::swap(vec[start], vec[end]);
		return ;
	}

	std::vector<int> medians;
	for (int i = start; i < end; i += 2)
	{
		if (vec[i] > vec[i + 1])
			std::swap(vec[i], vec[i + 1]);
		medians.push_back(i + 1);
	}

	if ((end - start) % 2 != 0)
		medians.push_back(end);

	int medianOfMedians = select_median(vec, medians);
	int mid = partition(vec, start, end, medianOfMedians);
	merge_insertion_sort(vec, start, mid - 1);
	merge_insertion_sort(vec, mid, end);
}

int main(int argc, char *argv[])
{
	std::vector<int>	vec;
	std::deque<int>		deq;
	std::set<int>		dupcheck;

	if (argc < 3)
	{
		std::cout << "Give at least 2 unique integers." << std::endl;
		return (EXIT_FAILURE);
	}

	for (int i = 1; i < argc; i++)
	{
		int number = atoi(argv[i]);
		if (dupcheck.find(number) != dupcheck.end())
		{
			std::cout << "Please provide unique integers." << std::endl;
			return (EXIT_FAILURE);
		}
		dupcheck.insert(number);
		vec.push_back(number);
		deq.push_back(number);
	}

	std::cout << "Before: ";
	if (vec.size() <= 5)
	{
		for (size_t i = 0; i < vec.size(); i++)
			std::cout << vec[i] << " ";
	}
	else
	{
		for (size_t i = 0; i < 4; i++)
			std::cout << vec[i] << " ";
		std::cout << "[...]";
	}
	std::cout << std::endl;

	std::chrono::_V2::system_clock::time_point start = std::chrono::high_resolution_clock::now();
	merge_insertion_sort(vec, 0, vec.size() - 1);
	std::chrono::_V2::system_clock::time_point end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double, std::micro> vec_elapsed = end - start;

	start = std::chrono::high_resolution_clock::now();
	merge_insertion_sort(deq, 0, deq.size() - 1);
	end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double, std::micro> deq_elapsed = end - start;

	std::cout << "After:  ";
	if (vec.size() <= 5)
	{
		for (size_t i = 0; i < vec.size(); i++)
			std::cout << vec[i] << " ";
	}
	else
	{
		for (size_t i = 0; i < 4; i++)
			std::cout << vec[i] << " ";
		std::cout << "[...]";
	}
	std::cout << std::endl;
	std::cout << "Time to process a range of " << vec.size() << " elements with std::vector : " << vec_elapsed.count() << " μs" << std::endl;
	std::cout << "Time to process a range of " << vec.size() << " elements with std::deque  : " << deq_elapsed.count() << " μs" << std::endl;
	return (EXIT_SUCCESS);
}
