#include <bits/stdc++.h>
using namespace std;

int minimum(int *arr, int num)
{
	int ans = 101, index = -1;
	for (int i = 0; i < num; ++i)
	{
		if (arr[i] < ans)
		{
			ans = arr[i];
			index = i;
		}
	}
	return index;
}

void reverseArr(int *arr, int start, int end)
{
	reverse(arr + start, arr + end + 1);
}

int cost(int *arr, int num)
{
	int count = 0;
	for (int i = 0; i <= num-2 ; ++i)
	{
		int minValIndex = min_element(arr + i, arr + num)-arr;
		reverseArr(arr, i, minValIndex);
		count=count+ minValIndex - i + 1;
	}
	return count;
}

int main()
{
	int t,i;
	cin>>t;
	for ( i=0; t>i; i++)
	{
		int n;
		cin >> n;
		int *arr = new int[n];
		for (int j = 0; n>j; j++)
			cin >> arr[j];
		
		cout << "Case #" << i + 1 << ": " << cost(arr, n) << "\n";
	}
	return 0;
}
