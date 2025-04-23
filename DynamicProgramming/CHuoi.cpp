#include <bits/stdc++.h>
using namespace std;

int mod = 1e9;

int main() {
    string S;
    cin >> S;
    int N = S.length();

    set<string> uniqueSubstrings;

    for (int mask = 1; mask < (1 << N); ++mask) {
        string substring = "";
        for (int i = 0; i < N; ++i) {
            if (mask & (1 << i)) { 
                substring += S[i];
            }
        }
        uniqueSubstrings.insert(substring);
    }
    cout << uniqueSubstrings.size() % mod << endl;

    return 0;
}

