#include<bits/stdc++.h>
using namespace std;

int n, X[100],used[100];
void inkq()
{
	for(int i = 1; i <= n ; i++)
	{
		cout << X[i] << " ";
	}
	cout << endl;
}

void Try(int i)
{
	for(int j = 1; j <= n ; j++)
	{
		if(used[j] == 0)
		{
			X[i] = j;
			used[j] = 1;
			if(i == n) inkq();
			else 
			Try(i+1);
			used[j] = 0;
		}
	}
}

int main()
{
	cin >> n;
	memset(used,0,sizeof(used));
	Try(1);
	return 0;
}
