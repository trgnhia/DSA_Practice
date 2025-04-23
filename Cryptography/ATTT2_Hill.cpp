#include <iostream>
#include <vector>
using namespace std;

// Tính modulo duong
int mod26(int x) {
    return (x % 26 + 26) % 26;
}


int determinant2x2(const vector<vector<int>>& key) {
    return mod26(key[0][0] * key[1][1] - key[0][1] * key[1][0]);
}

int modInverse(int a) {
    a = a % 26;
    for (int x = 1; x < 26; x++)
        if ((a * x) % 26 == 1)
            return x;
    return -1; 
}


vector<vector<int>> inverseKey2x2(const vector<vector<int>>& key) {
    int det = determinant2x2(key);
    int invDet = modInverse(det);

    if (invDet == -1) {
        cout << "Khong the tim nghich dao ma tran!" << endl;
        exit(1);
    }

    vector<vector<int>> inv(2, vector<int>(2));
    inv[0][0] = mod26(key[1][1] * invDet);
    inv[0][1] = mod26(-key[0][1] * invDet);
    inv[1][0] = mod26(-key[1][0] * invDet);
    inv[1][1] = mod26(key[0][0] * invDet);
    return inv;
}


string hillEncrypt2x2(string text, const vector<vector<int>>& key) {
    string result = "";
    for (int i = 0; i < text.length(); i += 2) {
        int x1 = text[i] - 'A';
        int x2 = text[i + 1] - 'A';

        int y1 = mod26(key[0][0] * x1 + key[0][1] * x2);
        int y2 = mod26(key[1][0] * x1 + key[1][1] * x2);

        result += char(y1 + 'A');
        result += char(y2 + 'A');
    }
    return result;
}

string hillDecrypt2x2(string cipher, const vector<vector<int>>& key) {
    vector<vector<int>> invKey = inverseKey2x2(key);
    string result = "";

    for (int i = 0; i < cipher.length(); i += 2) {
        int y1 = cipher[i] - 'A';
        int y2 = cipher[i + 1] - 'A';

        int x1 = mod26(invKey[0][0] * y1 + invKey[0][1] * y2);
        int x2 = mod26(invKey[1][0] * y1 + invKey[1][1] * y2);

        result += char(x1 + 'A');
        result += char(x2 + 'A');
    }
    return result;
}

int main() {
    string text;
    cout << "Nhap chuoi can ma hoa (do dai chan, IN HOA): ";
    cin >> text;


    if (text.length() % 2 != 0)
        text += 'X';

    vector<vector<int>> key = {
        {3, 3},
        {2, 5}
    };

    string encrypted = hillEncrypt2x2(text, key);
    cout << "Chuoi da ma hoa: " << encrypted << endl;

    string decrypted = hillDecrypt2x2(encrypted, key);
    cout << "Chuoi giai ma: " << decrypted << endl;

    return 0;
}

