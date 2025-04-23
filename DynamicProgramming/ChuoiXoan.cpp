#include<bits/stdc++.h>

using namespace std;

char solve(long long N, string &s)
{
	long long len = s.length();
	long long curLen = len;
	while(curLen <= N) {
		curLen *= 2;
	}
	while (curLen > len)
	{
		if (N >= curLen/ 2) {
            N = curLen - N - 1;
        }
        curLen/= 2;
	}
	return s[N];
}

int main()
{
	string s;
	cin >> s;
	int m;
	cin >> m;
	while(m--)
	{
		long long n; cin >> n;
		cout << solve(n,s) << endl;
	}
	return 0;
}
