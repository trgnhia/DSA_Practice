#include<bits/stdc++.h>

using namespace std;

string solve(int n)
{
	int numFours = 0, numSeven = 0;
	for(int i = n/4; i >= 0; i --)
	{
		int tmp = n - i * 4;
		if(tmp % 7 == 0)
		{
			numFours = i;
			numSeven = tmp/7;
			break;
		}
	}
	string res = "";
	if(numFours == 0 && numSeven == 0) res = "-1";
	else res = string(numFours, '4') + string(numSeven, '7');
	return res;
}

int main()
{
	int n; cin >> n;
	string res = solve(n);
	cout << res;
	return 0;
}