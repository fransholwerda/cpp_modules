#include <iostream>
#include <vector>
#include <deque>
#include <stdlib.h>
#include <algorithm>
#include <chrono>
#include <set>

#ifdef DEBUG
int g_comparisons = 0;
#endif

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
	#ifdef DEBUG
	++g_comparisons;
	#endif
	return (a > b);
}

/* ---------------------------------- vector functions ---------------------------------- */

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

	for (size_t i = (arr.size() / 2); i < arr.size(); ++i)
		result.push_back(arr[i]);

	return (result);
}

// Finds the insert position recursively and then inserts it when it's found
void vec_insert(std::vector<std::vector<int>>& arr, std::vector<int> to_insert, size_t left, size_t right)
{
	if (left >= right)
	{
		arr.insert(arr.begin() + left, to_insert);
		return ;
	}
	
	size_t middle = (right - left) / 2 + left;
	if (compare(to_insert[0], arr[middle][0]))
		vec_insert(arr, to_insert, middle + 1, right);
	else
		vec_insert(arr, to_insert, left, middle);
}

// Helper function that performs the actual insertion sort based on Jacobsthal sequence
void insert_elements_in_order(
	std::vector<std::vector<int>>& source, 
	std::vector<std::vector<int>>& destination, 
	size_t last_index, 
	size_t current_jacob_value, 
	std::vector<int>& straggler)
{
	// First pass: insert first half of the arrays from the source to the destination
	for (size_t i = 0; current_jacob_value > last_index + i; i++) {
		if (last_index + i < source.size()) {
			destination.push_back(vec_split_arr_first_half(source[last_index + i]));
		}
	}

	size_t insert_pos = destination.size() - 1;

	// Second pass: insert second half and handle stragglers if needed
	for (size_t i = 1; current_jacob_value - i >= last_index; i++) {
		// Handle straggler if available and we've reached beyond the source size
		if (!straggler.empty() && current_jacob_value > source.size()) {
			vec_insert(destination, straggler, 0, destination.size());
			straggler.clear();
			insert_pos++;
		}

		// Insert second half of the array from the source
		if (current_jacob_value - i < source.size()) {
			vec_insert(destination, vec_split_arr_second_half(source[current_jacob_value - i]), 0, insert_pos);
		}
	}
}

// Main function that drives the insertion sort process using the Jacobsthal sequence
void jacobsthal_insertion_sort(
	std::vector<std::vector<int>>& source, 
	std::vector<std::vector<int>>& destination, 
	std::vector<int> straggler = {})
{
	size_t current_jacob_value;
	size_t last_jacob_value = 1;  // Starts from 1 to cover the first element
	size_t jacob_index = 3;       // Jacobsthal sequence starts from index 3

	// Continue sorting while there are elements left in the source or straggler exists
	while (last_jacob_value < source.size() || !straggler.empty()) {
		current_jacob_value = jacobsthal(jacob_index);  // Get the next Jacobsthal number

		// Sort elements using the current Jacobsthal sequence value
		insert_elements_in_order(source, destination, last_jacob_value, current_jacob_value, straggler);

		++jacob_index;  // Move to the next Jacobsthal index
		last_jacob_value = current_jacob_value;  // Update the last processed index
	}
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

	result.push_back(vec_split_arr_second_half(deeper_paired_arr[0]));
	result.push_back(vec_split_arr_first_half(deeper_paired_arr[0]));

	if (paired_arr.size() % 2 != 0)
		jacobsthal_insertion_sort(deeper_paired_arr, result, paired_arr.back());
	else
		jacobsthal_insertion_sort(deeper_paired_arr, result);
	
	#ifdef DEBUG
	std::cout << "comparisons: " << g_comparisons << std::endl;
	for (auto i : result)
	{
		std::cout << "{";
		for (auto j : i)
			std::cout << j << " ";
		std::cout << "}";
	}
	std::cout << std::endl;
	#endif

	return (result);
}

// Prepares the array so it can be recursively sorted by merge insertion
std::vector<int> vec_fjmi(std::vector<int> arr)
{
	std::vector<std::vector<int>> paired_arr;
	std::vector<int> result;

	for (size_t i = 0; i < arr.size(); ++i)
		paired_arr.push_back(std::vector<int>{arr[i]});

	paired_arr = vec_merge_insertion(paired_arr);
	for (std::vector<int> pair : paired_arr)
	{
		for (int num : pair)
			result.push_back(num);
	}
	return (result);
}

/* ---------------------------------- deque functions ---------------------------------- */

// Returns a combined array of array a and b (in that order)
std::deque<int> deq_merge(std::deque<int> a, const std::deque<int> b)
{
	for (int i : b)
		a.push_back(i);
	return (a);
}

// Returns the first half of the given array
std::deque<int> deq_split_arr_first_half(const std::deque<int>& arr)
{
	std::deque<int> result;

	for (size_t i = 0; i < arr.size() / 2; ++i)
		result.push_back(arr[i]);

	return (result);
}

// Returns the second half of the given array
std::deque<int> deq_split_arr_second_half(const std::deque<int>& arr)
{
	std::deque<int> result;

	for (size_t i = (arr.size() / 2); i < arr.size(); ++i)
		result.push_back(arr[i]);

	return (result);
}

