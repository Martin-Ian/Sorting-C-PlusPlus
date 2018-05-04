#include <iostream>
#include <string>
#include <vector>
#include <time.h>
#include <cstdlib>
#include "Sorter.h"
#include "Bubble_Sort.h"

using namespace std;

//Makes random numbers
vector<int> getRandomNumbers(int amount, int lower, int upper);

//Benchmarking
void benchmark_sort(int amount);

//Bubble Sort
vector<int> bubble_sort(vector<int> data);

//insertion Sort
vector<int> insertion_sort(vector<int> data);

//Radix sort
vector<int> radix_sort(vector<int> data);

int main(void)
{

	Bubble_Sort bubble{};

	bubble.show_sort();

	for (int i = 100; i <= 3200; i *= 2)
	{
		benchmark_sort(i);
	}

	return 0;
}

vector<int> getRandomNumbers(int amount, int lower, int upper)
{
	//Reset the random number generator
	srand(time(0));

	//Holds numbers
	vector<int> random_numbers;

	for (int i = 0; i < amount; i++)
	{
		//Add random numbers to random_numbers
		random_numbers.push_back(rand() % upper + lower + 1);
	}

	return random_numbers;
}

void benchmark_sort(int amount)
{
	Bubble_Sort bubble{};

	vector<int> to_sort = getRandomNumbers(amount, 0, 1000);
	int start = clock();
	bubble.sort(to_sort);
	int end = clock();
	cout << "Bubble Sort on " << amount << " elements: " << end - start << endl;

	start = clock();
	insertion_sort(to_sort);
	end = clock();
	cout << "Insertion Sort on " << amount << " elements: " << end - start << endl;

	start = clock();
	radix_sort(to_sort);
	end = clock();
	cout << "Radix Sort on " << amount << " elements: " << end - start << endl;

	cout << endl;
}

vector<int> bubble_sort(vector<int> data)
{
	//tracks if it needs more sorting
	bool is_sorted = false;

	while (is_sorted == false)
	{
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

	return data;
}

vector<int> insertion_sort(vector<int> data)
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

vector<int> radix_sort(vector<int> data)
{
	vector<vector<int>> bucket{};
	vector<vector<int>> temp_bucket{};
	int decimal_place = 1;
	bool sorted = false;

	//10 digits, 0-9
	bucket.resize(10);
	temp_bucket.resize(10);

	//Push all data into 0's slot
	for (int i = 0; i < data.size(); i++)
	{
		bucket[0].push_back(data[i]);
	}

	while (sorted == false)
	{
		sorted = true;
		//for each digit in bucket...
		for (int i = 0; i < bucket.size(); i++)
		{
			//for each int at that digit
			for (int j = 0; j < bucket[i].size(); j++)
			{
				int temp = bucket[i][j];
				temp = temp / decimal_place % 10;
				temp_bucket[temp].push_back(bucket[i][j]);

				if (temp != 0)
				{
					sorted = false;
				}
			}
		}

		bucket.swap(temp_bucket);
		temp_bucket.clear();
		temp_bucket.resize(10);
		decimal_place *= 10;
	}

	for (int i = 0; i < bucket[0].size(); i++)
	{
		data[i] = bucket[0][i];
	}

	return data;
}