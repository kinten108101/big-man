#include "../h/Header.h"

int T, N, arr;

int insertionsort(int arr[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (arr[i] < arr[j]){std::swap(arr[j], arr[i]);}
		}
	}
	return 0;
}

void merge(int arr[], int l,int m, int r)
{
	int a = 0;
	int mm = m;

	if (l < r) 
	{
			for (int i = 0; i < (m); i++)
			{
				int fail = 1;
				for (int j = mm; j < r; j++)
				{
					if (arr[i] > arr[j])
					{
						arr1[a] = arr[j];
						a++;
						mm++;
						fail = 0;
					}
					else { fail = 1; }
				}
				if (fail == 1) { arr1[a] = arr[i]; a++; }
			}
			for (mm; mm < r; mm++)
			{
				arr1[mm] = arr[mm];
			}
	}
}

int main()
{
	
	
	const int n = 9, l = 0, r = 9;
	int m = (l+r)/2;
	int arr[l+r] = { 1,2,10,15,5,9,11,99,100 };
	int arr1[l+r];
	merge(arr, l, m, r);
	for (int i = 0; i < (l + r); i++)
	{
		printf("%d ", arr1[i]);
	}
	system("Pause");

}