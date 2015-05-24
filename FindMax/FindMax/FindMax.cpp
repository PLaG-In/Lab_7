// FindMax.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

template < typename T >
bool FindMax(std::vector<T> const& arr, T &maxValue){
	if (arr.empty())
	{
		return false;
	}

	size_t max = 0;
	for (auto elem : arr)
	{
		if (maxValue < elem)
		{
			maxValue = elem;
		}
	}
	return true;
}

int _tmain(int /*argc*/, _TCHAR*/*argv[]*/)
{
	std::vector<int> a = { 1, 4, -2, 0, 12, -6 };
	int max;
	assert(FindMax(a, max));
	assert(max == 12);

	std::string maxStr;
	std::vector<std::string> strings = { "man", "feel", "dead", "like", "wakawaka" };
	assert(FindMax(strings, maxStr));
	assert(maxStr == "wakawaka");
	return 0;
}

