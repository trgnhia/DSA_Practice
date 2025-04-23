#include <bits/stdc++.h>

using namespace std;

void change(string &s, int k, int k2)
{
	char oldChar = k + '0';
	char newChar = k2 + '0';
	for(int i = 0; i < s.length(); i++)
	{
		if(s[i] == oldChar) s[i] = newChar;
	}
}

int main()
{
	long long a,b;
	cin >> a >> b;
	string s1 = to_string(a);
	string s2 = to_string(b);
	change(s1,5,6);
	change(s2,5,6);

	a = stoll(s1);
	b = stoll(s2);
	cout << a + b << " ";
	change(s1,6,5);
	change(s2,6,5);
	a = stoll(s1);
	b = stoll(s2);
	cout << a + b << " ";
	return 0;
}