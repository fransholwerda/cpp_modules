#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <vector>
# include <set>

template <class T>
class PmergeMe
{
	private:
		std::vector<int>	_vector;
		std::set<int>		_set;
		int					_threshold;
	public:
		PmergeMe();
		PmergeMe(PmergeMe const &other);
		~PmergeMe();
		PmergeMe &operator=(PmergeMe const &other);

		void	push_back(int n);
		void	insert(int n);
		void	displayVector();
		void	displaySet();
		void	mergeInsertionSort();
		void	mergeInsertionSortVector();
		void	mergeInsertionSortSet();

		void	setThreshold(int threshold);
		int		getThreshold() const;
};

#endif
