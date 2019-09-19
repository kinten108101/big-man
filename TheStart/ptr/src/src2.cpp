#include "../h/Header.h"


int PLACINGP( int A[], int B[], int a) // New array placed first
{
	//for (int i = 0; i < a; i++) { A[i] = B[i]; }
	std::copy(B.begin(), B.end(), A.begin());
	return 0;

}

int PLACINGPX(int A[], int B[], int ax) // New array placed first
{
	//for (int i = 0; i < ax; i++) { A[ax+i] = B[i]; }
	std::copy(B.begin(), B.end(), A.begin()+ax);
	return 0;
}

int SEPARATING(int x, int L[], int R[], int& lh, int& rh)
{
	lh = x / 2;
	if (x == 3) 
	{ 
		rh = 2; 
	}
	else 
	{ 
		rh = lh + ((x - lh) % lh); 
    }

	L = new int[lh];
	R = new int[rh];
	return 0;
}

int BUBBLESORT(int total, int arr[])
{
	int pairamount = total - 1;
	for (int i = 0; i < pairamount; i++)
		for (int i = 0; i < total; i++)
			if (arr[i] < arr[i + 1]) // largest to smallest
				std::swap(arr[i], arr[i + 1]);
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

int SPLIT(int p, int px, int LEFT[], int RIGHT[], int p1, int px1, int LEFT1[], int RIGHT1[])
{
	SEPARATING(p, LEFT1, RIGHT1, p1, px1);
	PLACINGP(LEFT1, LEFT, p1);
	PLACINGPX(RIGHT1, LEFT, px1);
	BUBBLESORT(p1, LEFT1);
	BUBBLESORT(px1, RIGHT1);
	return 0;
}

int MERGE(int p, int LEFT[], int p1, int LEFT1[], int px1, int RIGHT1[])
{
	PLACINGP(LEFT, LEFT1, p1); // New first
	PLACINGPX(LEFT, RIGHT1, px1);
	BUBBLESORT(p, LEFT);
	return 0;
}

int main()
{

	int a = 0;

	int A[1], LEFT[1],RIGHT[1], LEFT1[1], RIGHT1[1], LEFT2[1], RIGHT2[1];

	int p = 0, px = 0, p1 = 0, px1 = 0, p2 = 0, px2=0;
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
	if ((p > 1) && (px > 1))
	{
		SPLIT(p, px, LEFT, RIGHT, p1, px1, LEFT1, RIGHT1);
		SPLIT(p, px, LEFT, RIGHT, p2, px2, LEFT2, RIGHT2);
		MERGE(p, LEFT, p1, LEFT1, px1, RIGHT1);
		MERGE(px, RIGHT, p2, LEFT2, px2, RIGHT2);
	}
	MERGE(a, A, p, LEFT, px, RIGHT);
	for (int i = 0; i < a; i++) LOG(A[i]);
	std::cin.get();




	std::cin.get();

	
	//Problem: can't universally declare arrays LEFT and RIGHT
	//Solution: Declaring new variables that use the given variables (numbnuts). The given one are pre-activated as placeholders (why not?). The original 
	//declaration should be in the main for universal access.
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

