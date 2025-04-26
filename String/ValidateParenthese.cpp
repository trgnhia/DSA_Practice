#include<bits/stdc++.h>

using namespace std;

int main()
{
	string s; stack<char> st;
	cin >> s;
	bool check = true;
	for(char c : s)
	{
		if(c == '{' || c== '[' || c == '(')
		st.push(c);
		else{
			if(st.empty()) check = false;
			else{
				char close = st.top();
			if(c == '}')
			{
				if(close == '{') st.pop();
				else check = false;
			}
			if(c == ']')
			{
				if(close == '[') st.pop();
				else check = false;
			}
			if(c == ')')
			{
				if(close == '(') st.pop();
				else check = false;
			}
			}
		}
	}
	if(!st.empty()) check = false;
	return check
	cout << check;
	return 0;
}
