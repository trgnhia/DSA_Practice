#include<bits/stdc++.h>

using namespace std;

int n, c[105][105], X[100];
int visited[100];
int d = 0, ans = INT_MAX, cmin = INT_MAX;
void nhap()
{
	for(int i = 1; i <= n ; i++)
	{
		for(int j = 1; j <= n ; j++)
		{
			cin >> c[i][j];
			if(c[i][j] != 0) cmin = min(c[i][j], cmin);
		}
	}
	memset(visited,0,sizeof(visited));
}

void Try(int i)
{
	for(int j = 1; j <= n; j++)
	{
		if(visited[j] == 0)
		{
			visited[j] = 1;
			X[i] = j;
			d+= c[X[i-1]][X[i]];
			if(i == n){
				ans = min(ans, d+c[X[n]][1]);
			}
				else if(d + (n-i+1) * cmin < ans)
			{
			Try(i+1);
			}
			visited[j] = 0;
			d -= c[X[i-1]][X[i]];
		}
	}
}

int main()
{
	cin >> n;
	nhap();
	X[1] = 1;
	visited[1] = 1;
	Try(2);
	cout << ans << endl;
	return 0;
}
