#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long int
#define vi vector<int>

int sum(string s){
    int ans = 0;
    for (int i = 0; i < s.length(); i++){
        ans += s[i] - '0';
    }
    return ans;
}

int ehPrimo(int n){
    if (n == 1) return 0;
    if (n == 2) return 1;
    if (n % 2 == 0) return 0;
    for (int i = 3; i*i <= n; i+=2){
        if (n % i == 0) return 0;
    }
    return 1;
}

signed main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    int l, r;
    cin >> l >> r;

    for (int i = l; i <= r; i++){
        int digitSum = sum(to_string(i));
        if (ehPrimo(i) && ehPrimo(digitSum)) cout << i << endl;
    }


    return 0;
}