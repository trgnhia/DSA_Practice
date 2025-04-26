#include<bits/stdc++.h>

using namespace std;

//link: https://leetcode.com/problems/median-of-two-sorted-arrays/description/?envType=problem-list-v2&envId=array

int main()
{
	vector<int> num1, num2;
	int m,n;
	cin >> m >> n;
	for(int i = 0; i < m ; i++)
	{
		int tmp;
		cin >> tmp;
		num1.push_back(tmp);
	}
	for(int i = 0; i < n ; i++)
	{
		int tmp;
		cin >> tmp;
		num2.push_back(tmp);
	}
	int i =0, j = 0;
	vector<int> mergeRes;
	while(i < m && j < n)
	{
		if(num1[j] <= num2[i])
		{
			mergeRes.push_back(num1[j]);
			j++;
		}
		else
		{
			mergeRes.push_back(num2[i]);
			i++;
		}
	}
	while(i < n)
	{
		mergeRes.push_back(num2[i]);
		i++;
	}
	while(j < m)
	{
		mergeRes.push_back(num1[j]);
		j++;
	}
	if(mergeRes.size() % 2 == 1){
		cout << fixed << setprecision(5) << mergeRes[mergeRes.size()/2];
	}
	else
	{
		int k = mergeRes.size(); 
		cout << fixed << setprecision(5) << float((mergeRes[k/2] + mergeRes[k/2-1]) /2.0 );
	}
	return 0;
}
