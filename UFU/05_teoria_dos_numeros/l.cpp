#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int unsigned long long int
#define vi vector<int>

int ehPrimo(int n){
    if (n == 1) return 0;
    if (n == 2) return 1;
    if (n % 2 == 0) return 0;
    for (int i = 3; i*i < n; i+=2){
        if (n % i == 0) return 0;
    }
    return 1;
}
signed main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        cout << ehPrimo(n)<< endl;
    }

    return 0;
}