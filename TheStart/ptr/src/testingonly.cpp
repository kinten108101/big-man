#include "../h/Header.h"



int main()
{
	int i = 0, input = 0; 
	bool end = 0;
	std::vector<int> loop;
	while (end==0) 
	{
		std::cin >> input;
		loop.push_back(input);
		i++;

		if (GetKeyState(VK_SHIFT) == 1) { end = 1; }
		
	}
	
	std::cout << loop.size();
	/*int a = 8;
	int *ptr = &a; // Cannot remove '&'
	*ptr = 3;
	LOG(ptr);
	//ptr = 00000017B3DBFC34, *ptr = 3 
	std::cin.get();*/


	std::cin.get();


	





}








/*

void Arraying(int x)
{
	int *d = &x;
	int z = *d;
		std::cout << z;
	std::cin.get();
}*/

/*void Increment(int *value)
{
	// If we put it *(value++), it would designate value=11 to be an address. Hm, what the mischief is that address anyway?
	(*value)++;
}

int main()
{
int a = 8;
	int *ptr = &a;
	PtrLog(ptr);
	int Number[6];
	for (int i = 0; i < 6; i++)
	{
		Number[i] = i;
	}
	NumLog(Number[2]);
	*/



	/*int n[8];
	int a[4];
	int b[4];

	for (int i = 0;i < 8; i++)
	{
		std::cout << "Number" << i+1 << "=";
		std::cin >> n[i];
	}
	a[0] = n[0];
	std::cout << a[0];

	for (int i = 0; i < 4; i++) { a[i]=n[i] ; std::cout << a[i]; }
	for (int i = 4; i < 8; i++) { b[i - 4]= n[i] ; std::cout << b[i - 4]; }
}



*/