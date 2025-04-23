#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	cin >> n;
	int a[n];
	int b[n];
	for(int &x : a)
	{
		cin >> x;
	}
	for(int &x : b) cin >> x;
	long long res =0;
	sort(a,a+n, greater<int>());
	sort(b,b+n, greater<int>());
	for(int i = 0 ; i < n ; i++)
	{
		res += a[i] * b[i];
	}
	cout << res;
	return 0;
}