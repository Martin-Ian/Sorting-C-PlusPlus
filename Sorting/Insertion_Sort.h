#pragma once

#include <cstdlib>
#include <iostream>
#include <vector>
#include "Sorter.h"

class Insertion_Sort : public Sorter
{
public:

	virtual vector<int> sort(vector<int> data)
	{
		//Iterates front to back of data
		int i = 1;
		while (i < data.size())
		{
			//itterates 'back' to front of list
			int j = i - 1;
			int val = data[i];
			while (j > -1 && data[j] > val)
			{
				//Swap if greater
				data[j + 1] = data[j];
				j--;
			}
			//replace temp value
			data[j + 1] = val;
			i++;
		}

		return data;
	}

	void virtual show_sort()
	{
		cout << "TO DO" << endl;
	}
};