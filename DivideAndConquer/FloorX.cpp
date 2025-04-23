#include<bits/stdc++.h>

using namespace std;

int findX(vector<int> &a, int n, int x)
{
	int l = 0;
	int r = n-1;
	int res = -1;
	while(l <= r)
	{
		int mid = (r + l) /2 ;
		if(a[mid] <= x)
		{
			res = a[mid];
			l = mid + 1;
		}
		else r = mid - 1;
	}
	return res;
}

int main()
{
	int n,x;
	cin >> n >> x;
	vector<int> v;
	for(int i = 0; i < n; i++) 
	{
		int tmp; cin >> tmp;
		v.push_back(tmp);
	}
	cout << findX(v,n,x);
	return 0;
}
