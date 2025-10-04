#include <bits/stdc++.h>
using namespace std;

long long power(long long base, int exp) {
    long long result = 1;
    for(int i = 0; i < exp; i++) {
        if(result > 1e9) return 1e18;
        result *= base;
    }
    return result;
}

int nthRoot(int n, long long m) {
    long long low = 1, high = m, ans = -1;
    while(low <= high) {
        long long mid = (low + high) / 2;
        long long val = power(mid, n);
        if(val == m) return mid;
        else if(val < m) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}

int main() {
    int n;
    long long m;
    cin >> n >> m;
    cout << nthRoot(n, m) << endl;
    return 0;
}
