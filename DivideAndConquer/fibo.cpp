#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

vector<vector<long long>> multiply(vector<vector<long long>>& A, vector<vector<long long>>& B) {
    vector<vector<long long>> result(2, vector<long long>(2));
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            result[i][j] = 0;
            for (int k = 0; k < 2; ++k) {
                result[i][j] = (result[i][j] + A[i][k] * B[k][j]) % MOD;
            }
        }
    }
    return result;
}


vector<vector<long long>> power(vector<vector<long long>>& A, long long n) {
    vector<vector<long long>> result(2, vector<long long>(2));
    
    result[0][0] = result[1][1] = 1;
    result[0][1] = result[1][0] = 0;

    while (n > 0) {
        if (n % 2 == 1) {
            result = multiply(result, A); 
        }
        A = multiply(A, A); 
        n /= 2;
    }
    return result;
}

long long fib(long long n) {
    if (n == 0) return 0;
    
    
    vector<vector<long long>> F = {{1, 1}, {1, 0}};
    vector<vector<long long>> result = power(F, n - 1);
    
    
    return result[0][0];
}

int main() {
    long long n;
    cin >> n;
    cout << fib(n) << endl;
    return 0;
}

