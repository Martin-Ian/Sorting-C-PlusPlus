#pragma once
#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

//This is the parent sorter class
class Sorter
{
public:
	string name = "Undefined Sort";

	//This function will sort 'data' and return the sorted data
	virtual vector<int> sort(vector<int> data)
	{
		return data;
	}

	//This function will attempt to show the user how 
	//	The specific sorting algorithm works
	virtual void show_sort()
	{
		return;
	}
};