#include <iostream>
#include <vector>
using namespace std;

int countZeros(const vector<int>& A) {
    int l = 0, r = A.size() - 1;
    int result = A.size();
    
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (A[mid] == 1) {
            result = mid;  
            r = mid - 1;   
        } else {
            l = mid + 1;  
        }
    }
    
    return result;
}

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    
    // Nh?p m?ng A
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    
    cout << countZeros(A) << endl;
    return 0;
}

