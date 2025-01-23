#include <iostream>
using namespace std;


bool oddOrEven(int N)
{
	return N & 1;
}

int main()
{
	int res;
	res = oddOrEven(15);
	if(res == 1)
	{
		cout << "Odd\n";
	}
	else if(res == 0)
	{
		cout << "Even\n";
	}
	res = oddOrEven(16);
	if(res == 1)
	{
		cout << "Odd\n";
	}
	else if(res == 0)
	{
		cout << "Even\n";
	}
}
