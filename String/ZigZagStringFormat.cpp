#include<bits/stdc++.h>

//https://leetcode.com/problems/zigzag-conversion/description/?envType=problem-list-v2&envId=string

using namespace std;
// code 8ms


//int main()
//{
//	string s,res = ""; cin >> s;
//	int rows;
//	cin >> rows;
//	if(rows == 1) res = s;
//	else
//	{
//		for(int i = 0; i < rows; i++){
//		int j = i;
//		int x = 1;
//		while(j < s.length()){
//			res += s[j];
//			if(i == 0 || i == rows-1) j += (rows-1)*2;
//			else 
//			{
//				if(x % 2 == 1)	j+= (rows-i-1)*2;
//				else j += (i*2);
//				x++;
//			} 
//		}
//		}
//	}
//	cout << res;
//	return 0;
//}
//

// code này 7ms
class Solution {
public:
    string convert(string s, int rows) {
        if (rows == 1 || s.length() <= rows) {
            return s;
        }

        vector<string> rowStrings(rows);
        int currentRow = 0;
        bool goingDown = false; 

        for (char c : s) {
            rowStrings[currentRow] += c;

            if (currentRow == 0 || currentRow == rows - 1) {
                goingDown = !goingDown; 
            }

            currentRow += (goingDown ? 1 : -1);
        }

        string res;
        for (const string& row : rowStrings) {
            res += row;
        }

        return res;
    }
};

int main() {
    string s;
    int rows;

    cout << "Nhap chuoi: ";
    cin >> s;

    cout << "Nhap so dong: ";
    cin >> rows;

    Solution solution;
    string result = solution.convert(s, rows);

    cout << "Chuoi sau khi chuyen doi: " << result << endl;

    return 0;
}

