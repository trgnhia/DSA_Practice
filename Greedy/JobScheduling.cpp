#include<bits/stdc++.h>

using namespace std;

bool comparator(pair<int,int> x, pair <int, int> y )
{
	return x.second < y.second;
}

int main()
{
	int n;
	cin >> n;
	pair<int,int> a[n];
	for(int i = 0; i < n ; i++)
	{
		cin >> a[i].first >> a[i].second;
	}
	sort(a,a+n, comparator);
	int cnt = 1;
	int start = a[0].first,end = a[0].second;
	for(int i = 0 ; i < n - 1 ; i++)
	{
		if(end < a[i].first)
		{
			end = a[i].second;	
			cnt++;
		}
	}
	cout << cnt;
	return 0;
}