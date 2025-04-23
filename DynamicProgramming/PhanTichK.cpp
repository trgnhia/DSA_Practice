#include<bits/stdc++.h>

using namespace std;

int main()
{
	int k;
	cout << "Nhap k = ";
	cin >> k;
	int dp[k+1][k+1];
	memset(dp,0,sizeof(dp));
	for(int j = 0; j <= k ; j++) dp[0][j] = 1;
	for(int i = 1; i <= k ; i++)
	{
		for(int j = 1; j <= k ; j++)
		{
			dp[i][j] = dp[i][j-1];
			if(i >= j)
			{
				dp[i][j] += dp[i-j][j-1];
			}
		}
	}
	cout << "Co tat ca " << dp[k][k-1] << " cach phan tich.";
	return 0;
}
