#include<bits/stdc++.h>
#define ll long long
using namespace std;

int mod = 1e9+7;

ll Pow2(ll n,ll k)
{
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
	return res % mod;
}

int main()
{
	ll n; cin >> n;
	ll k = n-1;
	cout << Pow2(2,k);
	return 0;
}
