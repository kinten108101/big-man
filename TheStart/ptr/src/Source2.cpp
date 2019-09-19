#include "../h/Header.h"

/*int insertionsort(int arr[], int n)
{

	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (arr[i] < arr[j]) { std::swap(arr[j], arr[i]); }
		}
	}
	return 0;
}*/

void merge(int arr[], int l, int m, int r)
{
	int size1 = m-l+1;
	int size2 = r-m;

	int * arr1,* arr2;

	arr1 = new int[size1];
	arr2 = new int[size2];

	for (int i = 0; i < size1; i++)
		arr1[i] = arr[i];
	for (int i = 0; i < size2; i++)
		arr2[i] = arr[i + m+1];

	int i = 0, j = 0, a = l, mm = 0;



	while (i < size1 && j < size2)
	{
		if (arr1[i] <= arr2[j])
		{
			arr[a] = arr1[i];
			i++;
		}
		else
		{
			arr[a] = arr2[j];
			j++;
		}
		a++;
	}

	while (i < size1)
	{
		arr[a] = arr1[i];
		a++;
		i++;
	}	
	while (j < size2)
	{
		arr[a] = arr2[j];
		a++;
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

void mergesort(int arr[], int l, int r)
{
	if (l < r)
	{
		int m = (l + r ) / 2;
		mergesort(arr, l, m);
		mergesort(arr, m, r);
		merge(arr, l, m, r);
	}
}


void printarray(int arr[],int n)
{
	for (int i = 0; i < n; i++) printf("%d ", arr[i]);
}


int main()
{
	int * arr;

	int n, T;
	scanf_s("%d", &T);
	while (T--)
	{
		//scanf_s("%d", &n);
		n = 11;
		//for (int i = 0; i < n; i++) scanf_s("%d", &arr[i]);
		arr = new int[11];
		arr[0] = 3;
		arr[1] = 6;
		arr[2] = 5;
		arr[3] = 1;
		arr[4] = 77;
		arr[5] = 32;
		arr[6] = 56;
		arr[7] = 91;
		arr[8] = 22;
		arr[9] = 1;
		arr[10] = 10;

		//int m = (l + r) / 2;
		//int arr[l + r] = { 1,2,10,15,5,9,11,99,100,101};
		mergesort(arr,0,n-1);
		printarray(arr, n);
	}
	system("Pause");

}