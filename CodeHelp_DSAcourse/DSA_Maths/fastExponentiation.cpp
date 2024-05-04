//https://www.naukri.com/code360/problems/modular-exponentiation_1082146?utm_source=youtube&utm_medium=affiliate&utm_campaign=love_babbar_7&leftPanelTabValue=PROBLEM
#include <bits/stdc++.h>
int modularExponentiation(int x, int n, int m) {
	// Write your code here.

	int ans = 1;

	while(n > 0)
	{
		if(n & 1)
		{
			ans = (1ll*(ans)*(x)%m)%m;
		}
		x = (1ll *(x) %m*(x)%m)%m;
		n = n >> 1;
	}

	return ans;
}
