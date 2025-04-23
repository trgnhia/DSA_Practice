#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n,m;
	cout << "Nhap m = ";
	cin >> m;
	int a[m];
	for(int i = 1 ; i <= m ; i++)
	{
		cout << "a[" << i << "] = ";
		cin >> a[i];
	}
	cout << "Nhap n = ";
	cin >> n; int b[n];
	for(int i = 1 ; i <= n ; i++)
	{
		cout << "b[" << i<< "] = ";
		cin >> b[i];
	}
	int dp[m+1][n+1];
	memset(dp,0, sizeof(dp));
	for(int i = 1; i <= m; i++)
	{
		for(int j = 1; j <= n ; j++)
		{
			if(a[i] == b[j]){
				dp[i][j] = dp[i-1][j-1] + a[i];
			}
			else
			dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
		}
	}
//	
//	for(int i = 1; i <= m; i++)
//	{
//		for(int j = 1; j <= n ; j++)
//		{
//			cout << dp[i][j] << " ";
//		}
//		cout << endl;
//	}
	
	
	cout << "Day con co tong lon nhat = " << dp[m][n];
}
