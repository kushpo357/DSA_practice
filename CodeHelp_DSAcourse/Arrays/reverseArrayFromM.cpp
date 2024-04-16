#include <bits/stdc++.h> 
void reverseArray(vector<int> &arr , int m)
{
	// Write your code here.
	int n = arr.size();
	n--;
	m++;
	while(m < n)
	{
		swap(arr[m], arr[n]);
		m++;
		n--;
	}
	//reverse(arr.begin() + m + 1, arr.end());
}
//Reverse the array from position m onwards
