#include<bits/stdc++.h>

using namespace std;

int main()
{
	string s;
	cout << "Nhap chuoi can ma hoa: "; getline(cin,s);
	string key;
	map<char,int> mp;
	cout << "Nhap chuoi key khong co ki tu nao trung nhau: "; cin >> key;
	for(char c : key) 
	{
		if(c == 'I') c = 'J';
		mp[c]++;
	}
	string res = key;
	for(char i = 'A'; i <= 'Z'; i++)
	{
		if(i != 'I')
		if(mp[i] == 0)
		{
			res += i;
			mp[i] = 1;
		}
	}
	cout << res << endl;
	vector<vector<char>> table(5,vector<char>(5));
		int k = 0;
	for(int i = 0; i < 5; i++)
	{
		for(int j = 0; j < 5 ; j++)
		{
			table[i][j] = res[k];
			k++;
		}
	}
	for(int i = 0; i < s.length()-1; i++)
	{
		if(s[i] == s[i+1])
		{
			s.insert(i+1,1,'X');
			i++;
		}
	}
	if(s.length()%2 != 0)
	s += 'X';
	string encrypt = "";
	for(int i = 0; i < s.length(); i+= 2)
	{
		char a = s[i], b = s[i+1];
		if (a == 'I') a = 'J';
    	if (b == 'I') b = 'J';

		pair<int,int> pa,pb;
		for (int x = 0; x < 5; x++) {
        for (int y = 0; y < 5; y++) {
            if (table[x][y] == a) pa = {x, y};
            if (table[x][y] == b) pb = {x, y};
        }
    }
    if(pa.first == pb.first){
    	// cung hang
    	encrypt += table[pa.first][(pa.second + 1) % 5];
    	encrypt += table[pb.first][(pb.second + 1) % 5];
	}
	else if(pa.second == pb.second)
	{
		 encrypt += table[(pa.first + 1) % 5][pa.second];
        encrypt += table[(pb.first + 1) % 5][pb.second];
	}
	else{
		encrypt += table[pa.first][pb.second];
        encrypt += table[pb.first][pa.second];
	}
}
	cout << "Chuoi sau khi ma hoa: " << encrypt << endl;
	return 0;
}
