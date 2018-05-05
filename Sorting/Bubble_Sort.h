#pragma once

#include <cstdlib>
#include <iostream>
#include <vector>
#include "Sorter.h"

class Bubble_Sort : public Sorter
{
public:

	virtual vector<int> sort(vector<int> data)
	{
		//tracks if it needs more sorting
		bool is_sorted = false;

		//If its not sorted... keep sorting
		while (is_sorted == false)
		{
			//Assume its sorted, if its not, we will update later
			is_sorted = true;

			//Go through each data point
			for (int i = 0; i < data.size() - 1; i++)
			{
				//If a number is greater than the next number, swap them
				if (data[i] > data[i + 1])
				{
					//swap and set is_sorted to false
					is_sorted = false;
					int temp = data[i];
					data[i] = data[i + 1];
					data[i + 1] = temp;
				}
			}
		}

		//return the soted data
		return data;
	}

	void virtual show_sort()
	{
		cout << "How does Bubble Sort work?" << endl;

		cout << "Consider the following list of numbers: " << endl << endl;

		cout << "7, 6, 8, 4, 3" << endl << endl;

		cout << "Bubble sort starts at the first element in our list, in this case, 7," << endl;
		cout << "and compares it to the next value, 6." << endl;

		cout << "Since our first value is larger than our second, we swap them in the list." << endl;
		cout << "Our current list now looks like this: " << endl;
		cout << "6, 7, 8, 4, 3" << endl;

		cout << "Now bubble sort does the same thing starting on the second item in our list." << endl;
		cout << "Since 7 is less than 8, we do not swap them, and move to the third number." << endl;

		cout << "We compare 8 and 4, and since 8 is larger than 4, we swap them." << endl;
		cout << "Now our list is:" << endl;
		cout << "6, 7, 4, 8, 3" << endl;

		cout << "We move to the two numbers, 8 and 3, and swap them as well." << endl;
		cout << "6, 7, 4, 3, 8" << endl;

		cout << "We have now hit the end of our list, and since we needed to swap in our first" << endl;
		cout << "time through our list, we need to continue to sort. So we start again at the beginning." << endl;
		cout << "We continue looping through until our list is sorted." << endl;

		cout << "6, 4, 7, 3, 8" << endl;
		cout << "6, 4, 3, 7, 8" << endl;
		cout << "4, 6, 3, 7, 8" << endl;
		cout << "4, 3, 6, 7, 8" << endl;
		cout << "3, 4, 6, 7, 8" << endl << endl;
		
		cout << "Notice when we find the largest number in our list, it \'bubbles\' to the top of our list." << endl;
		cout << "Now you know how Bubble Sort works!" << endl;
	}
};