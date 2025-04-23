#include <iostream>
using namespace std;

string vernamCipher(string text, string key) {
    string result = "";
    for (int i = 0; i < text.length(); i++) {
        int p = text[i] - 'A';     // Chuy?n k� t? th�nh s? (0�25)
        int k = key[i] - 'A';      // K� t? kh�a tuong ?ng
        int c = (p ^ k) % 26;      // XOR r?i mod 26
        result += char(c + 'A');   // Chuy?n v? k� t? in hoa
    }
    return result;
}

int main() {
    string text, key;

    cout << "Nhap chuoi can ma hoa (IN HOA): ";
    cin >> text;
    cout << "Nhap khoa (IN HOA, cung do dai): ";
    cin >> key;

    // M� h�a
    string cipher = vernamCipher(text, key);
    cout << "Chuoi ma hoa: " << cipher << endl;

    // Gi?i m�: ch? c?n XOR l?i v?i key
    string decrypted = vernamCipher(cipher, key);
    cout << "Chuoi giai ma: " << decrypted << endl;

    return 0;
}

