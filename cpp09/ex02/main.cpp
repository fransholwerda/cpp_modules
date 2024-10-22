#include <iostream>
#include <vector>
#include <deque>
#include <stdlib.h>
#include <algorithm>
#include <chrono>
#include <set>

int g_comparisons = 0;

// Jacobsthal sequence
size_t jacobsthal(size_t n)
{
	if ( n <= 1)
		return (n);
	return (jacobsthal(n - 1) + 2 * jacobsthal(n - 2));
}

// Returns true if a > b, else false
bool compare(const int& a, const int& b)
{
	++g_comparisons;
	return (a > b);
}

// Returns a combined array of array a and b (in that order)
std::vector<int> vec_merge(std::vector<int> a, const std::vector<int> b)
{
	for (int i : b)
		a.push_back(i);
	return (a);
}

// Returns the first half of the given array
std::vector<int> vec_split_arr_first_half(const std::vector<int>& arr)
{
	std::vector<int> result;

	for (size_t i = 0; i < arr.size() / 2; ++i)
		result.push_back(arr[i]);

	return (result);
}

// Returns the second half of the given array
std::vector<int> vec_split_arr_second_half(const std::vector<int>& arr)
{
	std::vector<int> result;

	for (size_t i = 0; i < arr.size() / 2; ++i)
		result.push_back(arr[i]);

	return (result);
}

void insertion_sort(std::vector<std::vector<int>>& sort_from, std::vector<std::vector<int>>& sort_to, std::vector<int> straggler = {})
{

}

// Recursively pairs up the given array using merge insertion sort
std::vector<std::vector<int>> vec_merge_insertion(std::vector<std::vector<int>> paired_arr)
{
	std::vector<std::vector<int>> deeper_paired_arr;

	for (size_t i = 0; i + 1 < paired_arr.size(); i += 2)
	{
		if (compare(paired_arr[i][0], paired_arr[i + 1][0]))
			deeper_paired_arr.push_back(vec_merge(paired_arr[i], paired_arr[i + 1]));
		else
			deeper_paired_arr.push_back(vec_merge(paired_arr[i + 1], paired_arr[i]));
	}

	if (deeper_paired_arr.size() > 1)
		deeper_paired_arr = vec_merge_insertion(deeper_paired_arr);
	
	#ifdef DEBUG
	std::cout << "S(" << paired_arr.size() << ")" << std::endl;
	std::cout << "comparisons: " << g_comparisons << std::endl;
	for (auto i : paired_arr)
	{
		std::cout << "{";
		for (auto j : i)
			std::cout << j << " ";
		std::cout << "}";
	}
	std::cout << std::endl;
	#endif

	std::vector<std::vector<int>> result;

	result.push_back(vec_split_arr_first_half(deeper_paired_arr[0]));
	result.push_back(vec_split_arr_second_half(deeper_paired_arr[0]));

	if (paired_arr.size() % 2 != 0)
		insertion_sort(deeper_paired_arr, result, paired_arr.back());
	else
		insertion_sort(deeper_paired_arr, result);

	return (result);
}

// Prepares the array so it can be recursively sorted by merge insertion
std::vector<int> vec_fjmi(std::vector<int> arr)
{
	std::vector<std::vector<int>> paired_arr;
	std::vector<int> result;

	for (size_t i = 0; i + 1 < arr.size(); i += 1)
		paired_arr.push_back(std::vector<int>{arr[i]});

	paired_arr =  vec_merge_insertion(paired_arr);
	
	return (result);
}

int main(int argc, char *argv[])
{
	std::vector<int>	vec;
	std::deque<int>		deq;
	std::set<int>		dupcheck;

	if (argc < 3)
	{
		std::cout << "Provide at least 2 unique integers." << std::endl;
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
	if (vec.size() <= 50)
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
	vec = vec_fjmi(vec);
	std::chrono::_V2::system_clock::time_point end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double, std::micro> vec_elapsed = end - start;

	start = std::chrono::high_resolution_clock::now();
	// deq = ford_johnson<std::deque, int, int>(deq);
	end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double, std::micro> deq_elapsed = end - start;

	std::cout << "After: ";
	if (vec.size() <= 50)
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
