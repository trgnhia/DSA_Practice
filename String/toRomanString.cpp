#include<bits/stdc++.h>

// link leetcode: https://leetcode.com/problems/integer-to-roman/description/?envType=problem-list-v2&envId=string

using namespace std;

string toRoman(int n)
{
	string res = "";
	if(n >= 1000)
	{
		res = string(n/1000, 'M');
	}
	else if(n >= 500)
	{
		int k = n%500;
		if(k == 0) res = "D";
		else if(k >= 100 && k < 400) res = "D" + string(k/100, 'C');
		else res = "CM";
	}
	else if(n>=100)
	{
		int k = n/100;
		if(k < 4) res = string(k,'C');
		else res = "CD";
	}
	else if(n >= 50)
	{
		int k = n%50;
		if(k == 0) res = "L";
		else if(k >= 10 && k < 40) res = "L" + string(k/10, 'X');
		else res = "XC";
	}
	else if(n>=10)
	{
		int k = n/10;
		if(k < 4) res = string(k,'X');
		else res = "XL";
	}
	else if(n >= 5)
	{
		int k = n%5;
		if(k == 0) res = "V";
		else if(k >= 1 && k < 4) res = "V" + string(k, 'I');
		else res = "IX";
	}
	else if(n>=1)
	{
		if(n < 4) res = string(n,'I');
		else res = "IV";
	}
	return res;
}

int main()
{
	int num,i=0;
	cin >> num;
	string number = to_string(num);
	int count = number.length()-1;
	string res = "";
	while(i <= (number.length()-1) )
	{
		char x = number[i];
		int n = (x - '0') * pow(10,count);
		res += toRoman(n);
		i++;
		count --;
	}
	cout << res;
	return 0;
}
