#include <iostream>
#include <vector>
using namespace std;

int uniqueNumber1(vector<int> arr)
{
	int N = arr.size();
	int XOR = 0;
	for(int i = 0; i < N; ++i)
	{
		XOR = XOR ^ arr[i];
	}
	return XOR;
}

int main()
{
	vector<int> arr = {1,3,5,4,3,1,5}; // unique number is 4
	cout << "Unique Number is : " << uniqueNumber1(arr) << "\n";
}
