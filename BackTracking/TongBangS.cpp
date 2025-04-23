#include <bits/stdc++.h>
using namespace std;

int cnt = 0;

void Try(int n, int k, int s, int curSum, int curSize, int first) {
    if (curSum == s && curSize == k) {
        cnt++;
        return;
    }
    if (curSum > s || curSize > k) return;

    for (int i = first; i <= n; i++) {
        Try(n, k, s, curSum + i, curSize + 1, i + 1);
    }
}

int main() {
    int n, k, s;
    cin >> n >> k >> s;
    Try(n, k, s, 0, 0, 1);
    cout << cnt;
    return 0;
}

