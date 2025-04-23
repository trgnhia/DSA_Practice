#include<bits/stdc++.h>

using namespace std;

void soNguyenK(string s)
{
	//thuat toan 1 : Cong so nguyen k ra chuoi moi: 
	int k;
	string res = "";
	cout <<"Nhap so nguyen k: ";
	cin >> k;
	cout << "Chuoi ma hoa la: ";
	for(char c : s){
		c+= k;
		cout << c;
		res+= c;
	}
	cout << endl << res << endl;
	cout << endl << "Chuoi giai ma la: " << endl;
	for(char c : res)
	{
		c-=k;
		cout << c;
	}
}

void CaesarBaoChua(string s)
{
	cout << "Nhap so nguyen k: ";
	int k; cin >> k;
	string res = "";
	for(int i = 0 ; i < s.length(); i++)
	{
		if(isalpha(s[i]))
		res += (s[i] - 'A' + k) % 26 + 'A';
		else res += s[i];
	}
	cout << "Chuoi sau khi ma hoa la: " << res << endl;
	cout << "Chuoi giai ma la: " << endl;
	for(int i = 0; i < res.length(); i ++)
	{
		if(isalpha(res[i]))
		res[i] = (res[i] - 'A' - k + 26) % 26 + 'A';
	}
	cout << res;
	
}

// ham tim a-1
int modVerse26(int a)
{
	a = a % 26;
	for(int i = 1; i < 26 ; i++)
	{
		if((a*i) % 26 == 1) return i;
	}
	return -1;
}

void Affine(string s)
{
	/*
	cong thuc ma hoa : E(x) = (a * x + b) mod 26
	cong thuc giai ma: D(y) = a-¹ * (y - b) mod 26
	x la so thu tu dau vao cua ki tu: A = 0, B = 1, ...., Z = 25
	a,b la 2 khoa nguyen voi a la so nguyen to cung nhau voi 26 => GCD(a,26) = 1
	a-1 la nghich dao modular cua a theo mod 26 sao cho (a*a-1)%26 = 1. vi du a = 5 => á-1 = 21 vi 5*21 % 26 = 1
	*/
	int a,b;
	cout << "Nhap 2 khoa a va b (luu y nhap a hop le sao cho gcd(a,26)=1 ): ";
	cin >> a >> b;
	b%=26; // de phong b qua lon
	string res  = "";
	for(char c : s)
	{
		if(isalpha(c))
		{
			int x = c-'A';
			int y =  (a * x + b) % 26;
			res += char(y + 'A');
		} else res += c;
	}
	cout << "Chuoi sau khi ma hoa la: " << res << endl;
	if(modVerse26(a) == -1) cout << "Khong the giai ma vi khong ton tai nghich dao cua a theo mod26 voi a = " << a << endl;
	else{
		string decrypt = "";
		int a_verse = modVerse26(a);
		cout << "Chuoi giai ma la: ";
		for(char c : res)
		{
			if(isalpha(c))
			{
			int y = c-'A';
			int x = (a_verse*(y-b+ 26)) % 26;
			decrypt +=  char(x + 'A');	
			}
			else decrypt += c;
		}
		cout << decrypt << endl;	
	}
	
}

void Monoalphabetic(string s)
{
	string key = "QWERTYUIOPASDFGHJKLZXCVBNM";
	map<char,char> mp;
	map<char,char> decryptMap;
	int j = 0;
	for(char i = 'A'; i <= 'Z'; i++)
	{
		mp[i] = key[j];
		decryptMap[key[j]] = i;
		j++;
	}
	string res = "";
	for(char c : s)
	{
		if(isalpha(c)) res+= mp[c];
		else res+= c;
	}
	cout << "chuoi ma hoa la: " << res << endl;
	string decrypt = "";
	for(char c : res)
	{
		if(isalpha(c)) decrypt += decryptMap[c];
		else decrypt += c;
	}
	cout << "chuoi giai ma la: " << decrypt << endl;
}

void PolyalphaBetic(string s)
{
	cout << "Nhap key co chieu dai bang voi plaintext (in hoa): ";
	string key; cin >> key;
	string cipher = "";
	for(int i =0 ; i < s.length(); i++)
	{
		int p = s[i] - 'A';
		int k = key[i] - 'A';
		char c = (p+k) % 26 + 'A'; 
		cipher += c;
	}
	cout << "Chuoi ma hoa la: " << cipher << endl;

    string decrypted = "";
    for (int i = 0; i < cipher.length(); i++) {
        int c = cipher[i] - 'A';
        int k = key[i] - 'A';
        char p = (c - k + 26) % 26 + 'A'; 
        decrypted += p;
    }

    cout << "Chuoi giai ma la: " << decrypted << endl;
}

int main()
{
	string s;
	cout << "Nhap chuoi can ma hoa: ";
	getline(cin,s);
	// chuyen ve chu in hoa
	for (int i = 0; i < s.length(); i++)
	{
		s[i] = toupper(s[i]);
	}
	//soNguyenK(s);
	//CaesarBaoChua(s);
	//Affine(s);
	//Monoalphabetic(s);
	PolyalphaBetic(s);
	return 0;

}
