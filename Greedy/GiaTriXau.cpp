#include<bits/stdc++.h>

using namespace std;

long long solve(map<char, int> &freqMap, int k)

{
	// khoi tao maxheap de luu tan suat
	long long tong = 0;
	priority_queue <int> maxHeap;
	for(auto it : freqMap)
	{
		maxHeap.push(it.second);
	}
	while(k-- > 0 && !maxHeap.empty())
	{
		int top  = maxHeap.top();
		maxHeap.pop();
		if(top > 0){
			maxHeap.push(top-1);
		}
	}
	while(!maxHeap.empty())
	{
		int top = maxHeap.top();
		tong += pow(top,2);
		maxHeap.pop();
	}
	return tong;
}


int main()
{
	int t; cin >> t;
	while(t--)
	{
		map<char, int> mp;
		int k; cin >> k;
		string s; cin >> s;
		for(char c : s) mp[c]++;
		long long res = solve(mp,k);
		cout << res << endl;
		//for(auto it : mp) cout << it.second << " ";
	}
	return 0;
}