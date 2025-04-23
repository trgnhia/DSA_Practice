#include<bits/stdc++.h>

using namespace std;

int MOD = 1e9+7;

int main()
{
	int n;
	cin >> n;
	int a[n];
	for(int &x : a) cin >> x;
	sort(a,a+n);
	long long res = 0;
	for(int i = 0; i < n; i++)
	{
		res += 1ll * (i * a[i]); 
		res %= MOD;
	}
	cout << res;
	return 0;
}