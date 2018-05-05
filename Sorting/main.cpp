#include <iostream>
#include <string>
#include <vector>
#include <time.h>
#include <cstdlib>
#include <unordered_map>
#include "Sorter.h"
#include "Bubble_Sort.h"
#include "Insertion_Sort.h"

using namespace std;

//Makes random numbers
vector<int> getRandomNumbers(int amount, int lower, int upper);

//Benchmarking
void benchmark_sort();

//Radix sort
vector<int> radix_sort(vector<int> data);

int main(void)
{
	vector<pair<string, Sorter*>*> sorters{};
	vector<Sorter*> sorter_choices{};
	//Note, not ideal, but it works
	sorters.push_back(new pair<string, Sorter*>{ "Bubble Sort", new Bubble_Sort{} });
	sorters.push_back(new pair<string, Sorter*>{ "Insertion Sort", new Insertion_Sort{} });

	cout << "Welcome to Ian's sorts! (Last updated 5/4/18)" << endl;
	bool choice_made = false;
	
	//Loops until a choice is made
	do
	{
		cout << "What would you like to do?" << endl;
		cout << "*[0] Benchmark Sorts" << endl;
		cout << "*[1] Learn how a sorting algorithm works" << endl;
		cout << "*[-1] Exit program" << endl;
		string responce;
		getline(cin, responce);

		switch (responce[0])
		{
		case '0':
			choice_made = true;
			benchmark_sort();
			break;
		case '1':
			choice_made = true;
			//learn_sorts();
			break;
		case '-': //-1
			choice_made = true;
			cout << "Thank you!" << endl;
			return 0;
			break;
		default:
			cout << "I didn't understand that." << endl;
			break;
		}
	} while (choice_made == false);

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

void benchmark_sort()
{
	unordered_map<string, Sorter*> sorters{};
	sorters["Bubble Sort"] = new Bubble_Sort();
	sorters["Insertion Sort"] = new Insertion_Sort();

	for (int i = 100; i <= 3600; i *= 2)
	{
		vector<int> to_sort = getRandomNumbers(i, 0, 1000);
		int start;
		int end;

		for (auto sorter : sorters)
		{
			start = clock();
			sorter.second->sort(to_sort);
			end = clock();
			cout << sorter.first << " on " << to_sort.size() << " elements: " << end - start << endl;
		}
		cout << endl;
	}
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