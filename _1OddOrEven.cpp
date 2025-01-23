#include <iostream>

#include <stdio.h>
using namespace std;


void oddOrEven(int x)
{
	if(x & 1 == 1)
		printf("%d sayisi tektir.\n",x);
	else
		printf("%d sayisi cifttir.\n",x);
	
}

int getIthBit(int n,int x)
{
	int mask = 1 << x;
	return (n & mask) > 0 ? 1 : 0;
}

void setIthBit(int &n,int x)
{
	int mask = (1<<x);
	n = (n|mask);
}

void clearIthBit(int &n,int x)
{
	int mask = ~(1 << x);
	n = n & mask;
	printf("%d\n",n);
}
void updateIthBit(int &n,int i,int v)
{
	clearIthBit(n,i);
	int mask = (v << i);
	n = n | mask;
}

int clearLastIBits(int n,int i)
{
	int mask = (-1 << i); // 11111 -> 111000
	n = n & mask;
	return n;
}

void clearRangeOfBits(int n,int i,int j)
{
	int mask_a = (~0) << (j+1);
	int mask_b = (1<<i) - 1;
	int mask = mask_a | mask_b;
	n = n & mask;
	
	//printf("%d\n",n);
}

void replaceBits(int &n,int i, int j ,int m)
{
	clearRangeOfBits(n,i,j);
	int mask = (m << i);
	n = n | mask;
}


void isPowerOfTwo(int n)
{
	if((n & (n-1)) == 0)
		printf("%d is power of two\n",n);
	else
		printf("%d is not power of two\n",n);
}


int countSetBitsTekrar(int n)
{
        int ans = 0;
        while(n)
        {
            ans += n & 1;
            n = n >> 1;
        }
        return ans;
    
}

void CountSetBits(int n)
{
	int count = 0;
	
	while(n)
	{
		int last_bit = (n&1);
		count += last_bit;
		n = n >> 1;
	}
	cout << "Set Bit Sayisi: " << count << "\n";
}

int countSetBitsFasterMethod(int n)
{
	int ans = 0;
	while(n>0)
	{
		n = n & (n-1);
		ans++;
	}
	return ans;
}

int ConvertToBinary(int n)
{
	int ans = 0;
	int p = 1;
	
	while(n > 0)
	{
		int last_bit = n & 1;
		ans = ans + (last_bit * p);
		p = p*10;
		n = n >> 1;	
	}
	return ans;
	
}


int main()
{
	//oddOrEven(5);
	//oddOrEven(6);
	//printf("%d\n",getIthBit(5,0));
	//int n = 5;
	//setIthBit(n,1); printf("%d\n",n);
	//int a = 13;
	//clearIthBit(a,2); // 9
	//clearIthBit(a,0); // 8
	//int n = 13;
	//updateIthBit(n,1,1);
	//printf("%d\n",n); // 15
	//int n = 15;
	//printf("%d\n",clearLastIBits(n,3));
	
	//clearRangeOfBits(15,0,2);
	
	
	//int n = 15,i = 1, j = 3, m = 2;
	//replaceBits(n,i,j,m);
	//printf("%d\n",n);
	
	//int n = 16;
	//isPowerOfTwo(n);
	//isPowerOfTwo(17); isPowerOfTwo(32); isPowerOfTwo(31); isPowerOfTwo(64); 
	
	//CountSetBits(31); // 5
	
	//cout << countSetBitsFasterMethod(15); // 4
	
	//cout << ConvertToBinary(5);
	
	
	
	return 0;
}
