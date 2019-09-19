#include "../h/Header.h"

int BUBBLESORT(int total, int arr[])
{
	int pairamount = total - 1;
	for (int i = 0; i < pairamount; i++)
	{
		for (int i = 0; i < total; i++)
		{
			static int placeholder = 0;
			if (arr[i] < arr[i + 1])
			{
				placeholder = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = placeholder;

			}
			else continue;
		}
	}
	return 0;
}

int INSERTING(int n)
{
	int *LEFT = 0, *RIGHT = 0;
	int p = n / 2;
	int px = p + ((n - p) % p);
	LEFT = new int[p];
	RIGHT = new int[px];


	for (int i = 0; i < p; i++)
	{
		std::cout << "LEFT" << i + 1 << "=";
		std::cin >> LEFT[i];
		
	}
	for (int i = 0; i < px; i++)
	{
		std::cout << "RIGHT" << i + 1 << "=";
		std::cin >> RIGHT[i];
	}
	BUBBLESORT(p, LEFT);
	BUBBLESORT(px, RIGHT);
	return 0;
}

int main()
{
	int a = NULL;
	std::cout << "Limit of array:";
	std::cin >> a;
	INSERTING(a);

	


	std::cin.get();
	
	//
	
	
	//Problem: can't universally declare arrays LEFT and RIGHT

	
	//INSERTING(a);





	/* for testing arraying length
	std::cout << LEFT[a/2] << std::endl;
	std::cout << RIGHT[a/2+1] << std::endl;
	*/
	/* for testing arraying declaring
	int *b = &Array[a - 1];
	*b = 2;
	std::cout << b;
*/ 



	std::cin.get();
}

