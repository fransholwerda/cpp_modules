#include <iostream>
#include <vector>
#include <deque>
#include <stdlib.h>
#include <algorithm>
#include <chrono>
#include <set>

size_t g_comparisons = 0;

size_t jacobsthal(size_t n)
{
	if ( n <= 1)
		return (n);
	return (jacobsthal(n - 1) + 2 * jacobsthal(n - 2));
}

void vec_pair_sort(std::vector<int>& arr)
{
	for (size_t i = 1; i < arr.size(); i += 2)
	{
		++g_comparisons;
		if (arr[i - 1] > arr[i])
		{
			int temp = arr[i - 1];
			arr[i - 1] = arr[i];
			arr[i] = temp;
		}
	}
}

int vec_binary_search(std::vector<int>& arr, int item)
{
	int left = 0;
	int right = arr.size();

	while (left < right)
	{
		int mid = (left + right) / 2;

		++g_comparisons;
		if (arr[mid] < item)
			left = mid + 1;
		else
			right = mid;
	}

	return (left);
}

int findInsertPosition(const std::vector<int>& arr, int new_num, int end_index) {
	int low = 0, high = end_index;

	while (low <= high) {
		int mid = low + (high - low) / 2;
		++g_comparisons;
		if (arr[mid] < new_num) {
			low = mid + 1;
		} else {
			high = mid - 1;
		}
	}

	return low;
}

void vec_blabla(std::vector<int>& arr, std::vector<int>& a_arr, std::vector<int>& b_arr)
{
	for (size_t i = 1; i < arr.size(); i += 2)
	{
		int num = arr[i];
		int pos = vec_binary_search(a_arr, num);
		a_arr.insert(a_arr.begin() + pos, num);
		b_arr.push_back(arr[i - 1]);
	}
	if (arr.size() % 2 == 1)
		b_arr.push_back(arr[arr.size() - 1]);
	a_arr.insert(a_arr.begin() + 0, b_arr[0]);

	#ifdef DEBUG
	std::cout << "a_array: ";
	for (int i : a_arr)
		std::cout << i << " ";
	std::cout << std::endl;

	std::cout << "b_array: ";
	for (int i : b_arr)
		std::cout << i << " ";
	std::cout << std::endl;
	#endif
}

void merge(std::vector<int>& arr, int left, int mid, int right) {
	std::vector<int> leftArr(arr.begin() + left, arr.begin() + mid + 1);
	std::vector<int> rightArr(arr.begin() + mid + 1, arr.begin() + right + 1);

	size_t i = 0;
	size_t j = 0;
	size_t k = left;

	while (i < leftArr.size() && j < rightArr.size()) {
		++g_comparisons;
		if (leftArr[i] <= rightArr[j]) {
			arr[k++] = leftArr[i++];
		} else {
			arr[k++] = rightArr[j++];
		}
	}

	while (i < leftArr.size()) {
		arr[k++] = leftArr[i++];
	}

	while (j < rightArr.size()) {
		arr[k++] = rightArr[j++];
	}
}

void vec_jacob(std::vector<int>& a_arr, std::vector<int>& b_arr, int final_len)
{
	int prev_jacob = 1;
	int cur_jacob = 3;
	int jacob_cursor = 3;
	int main_chain_len = 3;

	while (main_chain_len < final_len)
	{
		int reference_index = main_chain_len - 1;
		int cursor = cur_jacob - 1;
		while (cursor > prev_jacob - 1)
		{
			int num = b_arr[cursor];
			if (main_chain_len <= 5)
				merge(a_arr, 0, reference_index / 2, reference_index);
			else
			{
				int pos = findInsertPosition(a_arr, num, reference_index);
				if (pos <= reference_index)
					++reference_index;
				a_arr.insert(a_arr.begin() + pos, num);
			}
			#ifdef DEBUG
			std::cout << "comparisons: " << g_comparisons << ", prev_jacob-cur_jacob: " << prev_jacob << "-" << cur_jacob << ", cursor: " << cursor << ", main_chain_len: " << main_chain_len << std::endl;
			#endif
			++main_chain_len;
			--cursor;
		}
		main_chain_len += (cur_jacob - prev_jacob);
		prev_jacob = cur_jacob;
		++jacob_cursor;
		cur_jacob = jacobsthal(jacob_cursor);
	}
}

std::vector<int> vec_fjmi(std::vector<int> arr)
{
	std::vector<int> a_arr;
	std::vector<int> b_arr;

	vec_pair_sort(arr);

	#ifdef DEBUG
	std::cout << "comparisons: " << g_comparisons << std::endl;
	#endif

	vec_blabla(arr, a_arr, b_arr);

	#ifdef DEBUG
	std::cout << "comparisons: " << g_comparisons << std::endl;
	#endif

	vec_jacob(a_arr, b_arr, arr.size());

	#ifdef DEBUG
	std::cout << "a_array: ";
	for (int i : a_arr)
		std::cout << i << " ";
	std::cout << std::endl;
	#endif

	return (a_arr);
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
	vec = vec_fjmi(vec);
	std::chrono::_V2::system_clock::time_point end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double, std::micro> vec_elapsed = end - start;

	start = std::chrono::high_resolution_clock::now();
	// deq = deq_merge_insertion_sort(deq);
	end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double, std::micro> deq_elapsed = end - start;

	std::cout << "After: ";
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
