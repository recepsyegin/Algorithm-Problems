#include <iostream>
#include <vector>
using namespace std;

void uniqueNumber2(vector<int> arr)
{
	int N = arr.size();
	
	int result = 0;
	for(int i = 0; i < N; ++i)
	{
		result = result ^ arr[i];
	}
	// Pos
	int pos = 0;
	int temp = result;
	while((temp&1) == 0)
	{
		pos++;
		temp = temp >> 1;
	}
	
	// Filter out the numbers from the array which have set bit at 'pos'
	int setA = 0;
	int setB = 0;
	int mask = (1<<pos);
	
	for(int i = 0; i < N; ++i)
	{
		if((arr[i] & mask) > 0)
			setA = setA ^ arr[i];
		else
			setB = setB ^ arr[i];
	}
	cout << setA << endl;
	cout << setB << endl;
}

int main(){
	vector<int> arr = {1,3,5,4,3,1,5,7};
	uniqueNumber2(arr);
}
