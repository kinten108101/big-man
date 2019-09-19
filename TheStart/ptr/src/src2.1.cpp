#include "../h/Header.h"


int SIZE(int A[])
{
	int a;
	a = (sizeof A) / (sizeof *A);
	return a;
}


int PLACINGP(int A[], int B[]) // New array placed first
{
	for (int i = 0; i < SIZE(B); i++) { A[i] = B[i]; }

	//std::copy(B.begin(), B.end(), A.begin()); 
	return 0;

}

int PLACINGPX(int A[], int B[]) // New array placed first
{
	if (SIZE(A) > SIZE(B))
	{
		for (int i = 0; i < SIZE(B); i++) { A[SIZE(B) + i] = B[i]; }
	}
	else
	{
		for (int i = 0; i < SIZE(B); i++) { A[i] = B[SIZE(B) + 1]; }
	}
	//std::copy(B.begin(), B.end(), A.begin() + ax);
	return 0;
}


int SEPARATING(int A[], int L[], int R[])
{
	int lh = SIZE(A) / 2;
	int rh = lh + ((SIZE(A) - lh) % lh);

	L = new int[lh];
	R = new int[rh];
	return 0;
}

int BUBBLESORT(int arr[])
{
	int pairamount = SIZE(arr) - 1;
	for (int i = 0; i < pairamount; i++)
		for (int i = 0; i < ((sizeof arr) / (sizeof *arr)); i++)
			if (arr[i] < arr[i + 1]) // largest to smallest
				std::swap(arr[i], arr[i + 1]);
	return 0;
}

int INSERTING(int A[])
{
	
	std::cout << "Array: ";
	for (int i = 0; i < SIZE(A); i++) std::cin >> A[i];


	return 0;
}

int SPLIT(int A[], int LEFT[], int RIGHT[])
{
	SEPARATING(A, LEFT, RIGHT);
	PLACINGP(LEFT, A);
	PLACINGPX(RIGHT, A);
	BUBBLESORT(LEFT);
	BUBBLESORT(RIGHT);
	return 0;
}

int MERGE(int LEFT[], int LEFT1[], int RIGHT1[])
{
	PLACINGP(LEFT, LEFT1); // New first
	PLACINGPX(LEFT, RIGHT1);
	BUBBLESORT(LEFT);
	return 0;
}

int main()
{

	int a = 0;
	int* A = NULL;

	int LEFT[1], RIGHT[1], LEFT1[1], RIGHT1[1], LEFT2[1], RIGHT2[1];

	std::cout << "Limit of array:";
	std::cin >> a;
	A = new int[a];

	
	/*p = a / 2;
	px = p + ((a - p) % p);
	LEFT = new int[p];
	RIGHT = new int[px];*/
	INSERTING(A);
	SPLIT(A, LEFT, RIGHT);
	BUBBLESORT(LEFT);
	BUBBLESORT(RIGHT);
	if ((SIZE(LEFT) > 1) && (SIZE(RIGHT) > 1))
	{
		SPLIT(LEFT, LEFT1, RIGHT1);
		SPLIT(RIGHT, LEFT2, RIGHT2);
		MERGE(LEFT, LEFT1, RIGHT1);
		MERGE(RIGHT, LEFT2, RIGHT2);
	}
	MERGE(A, LEFT, RIGHT);
	std::cout << "\n";
	std::this_thread::sleep_for(std::chrono::seconds(2));
	//I swear, this cpp must be cleaned up before I move on to something else

	for (int i = 0; i < a; i++) { std::cout << A[i] << " "; }
	//std::copy(A.begin(), A.end(), std::ostream_iterator<int>(std::cout, " "));
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

