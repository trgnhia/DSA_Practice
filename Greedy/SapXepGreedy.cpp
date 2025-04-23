#include<bits/stdc++.h>

using namespace std;

int main()
{
	int n; cin >> n;
	int a[n], b[n];
	for(int i = 0; i < n ; i++)
	{
		cin >> a[i];
		b[i] = a[i];
	}
	sort(b,b+n);
	bool ok = true;
	for(int i = 0; i < n ; i++)
	{
		if(a[i] != b[i] && a[i] != b[n-i-1])
		{
			ok = false;
			break;
		}
	}
	if(ok) cout << "YES";
	else cout << "NO";
	return 0;
}