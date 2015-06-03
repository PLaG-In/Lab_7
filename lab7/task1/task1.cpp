// task1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
using namespace std;

template <typename T, typename Comp = std::less<T>>
bool FindMax(std::vector<T> const& arr, T &maxValue, Comp const& comp = std::less<T>())
{
	if (arr.empty())
	{
		return false;
	}

	size_t max = 0;
	for (size_t i = 1; i < arr.size(); ++i)
	{
		if (comp(arr[max], arr[i]))
		{
			max = i;
		}
	}
	maxValue = arr[max];
	return true;
}

struct Student
{
	string name;
	int age;
	int weight;
	int height;
};


int _tmain(int /*argc*/, _TCHAR* /*argv*/[])
{
	std::vector<int> a = { 1, 4, -2, 0, 12, -6 };
	int max;
	assert(FindMax(a, max));
	assert(max == 12);
	int minimum;
	assert(FindMax(a, minimum, [](int const& max, int const& min){return min < max; }));
	assert(minimum == -6);
	std::vector<string> strings = { "cat", "dog", "apple", "cow" };
	string maxString;
	assert(FindMax(strings, maxString));
	assert(maxString == "dog");


	vector<Student> students = {
		{"Ivan Petrov", 20, 100, 150}, 
		{"Eugene Dolgushev", 20, 87, 188},
		{"Vladimir Alitov", 20, 62, 175},
		{ "Oleg Orlov", 30, 120, 187 },
		{ "Franc Kafka", 50, 70, 176 }
	};
	Student tallestStudent;
	assert(FindMax(students, tallestStudent, [](Student const& a, Student const& b){
		return a.height < b.height;
	}));
	assert(tallestStudent.name == "Eugene Dolgushev");
	Student heaviestStudent;
	assert(FindMax(students, heaviestStudent, [](Student const& a, Student const& b){
		return a.weight < b.weight;
	}));
	assert(heaviestStudent.name == "Oleg Orlov");
	return 0;
}

