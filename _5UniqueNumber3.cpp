#include <iostream>
#include <vector>
using namespace std;

void updateSum(vector<int> &sumArr,int x)
{
	// Extract all bits of x
	for(int i = 0; i < 32; ++i)
	{
		int ith_bit = x & (1<<i);
		if(ith_bit)
			sumArr[i]++;
	}
}

int numFromBits(vector<int> sumArr)
{
	int num = 0;
	for(int i = 0; i < 32; ++i)
		num += (sumArr[i] * (1<<i));
	return num;
}

int uniqueNumber3(vector<int> arr)
{
	int N = arr.size();
	
		vector<int> sumArr(32,0);
		
		for(int x:arr)
			updateSum(sumArr,x);
		for(int i = 0; i < 32; ++i)
			sumArr[i] = sumArr[i] % 3; // 3N or 3N+1
		
		// An array of bits (0 or 1)
		return numFromBits(sumArr);
}

int main()
{
	vector<int> arr = {1,3,5,4,3,1,5,5,3,1};
	int A = uniqueNumber3(arr); cout << A ;
}

