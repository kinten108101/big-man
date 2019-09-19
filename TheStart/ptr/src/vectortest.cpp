#include "../h/Header.h"


struct Names
{
	int a, b, c;
};

std::ostream& operator<<(std::ostream& stream, const Names& vertex)
{
	stream << vertex.a << ", " << vertex.b << ", " << vertex.c;
	return stream;
}

void Passing(const std::vector<Names>& BigName){}

int main()
{
	std::vector<Names> BigName;
	Passing(BigName);
	BigName.push_back({ 1,2,3 });
	for (Names a : BigName) { std::cout << a; }



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