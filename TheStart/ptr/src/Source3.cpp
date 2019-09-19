#include "../h/Header.h"

int T, N, arr;

int insertionsort(std::vector<int>& arr, int n)
{

	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (arr[i] < arr[j]) { std::swap(arr[j], arr[i]); }
		}
	}
	return 0;
}

void merge(std::vector<int>& arr, int l, int m, int r)
{
	int size1 = m - l;
	int size2 = r - m;


	std::vector<int> arr1, arr2;

	for (int i = 0; i < size1; i++)
		//arr1[i] = arr[i]; 
		arr1.push_back(arr[i]);
	for (int i = 0; i < size2; i++)
		//arr2[i] = arr[i + m];
		arr2.push_back(arr[i + m]);

	int i = 0, j = 0, a = l, mm = 0;



	while (i < size1 && j < size2)
	{
		if (arr1[i] <= arr2[j])
		{
			arr.push_back(arr1[i]);
			i++;
		}
		else
		{
			arr.push_back(arr2[i]);
			j++;
		}
		a++;
	}

	while (i < size1)
	{
		arr.push_back(arr1[i]);
		i++;
	}
	while (j < size2)
	{
		arr.push_back(arr1[j]);
		j++;
	}

}






/*
	if (l < r)
	{
		for (int i = 0; i < (m); i++)
		{
			int fail = 1;
			for (int j = mm; j < (r-m); j++)
			{
				if (arr1[i] > arr2[j])
				{
					arr[a] = arr2[j];
					a++;
					mm++;
					fail = 0;
				}
				else { fail = 1; }
			}
			if (fail == 1) { arr[a] = arr1[i]; a++; }
		}
		for (mm; mm < (r-m); mm++)
		{
			arr[a] = arr2[mm];
			a++;
		}
	}
}*/

void mergesort(std::vector<int>& arr, int l, int r)
{
	if (l < r)
	{
		int m = (l + r) / 2;
		mergesort(arr, l, m);
		mergesort(arr, m + 1, r);
		merge(arr, l, m, r);
	}
}


void printarray(std::vector<int>& arr, int n)
{
	for (int i = 0; i < n; i++) printf("%d ", arr[i]);
}

int main()
{
	std::vector<int> arr;
	int n, T;
	scanf_s("%d", &T);
	while (T--)
	{
		
		scanf_s("%d", &n);
		//for (int i = 0; i < n; i++) scanf_s("%d", &arr[i]);
		
		int input = 0;
		for (int i = 0; i < n; i++) {
			std::cin >> input;
			if (input == floor(input))
				arr.push_back(input);
		}


			//int m = (l + r) / 2;
			//int arr[l + r] = { 1,2,10,15,5,9,11,99,100,101};
			mergesort(arr, 0, n);
			printarray(arr, n);
		
		system("Pause");

	}
}