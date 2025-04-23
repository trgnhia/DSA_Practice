#include<bits/stdc++.h>

using namespace std;

#define ll long long

int mod = 1e9+7;

int main()
{
	ll n,k;
	cin >> n >> k;
	ll res = 1;
	while(k!=0)
	{
		if(k%2==1) 
		{
			res = (res*n) % mod;
		}
		k/=2;
		n = (n*n)%mod;
	}
	cout << res;
	return 0;
}
