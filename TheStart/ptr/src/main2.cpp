#include "../h/Header.h"

int SEPARATING(int x, int* L, int* R, int& lh, int& rh)
{
	lh = x / 2;
	rh = lh + ((x - lh) % lh);
	L = new int[lh];
	R = new int[rh];
	return 0;
}

int BUBBLESORT(int total, int arr[])
{
	int pairamount = total - 1;
	for (int i = 0; i < pairamount; i++)
	{
		for (int i = 0; i < total; i++)
		{
			static int placeholder = 0;
			if (arr[i] < arr[i + 1]) // largest to smallest
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

int INSERTING(int n, int L[], int R[], int lh, int rh)
{

	for (int i = 0; i < lh; i++)
	{
		std::cout << "LEFT" << i + 1 << "=";
		std::cin >> L[i];
	}
	for (int i = 0; i < rh; i++)
	{
		std::cout << "RIGHT" << i + 1 << "=";
		std::cin >> R[i];
	}
	

	return 0;
}

int main()
{

	int a = NULL;
	int *LEFT = 0, *RIGHT = 0;
		int c = 0, cc = 0;
	int& p = c;
	int& px = cc;
	std::cout << "Limit of array:";
	std::cin >> a;

	SEPARATING(a, LEFT, RIGHT, p, px);
	INSERTING(a, LEFT, RIGHT, p, px);
    BUBBLESORT(p, LEFT);
	BUBBLESORT(px, RIGHT);


	std::cin.get();

	//


	//Problem: can't universally declare arrays LEFT and RIGHT
	//Solution: Declaring new variables that use the given variables (numbnuts). The original declaration should be in the main for
	//universal access.


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

