#include<bits/stdc++.h>

using namespace std;

void reverse(int a[], int l, int r, int n)
{
	int mid = n/2;
	while(l <= mid)
	{
		swap(a[l], a[r]);
		l++;
		r--;
	}
}

bool check(int a[], int n)
{
	for(int i = 0; i < n-1 ; i++)
	{
		if(a[i] > a[i+1]) return false;
	}
	return true;
}

int main()
{
	int n; 
	cin >> n;
	int a[n];
	for(int &x : a) cin >> x;
	int mid = n/2;
	int l = mid - 1;
	int r = mid + 1;
	bool ok = true;
	while(!check(a,n))
	{
		reverse(a,l,r,n);
		l--;
		r++;
		if(l < 0 || r > n)
		{
			ok = false;
			break;
		}
	}
	if(ok) cout << "YES";
	else cout << "NO";
	return 0;
}