#include <bits/stdc++.h> 
vector<int> findArraySum(vector<int>&a, int n, vector<int>&b, int m) {
	// Write your code here.

	if(n < m)
	{
		a.swap(b);
		swap(n, m);
	}

	vector<int> ans;

	int i = m - 1, j = n - 1;

	int carry = 0;
	while(i >= 0)
	{
		ans.push_back((a[j] + b[i] + carry) % 10);
		carry = (a[j] + b[i] + carry)/10;
		i--;
		j--;
	}

	while(j >= 0)
	{
		ans.push_back((a[j] + carry) % 10);
		carry = a[j] + carry;
		carry /= 10;
		j--;
	}

	if(carry) ans.push_back(carry);
	reverse(ans.begin(), ans.end());

	return ans;
}
//Add the two numbers given in the form of integer Arrays
