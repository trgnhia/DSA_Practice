#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll sumMax(int a[], int n)
{
    ll max1 = 0; 
    ll max2 = a[0]; 
    for (int i = 0; i < n; i++) {
        max1 = max((ll)a[i], max1 + a[i]); 
        max2 = max(max2, max1); 
    }
    return max2;
}

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    cout << sumMax(a, n);
    return 0;
}

