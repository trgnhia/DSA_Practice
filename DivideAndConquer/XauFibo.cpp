#include<bits/stdc++.h>

using namespace std;

#define ll long long
map<int, ll> mp;

ll stringLen(int n)
{
	if(n <= 2) mp[n] = 1;
	else 
	{
		if(mp[n] == 0) mp[n] = stringLen(n-2) + stringLen(n-1);
	}
	return mp[n];
}

char solve(int n, long long k)
{
	if(n == 1) return 'A';
	if(n == 2) return 'B';
	int len2 = stringLen(n-2);
	if(k <= len2) return solve(n-2,k);
	else return solve(n-1,k-stringLen(n-2));
}

int main()
{
	ll n,k;
	cin >> n >> k;
	cout << solve(n,k);
}