// Finds the insert position recursively and then inserts it when it's found
void deq_insert(std::deque<std::deque<int>>& arr, std::deque<int> to_insert, size_t left, size_t right)
{
	if (left >= right)
	{
		arr.insert(arr.begin() + left, to_insert);
		return ;
	}
	
	size_t middle = (right - left) / 2 + left;
	if (compare(to_insert[0], arr[middle][0]))
		deq_insert(arr, to_insert, middle + 1, right);
	else
		deq_insert(arr, to_insert, left, middle);
}

// Helper function that performs the actual insertion sort based on Jacobsthal sequence
void insert_elements_in_order(
	std::deque<std::deque<int>>& source, 
	std::deque<std::deque<int>>& destination, 
	size_t last_index, 
	size_t current_jacob_value, 
	std::deque<int>& straggler)
{
	// First pass: insert first half of the arrays from the source to the destination
	for (size_t i = 0; current_jacob_value > last_index + i; i++) {
		if (last_index + i < source.size()) {
			destination.push_back(deq_split_arr_first_half(source[last_index + i]));
		}
	}

	size_t insert_pos = destination.size() - 1;

	// Second pass: insert second half and handle stragglers if needed
	for (size_t i = 1; current_jacob_value - i >= last_index; i++) {
		// Handle straggler if available and we've reached beyond the source size
		if (!straggler.empty() && current_jacob_value > source.size()) {
			deq_insert(destination, straggler, 0, destination.size());
			straggler.clear();
			insert_pos++;
		}

		// Insert second half of the array from the source
		if (current_jacob_value - i < source.size()) {
			deq_insert(destination, deq_split_arr_second_half(source[current_jacob_value - i]), 0, insert_pos);
		}
	}
}

// Main function that drives the insertion sort process using the Jacobsthal sequence
void jacobsthal_insertion_sort(
	std::deque<std::deque<int>>& source, 
	std::deque<std::deque<int>>& destination, 
	std::deque<int> straggler = {})
{
	size_t current_jacob_value;
	size_t last_jacob_value = 1;  // Starts from 1 to cover the first element
	size_t jacob_index = 3;       // Jacobsthal sequence starts from index 3

	// Continue sorting while there are elements left in the source or straggler exists
	while (last_jacob_value < source.size() || !straggler.empty()) {
		current_jacob_value = jacobsthal(jacob_index);  // Get the next Jacobsthal number

		// Sort elements using the current Jacobsthal sequence value
		insert_elements_in_order(source, destination, last_jacob_value, current_jacob_value, straggler);

		++jacob_index;  // Move to the next Jacobsthal index
		last_jacob_value = current_jacob_value;  // Update the last processed index
	}
}


// Recursively pairs up the given array using merge insertion sort
std::deque<std::deque<int>> deq_merge_insertion(std::deque<std::deque<int>> paired_arr)
{
	std::deque<std::deque<int>> deeper_paired_arr;

	for (size_t i = 0; i + 1 < paired_arr.size(); i += 2)
	{
		if (compare(paired_arr[i][0], paired_arr[i + 1][0]))
			deeper_paired_arr.push_back(deq_merge(paired_arr[i], paired_arr[i + 1]));
		else
			deeper_paired_arr.push_back(deq_merge(paired_arr[i + 1], paired_arr[i]));
	}

	if (deeper_paired_arr.size() > 1)
		deeper_paired_arr = deq_merge_insertion(deeper_paired_arr);
	
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

	std::deque<std::deque<int>> result;

	result.push_back(deq_split_arr_second_half(deeper_paired_arr[0]));
	result.push_back(deq_split_arr_first_half(deeper_paired_arr[0]));

	if (paired_arr.size() % 2 != 0)
		jacobsthal_insertion_sort(deeper_paired_arr, result, paired_arr.back());
	else
		jacobsthal_insertion_sort(deeper_paired_arr, result);

	#ifdef DEBUG
	std::cout << "comparisons: " << g_comparisons << std::endl;
	for (auto i : result)
	{
		std::cout << "{";
		for (auto j : i)
			std::cout << j << " ";
		std::cout << "}";
	}
	std::cout << std::endl;
	#endif

	return (result);
}

// Prepares the array so it can be recursively sorted by merge insertion
std::deque<int> deq_fjmi(std::deque<int> arr)
{
	std::deque<std::deque<int>> paired_arr;
	std::deque<int> result;

	for (size_t i = 0; i < arr.size(); ++i)
		paired_arr.push_back(std::deque<int>{arr[i]});

	paired_arr = deq_merge_insertion(paired_arr);
	for (std::deque<int> pair : paired_arr)
	{
		for (int num : pair)
			result.push_back(num);
	}
	return (result);
}

/* ---------------------------------- main ---------------------------------- */

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

	#ifdef DEBUG
	std::cout << "comparisons: " << g_comparisons << std::endl << std::endl;
	g_comparisons = 0;
	#endif

	// if (std::is_sorted(vec.begin(), vec.end()))
	// 	std::cout << "vec sorted :D" << std::endl;
	// else
	// 	std::cout << "vec not sorted D:" << std::endl;

	start = std::chrono::high_resolution_clock::now();
	deq = deq_fjmi(deq);
	end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double, std::micro> deq_elapsed = end - start;

	#ifdef DEBUG
	std::cout << "comparisons: " << g_comparisons << std::endl << std::endl;
	#endif

	// if (std::is_sorted(deq.begin(), deq.end()))
	// 	std::cout << "deq sorted :D" << std::endl;
	// else
	// 	std::cout << "deq not sorted D:" << std::endl;

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
