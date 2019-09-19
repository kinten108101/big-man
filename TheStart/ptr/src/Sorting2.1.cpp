#include "../h/Header.h"

int PLACINGP(std::vector<int>& A, std::vector<int>& B) // New array placed first
{
	if (A.size() > B.size())
	{
		for (int i = 0; i < B.size(); i++) { A[i] = B[i]; }
		//for (int i = 0; i < A.size(); i++) { std::cout << A[i] << " "; }
	}
	else
		for (int i = 0; i < A.size(); i++) { A[i] = B[i]; }
	//for (int i = 0; i < A.size(); i++) { std::cout << A[i] << " "; }
	
//{A.insert(A.begin()+i,B[i]); }
	//std::copy(B.begin(), B.end(), A.begin()); 
	return 0;

}

int PLACINGPX(std::vector<int>& A, std::vector<int>& B) // New array placed first
{
	if (A.size() > B.size())
	{
		for (int i = 0; i < B.size(); i++) { A[i + (A.size() / 2) ] = B[i]; } //{A.insert(A.begin() + (B.size()/2)-1 + i, B[i]); }
		//for (int i = 0; i < A.size(); i++) { std::cout << A[i] << " "; }
	}
	else
	{
		for (int i = 0; i < A.size(); i++) {A[i] = B[i + (B.size() / 2) ];}  //{A.insert(A.begin()+i, B[(B.size()/2)-1 + i]); }
		//for (int i = 0; i < A.size(); i++) { std::cout << A[i] << " "; }
	}
	//std::copy(B.begin(), B.end(), A.begin() + ax);
	return 0;
}



int BUBBLESORT(std::vector<int>& arr)
{
	
	for (int i = 0; i < (arr.size() - 1); i++) // no pairamount
		for (int i = 0; i < arr.size()-1; i++)
			if (arr[i] < arr[i + 1]) // largest to smallest
				std::swap(arr[i], arr[i + 1]);
	//for (int i = 0; i < arr.size(); i++) { std::cout << arr[i] << " "; }
	return 0;
}

int INSERTING(int& a, std::vector<int>& A)
{
	std::cout << "\rArray Unsorted: ";
	int input = 0;
	for (int i = 0; i < a; i++) { 
		std::cin >> input;  
		if (input==floor(input))
			A.push_back(input);
	
	}
	return 0;
}

int PUSHING(int a, std::vector<int>& LEFT, std::vector<int>& RIGHT)
{
	int lh = a / 2;
	int rh = a - lh;
	for (int i = 0; i < lh; i++) LEFT.push_back(0);
	for (int i = 0; i < rh; i++) RIGHT.push_back(0);
	return 0;
}

int SPLIT(std::vector<int>& A, std::vector<int>& LEFT, std::vector<int>& RIGHT)
{
	PUSHING(A.size(), LEFT, RIGHT);
	PLACINGP(LEFT, A);
	PLACINGPX(RIGHT, A);
	BUBBLESORT(LEFT);
	BUBBLESORT(RIGHT);
	return 0;
}

int MERGE( std::vector<int>& LEFT, std::vector<int>& LEFT1, std::vector<int>& RIGHT1)
{
	PLACINGP(LEFT, LEFT1); // New first
	PLACINGPX(LEFT, RIGHT1);
	BUBBLESORT(LEFT);
	return 0;
}



int main()
{
	int all = 0;
	std::vector<int> ALL, LEFT, RIGHT, LEFT1, RIGHT1, LEFT2, RIGHT2;
	std::cout << "Array Size: ";
	std::cin >> all;

	INSERTING(all, ALL);

	

	SPLIT(ALL, LEFT, RIGHT);
	BUBBLESORT(LEFT);
	BUBBLESORT(RIGHT);
	if ((LEFT.size() > 1) && (RIGHT.size() > 1))
	{
		SPLIT(LEFT, LEFT1, RIGHT1);
		SPLIT(RIGHT, LEFT2, RIGHT2);
		MERGE(LEFT, LEFT1, RIGHT1);
		MERGE(RIGHT, LEFT2, RIGHT2);
	}
	MERGE(ALL, LEFT, RIGHT);
	std::cout << "\n";
	std::this_thread::sleep_for(std::chrono::seconds(2));
	//I swear, this cpp must be cleaned up before I move on to something else
	std::cout << "Array   sorted: ";
	for (int i = 0; i < ALL.size(); i++) { std::cout << ALL[i] << " "; }
	//std::copy(A.begin(), A.end(), std::ostream_iterator<int>(std::cout, " "));

	std::cin.get();




	std::cin.get();


	//Problem: can't universally declare arrays LEFT and RIGHT
	//Solution: Declaring new variables that use the given variables (numbnuts). The given one are pre-activated as placeholders (why not?). The original 
	//declaration should be in the main for universal access.
	//Problem: L's address 0x00000000000...
	//Solution: Replace arrays with vectors.


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

