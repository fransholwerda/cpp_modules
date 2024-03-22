#include <iostream>
#include <vector>
#include <deque>
#include <stdlib.h>
#include <algorithm>
#include <chrono>
#include <set>

size_t jacobsthal(size_t n)
{
	if ( n <= 1)
		return (n);
	return (jacobsthal(n - 1) + 2 * jacobsthal(n - 2));
}

std::vector<size_t> build_jacob_insertion_sequence(std::vector<int> array)
{
	size_t				array_len = array.size();
	std::vector<size_t>	insertion_sequence;
	size_t				jacob_index = 3;
	size_t				jacob_number = jacobsthal(jacob_index);

	while (jacob_number < (array_len - 1))
	{
		insertion_sequence.push_back(jacob_number);
		jacob_index++;
		jacob_number = jacobsthal(jacob_index);
	}

	return (insertion_sequence);
}

std::vector<std::vector<int>> vec_create_pairs(std::vector<int> vec)
{
	std::vector<std::vector<int>>	split_vec;
	std::vector<int>				temp_vec;

	for (size_t i = 0; i < vec.size(); ++i)
	{
		size_t temp_length = temp_vec.size();
		if (temp_length == 1)
		{
			temp_vec.push_back(vec[i]);
			split_vec.push_back(temp_vec);
			temp_vec.clear();
		}
		else if (split_vec.size() * 2 == vec.size() - 1)
		{
			std::vector<int> single_value;
			single_value.push_back(vec[i]);
			split_vec.push_back(single_value);
		}
		else if (temp_length == 0)
			temp_vec.push_back(vec[i]);
	}

	return (split_vec);
}

void vec_sort_each_pair(std::vector<std::vector<int>> split_vec)
{
	for (std::vector<int> pair : split_vec)
	{
		if (pair.size() != 1 && (pair[0] > pair[1]))
		{
			int temp = pair[0];
			pair[0] = pair[1];
			pair[1] = temp;
		}
	}
}

void vec_insert(std::vector<int> element, std::vector<std::vector<int>> split_vec, size_t n)
{
	if (n < 0)
		split_vec[0] = element;
	else if (element[1] >= split_vec[n][1])
	{
		if (n == split_vec.size() - 1)
			split_vec.push_back(element);
		else
			split_vec[n + 1] = element;
	}
	else
	{
		if (n == split_vec.size() - 1)
			split_vec.push_back(split_vec[n]);
		else
		{
			split_vec[n + 1] = split_vec[n];
			vec_insert(element, split_vec, n - 1);
		}
	}
}

void vec_insertion_sort_pairs(std::vector<std::vector<int>> split_vec, size_t n)
{
	if (n < 1)
		return;
	vec_insertion_sort_pairs(split_vec, n - 1);
	vec_insert(split_vec[n], split_vec, n - 1);
}

void vec_sort_by_larger_value(std::vector<std::vector<int>> split_vec)
{
	size_t length = split_vec.size();

	vec_insertion_sort_pairs(split_vec, length - 1);
}

std::vector<int> vec_create_seq(std::vector<std::vector<int>> split_vec, bool straggler, int straggler_number)
{
	std::vector<int>	sequence;
	std::vector<int>	pending;

	for (std::vector<int> pair : split_vec)
	{
		sequence.push_back(pair[1]);
		pending.push_back(pair[0]);
	}

	sequence.insert(sequence.begin(), pending[0]);

	size_t				iterator = 0;
	size_t				jacobindex = 3;
	int					item;
	std::vector<size_t>	indexSequence {1};
	std::string			last = "default";

	std::vector<size_t> jacob_insertion_sequence = build_jacob_insertion_sequence(pending);

	while (iterator <= pending.size())
	{
		if (jacob_insertion_sequence.size() != 0 && last != "jacob")
		{
			indexSequence.push_back(jacob_insertion_sequence[0]);
			item = pending[jacob_insertion_sequence[0] - 1];
			last = "jacob";
		}
		else
		{
			if (std::find(indexSequence.begin(), indexSequence.end(), iterator) != indexSequence.end())
				iterator++;
			std::cout << (iterator - 1) << std::endl;
			if (iterator > 0)
			{
				std::cout << "size of pending: " << pending.size() << std::endl;
				item = pending[iterator - 1];
			}
			else
				item = pending[pending.size() - 1];
			indexSequence.push_back(iterator);
			last = "not-jacob";
		}

		size_t insertion_point = std::lower_bound(sequence.begin(), sequence.end(), item) - sequence.begin();
		sequence.insert(sequence.begin() + insertion_point, item);
		iterator++;
		jacobindex++;
	}

	if (straggler)
	{
		std::cout << "Straggler: " << straggler_number << std::endl;
		size_t insertion_point = std::lower_bound(sequence.begin(), sequence.end(), straggler_number) - sequence.begin();
		sequence.insert(sequence.begin() + insertion_point, straggler_number);
	}

	return (sequence);
}

std::vector<int> vec_merge_insertion_sort(std::vector<int> vec)
{
	bool straggler = false;
	int straggler_number = 0;
	if (vec.size() % 2 != 0)
	{
		straggler = true;
		straggler_number = vec[vec.size() - 1];
		vec.pop_back();
	}
	std::vector<std::vector<int>> split_vec = vec_create_pairs(vec);
	vec_sort_each_pair(split_vec);
	vec_sort_by_larger_value(split_vec);
	std::vector<int> sorted_vec = vec_create_seq(split_vec, straggler, straggler_number);

	return (sorted_vec);
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
	vec = vec_merge_insertion_sort(vec);
	std::chrono::_V2::system_clock::time_point end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double, std::micro> vec_elapsed = end - start;

	start = std::chrono::high_resolution_clock::now();
	// merge_insertion_sort(deq, 0, deq.size() - 1);
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
