#include<bits/stdc++.h>

using namespace std;

int MOD = 1e9+7;

long long maxCost(vector<long long> &ropes)
{
	// hang doi uu tien voi cac phan tu giam dan
	priority_queue<long long, vector<long long>, less<long long>> pq(ropes.begin(), ropes.end());
	long long MaxCost = 0;
	while(pq.size() > 1)
	{
		long long first = pq.top(); 
		pq.pop();
		long long second = pq.top();
		pq.pop();
		long long cost = (first+second) 
		MaxCost = (MaxCost + cost) 
		pq.push(cost);
	}
	return MaxCost % MOD; ;
int main()
{
	int n;
	cin >> n;
	vector <long long> v(n);
	for(int i = 0; i < n ; i++)
	{
		cin >> v[i];
	}
	cout << maxCost(v);
	return 0;
}