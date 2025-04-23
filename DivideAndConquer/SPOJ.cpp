#include<bits/stdc++.h>
#define ll long long 
using namespace std;

int mod = 1e9+7;
map<int, ll> mp;
ll solve(int n)
{
	if(n == 0) return mp[n] = 0;
	else if (n == 1) return mp[n] = 1;
	else
	{
		if(mp[n] == 0) 
	    mp[n] = (solve(n - 1) + solve(n - 2)) % mod;
	}
	return mp[n] % mod;
}

int main()
{
	int n; cin >> n;
	cout << solve(n);
}
