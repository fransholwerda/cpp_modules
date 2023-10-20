#include <iostream>
#include <vector>
#include <set>
#include <chrono>
#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
	_threshold = 20;
}

PmergeMe::PmergeMe(PmergeMe const &other)
{
	*this = other;
}

PmergeMe::~PmergeMe()
{
}

PmergeMe &PmergeMe::operator=(PmergeMe const &other)
{
	if (this != &other)
	{
		_vector = other._vector;
		_set = other._set;
		_threshold = other._threshold;
	}
	return (*this);
}

void PmergeMe::push_back(int n)
{
	_vector.push_back(n);
}

void PmergeMe::insert(int n)
{
	_set.insert(n);
}

void PmergeMe::displayVector()
{
	if (_vector.empty())
	{
		std::cout << "Vector is empty" << std::endl;
		return ;
	}
	std::cout << "Vector: ";
	for (std::vector<int>::iterator it = _vector.begin(); it != _vector.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
}

void PmergeMe::displaySet()
{
	if (_set.empty())
	{
		std::cout << "Set is empty" << std::endl;
		return ;
	}
	std::cout << "Set: ";
	for (std::set<int>::iterator it = _set.begin(); it != _set.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
}

void PmergeMe::mergeInsertionSort()
{
	std::chrono::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now();
	mergeInsertionSortVector();
	std::chrono::high_resolution_clock::time_point end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> elapsed = end - start;
	std::cout << "Time to process a ranger of " << _vector.size() << " elements: " << elapsed.count() << "s" << std::endl;

	start = std::chrono::high_resolution_clock::now();
	mergeInsertionSortSet();
	end = std::chrono::high_resolution_clock::now();
	elapsed = end - start;
	std::cout << "Time to process a ranger of " << _set.size() << " elements: " << elapsed.count() << "s" << std::endl;
}

void insertionSortVector(std::vector<int> &vec, int left, int right)
{
	int i;
	int j;
	int key;

	for (i = left + 1; i <= right; i++)
	{
		key = vec[i];
		j = i - 1;
		while (j >= left && vec[j] > key)
		{
			vec[j + 1] = vec[j];
			j--;
		}
		vec[j + 1] = key;
	}
}

void mergeVector(std::vector<int> &vec, int left, int right, int threshold)
{

}

void mergeSortVector(std::vector<int> &vec, int left, int right, int threshold)
{
	if ((right - left) <= threshold)
	{
		insertionSortVector(vec, left, right);
		return ;
	}
	int mid = (left + right) / 2;
	mergeSortVector(vec, left, mid, threshold);
	mergeSortVector(vec, mid + 1, right, threshold);
	mergeVector(vec, left, mid, right);
}

void PmergeMe::mergeInsertionSortVector()
{
	int left = 0;
	int right = _vector.size() - 1;
	bool isOdd = false;

	if (right % 2 == 1)
	{
		right--;
		isOdd = true;
	}
	mergeSortVector(_vector, left, right, _threshold);
}

void PmergeMe::mergeInsertionSortSet()
{
	
}
