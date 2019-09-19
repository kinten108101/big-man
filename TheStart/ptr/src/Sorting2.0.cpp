#include "../h/Header.h"


void Passing(const std::vector<int>& Something) {}




int PLACINGP(std::vector<int> A, std::vector<int> B) // New array placed first
{
	for (int i = 0; i < B.size(); i++) { A[i] = B[i]; }

	//std::copy(B.begin(), B.end(), A.begin()); 
	return 0;

}

int PLACINGPX(std::vector<int> A, std::vector<int> B) // New array placed first
{
	if (A.size() > B.size())
	{
		for (int i = 0; i < B.size(); i++) { A[B.size() + i] = B[i]; }
	}
	else
	{
		for (int i = 0; i < B.size(); i++) { A[i] = B[B.size() + 1]; }
	}
	//std::copy(B.begin(), B.end(), A.begin() + ax);
	return 0;
}


int BUBBLESORT(std::vector<int> arr)
{
	for (int i = 0; i < arr.size() - 1; i++) // no pairamount
		for (int i = 0; i < arr.size(); i++)
			if (arr[i] < arr[i + 1]) // largest to smallest
				std::swap(arr[i], arr[i + 1]);
	return 0;
}

int INSERTING(int a, std::vector<int> A)
{
	std::cout << "Array Size is " << a << "\n";
	std::cout << "Array: ";
	int input = 0;
	for (int i = 0; i < a; i++) { std::cin >> input; A.push_back(input); }



	return 0;
}

int SPLIT(std::vector<int> A, std::vector<int> LEFT, std::vector<int> RIGHT)
{
	PLACINGP(LEFT, A);
	PLACINGPX(RIGHT, A);
	BUBBLESORT(LEFT);
	BUBBLESORT(RIGHT);
	return 0;
}

int MERGE(std::vector<int> LEFT, std::vector<int> LEFT1, std::vector<int> RIGHT1)
{
	PLACINGP(LEFT, LEFT1); // New first
	PLACINGPX(LEFT, RIGHT1);
	BUBBLESORT(LEFT);
	return 0;
}


int main()
{
	int a = 0;
	std::vector<int> A, LEFT, RIGHT, LEFT1, RIGHT1, LEFT2, RIGHT2;
	std::cout << "Array Size: ";
	std::cin >> a;

	INSERTING(a, A);
	SPLIT(A, LEFT, RIGHT);
	BUBBLESORT(LEFT);
	BUBBLESORT(RIGHT);
	if ((LEFT.size() > 1) && (RIGHT.size() > 1))
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

	for (int i = 0; i < A.size(); i++) { std::cout << A[i] << " "; }
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

