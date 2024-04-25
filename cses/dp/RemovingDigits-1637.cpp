#include <bits/stdc++.h>
using namespace std;

#define INF 1123456789

vector<int> memo;

int dp(int n){
    if (memo[n] != INF)
        return memo[n];
    string s = to_string(n);
    for (int i = 0; i < s.length(); i++){
        int digit = s[i] - '0';
        memo[n] = min(memo[n], dp(n-digit) + 1);
    }
    return memo[n];
}

int main(){
    int n; cin >> n;
    memo = vector<int>(n+1, INF);
    for (int i = 0; i < 10 && i <= n; i++) memo[i] = 1;
    cout << dp(n) << endl;

    return 0;
}