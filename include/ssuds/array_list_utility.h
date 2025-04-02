#pragma once

#include <array_list.h>
#include <random>

namespace ssuds
{

	
	enum class SortType { ASCENDING, DESCENDING };

	/*template <class T>

	unsigned int quicksort(ssuds::ArrayList<T>& alist, SortType tp) {
		int temp_val = 0;
		if (tp == SortType::DESCENDING) {
			for (unsigned int i = 0; i < alist.size() - 1; i++) {

			}
		}
		else {

		}
	}

	template <class T>

	unsigned int partition(ssuds::ArrayList<T> alist, unsigned int left_index, unsigned int right_index) {
		unsigned int mid_index = (left_index + right_index) / 2;
		int pivot_val = alist[mid_index]


	}

	void swap(int&) {

	}
	*/

	template <class T>

	unsigned int binary_search(const ArrayList<T>& alist, enum SortType tp, T search_val) {
		unsigned int left = 0;
		unsigned int right = alist.size() - 1;
		

		while (left <= right) {
			unsigned int mid = (right - left) / 2;
			if (alist[mid] == search_val) {
				return mid;
			}
			else if (right == left) {
				return right;
			}
			else if (search_val < alist[mid] && tp == SortType::ASCENDING) {
				right = mid - 1;
			}
			else if (search_val > alist[mid] && tp == SortType::ASCENDING) {
				left = mid + 1;
			}
			else if (search_val < alist[mid] && tp == SortType::DESCENDING){
				left = mid + 1;
			}
			else if (search_val > alist[mid] && tp == SortType::DESCENDING) {
				right = mid - 1;
			}
		}
			
			
		return -1;
	}
	
	template <class T>

	unsigned int bubble_sort(const ArrayList<T>& alist, enum SortType tp){
		// Loops, swap alist[i] and alist[i + 1], etc.
		unsigned int changes = 0;
		if (tp == SortType::DESCENDING) {
			while (1) {
				unsigned int temp_changes = 0;
				for (unsigned int i = 0; i < alist.size(); i++) {
					if (i != alist.size() - 1 && alist[i + 1] > alist[i]) {
						int temp_val = alist[i];
						alist[i] = alist[i + 1];
						alist[i + 1] = temp_val;
						changes++;
						temp_changes++;
					}

				}
				if (temp_changes == 0) {
					return changes;
				}
			}
		}
		else {
			while (1) {
				unsigned int temp_changes = 0;
				for (unsigned int i = 0; i < alist.size(); i++) {
					if (i != alist.size() - 1 && alist[i + 1] < alist[i]) {
						int temp_val = alist[i];
						alist[i] = alist[i + 1];
						alist[i + 1] = temp_val;
						changes++;
						temp_changes++;
					}

				}
				if (temp_changes == 0) {
					return changes;
				}
			}
		}
		return changes;

	}

	template <class T>
	ArrayList<T> shuffle(const ArrayList<T>& alist) {
		unsigned int n = alist.size() - 1;
		ssuds::ArrayList<float> temp_list = alist;
		for (n > 0; n--;) {
			std::default_random_engine generator;
			std::uniform_int_distribution<int> distribution(0, n);
			unsigned int shuf_index = distribution(generator);
			int temp_val = temp_list[shuf_index];
			temp_list[shuf_index] = temp_list[n];
			temp_list[n] = temp_val;
		}
		return temp_list;
	}

	/*template <class T>
	bool shuffled_check(const ArrayList<T>& alist1, const ArrayList<T>& alist2) {
		unsigned int n = alist.size() - 1;
		if (alist1.size() == alist2.size()) {
			for (unsigned int i = 0; i < n; i++;) {
				if (alist1[i] != alist2[i]) {
					return true;
				}
			}
		}
		return false;
	}
	*/
	
}