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

	int a = 0;
	int *LEFT = 0, *RIGHT = 0;

	int p = 0, px = 0;
	std::cout << "Limit of array:";
	std::cin >> a;

	SEPARATING(a, LEFT, RIGHT, p, px);
	/*p = a / 2;
	px = p + ((a - p) % p);
	LEFT = new int[p];
	RIGHT = new int[px];*/
	INSERTING(a, LEFT, RIGHT, p, px);
	BUBBLESORT(p, LEFT);
	BUBBLESORT(px, RIGHT);


	std::cin.get();

	//


	//Problem: can't universally declare arrays LEFT and RIGHT
	//Solution: Declaring new variables that use the given variables (numbnuts). The original declaration should be in the main for
	//universal access.
	//Problem: L's address 0x00000000000...


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



}

