/**
*	Recursive Binary Search
*	Reading: section 7.3
*	HomeWork Completed by Preston Stephens
*/
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>
using namespace std;

/**
*	Template function for performing the recursive binary search
*/
template <typename T>
int binary_search(const vector<T> &items, int first, int last, T target) {
	// FIXME: Implement recursive binary search

	// Check to see if target is within bounds
	if (target < items[first] || target > items[last]) {
		return -1;
	}

	// Calculate Midpoint
	int mid = first + ((last - first) / 2);
	
	// Check where the target is in relation to the midpoint and call the function accordingly
	if (items[mid] > target) {
		return binary_search(items, first, mid, target);
	}
	if (items[mid] < target) {
		return binary_search(items, mid, last, target);
	}

	// Check to see if the target is reached
	if (items[mid] == target) {
		return mid;
	}

	// Check to see if the list is empty
	if (first == last) {
		return -1;
	}
}

/**
*	Template function for invoking the recursive binary search function.
*	This is the function a user calls.
*/
template <typename T>
int binary_search(const vector<T> &items, T target) {
	return binary_search(items, 0, items.size()-1, target);
}

int main()
{
	/** TEST */
	vector<int> haystack;

	srand(1);
	for (int i = 0; i < 1000000; ++i) // initialize the vector with random values
		haystack.push_back(rand());


	sort(haystack.begin(), haystack.end()); // sort the contents of the vector

	bool retryflag = true;
	do {
		int needle;
		cout << "Enter a number to search for [-1 to exit]: ";
		cin >> needle; // get the value to search for in the vector
		if (needle == -1) {
			retryflag = false; // time to exit 
		} 
		else {
			int idx = binary_search(haystack, needle); // search for the needle in the haystack
			if (idx != -1) // found the index where the needle is located in the haystack
				cout << needle << " found at index " << idx << endl;
			else
				cout << needle << " is not in haystack\n";
		}
	} while (retryflag);

}