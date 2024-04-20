#include <bits/stdc++.h>
using namespace std;

#define int long long int

bool isPalyndromic(int n){
    string s = to_string(n);
    for (int i = 0; i < s.length()/2; i++)
        if (s[i] != s[s.length()-i-1]) return false;
    return true;
}

signed main(){
    int n, ans = 0; cin >> n;
    for (int i = 0; i*i*i <= n; i++){
        if (isPalyndromic(i*i*i))
            ans = i*i*i;
    }
    cout << ans << endl;

}