#include <bits/stdc++.h>
using namespace std;

int MOD = 1e9+7;

long long minCost(vector<long long> &ropes) {
	// khoi tao hang doi chua cac phan tu thu tu tang dan
    priority_queue<long long, vector<long long>, greater<long long>> pq(ropes.begin(), ropes.end());

    long long totalCost = 0;
    while (pq.size() > 1) {
        long long first = pq.top(); pq.pop();
        long long second = pq.top(); pq.pop();
        long long cost = first + second;
        totalCost += cost;
        pq.push(cost);
    }

    return totalCost % MOD;
}

int main() {
    int n;
    cin >> n;
    vector<long long> ropes(n);
    for (int i = 0; i < n; i++) {
        cin >> ropes[i];
    }
    cout << minCost(ropes) << endl;
    return 0;
}
