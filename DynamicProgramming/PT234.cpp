#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	cin >> n;
//	if(n < 2) cout << 0;
	int dp[n+1];
	memset(dp,0,sizeof(dp));
	dp[0] = 1;
	for(int i = 1; i <= n ; i++)
	{
		if(i >= 2) dp[i] += dp[i-2];
		if(i >= 3) dp[i] += dp[i-3];
		if(i >= 4) dp[i] += dp[i-4];
	}
	cout << dp[n];
	return 0;
}
