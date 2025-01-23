#include <iostream>
#include <cstring>
using namespace std;

void overlayNumber(char arr[],int number)
{
	int j = 0;
	while(number)
	{
		int last_bit = number & 1;
		if(last_bit)
			cout << arr[j];
		j++;
		number = number >> 1;
	}
	cout << '\n';
}

void generateAllSubsequences(char arr[])
{
	int N = strlen(arr);
	for(int i = 0; i < (1<<N); ++i)
		overlayNumber(arr,i);
}

int main()
{
	char arr[512];
	cin >> arr;
	generateAllSubsequences(arr);
/*
input : abcde
outputs : (all subsequences)
a
b
ab
c
ac
bc
abc
d
ad
bd
abd
cd
acd
bcd
abcd
e
ae
be
abe
ce
ace
bce
abce
de
ade
bde
abde
cde
acde
bcde
abcde

*/
}
