#include "../h/Header.h"

int BUBBLESORT(int n, int arr[])
{
	int run = n - 1;
	for (int i = 0; i < run; i++)
		for (int i = 0; i < n; i++)
			if (arr[i] < arr[i + 1]) // largest to smallest
				std::swap(arr[i], arr[i + 1]);
	return 0;
}

int main()
{
	int n = 5, run = n - 1,
		arra[5] = { 5, 7, 4, 2, 14 };
	BUBBLESORT(n, arra);
	for (int i = 0; i < run; i++) {LOG(arra[i]);}
	std::cin.get();
}