#include<bits/stdc++.h>

using namespace std;
int main()
{
	int n;
	cin >> n;
	
	int a[n];
	vector<int> L(n,1);
	for(int &x : a) cin >> x;
	for(int i = 0; i < n; i ++)
	{
		for(int j = 0 ; j < i; j++)
		{
			if(a[i] > a[j])
			L[i] = max(L[i], L[j]+1);
		}
	}
	sort(L.begin(), L.end());
//	for(int i =0 ; i < n; i++) cout << L[i] << " ";
	cout << L[n-1];
	return 0;
}
