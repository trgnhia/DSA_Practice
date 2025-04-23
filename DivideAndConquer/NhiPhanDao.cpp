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

int reverse(int n)
{
	int k = 0;
	while(n!=0)
	{
		int i = n % 10;
		k = k * 10 + i;
		n /= 10; 
	}
	return k;
}

int main()
{
	ll n;
	cin >> n;
	int k = reverse(n);
	cout << Pow2(n,k);
	return 0;
} 
