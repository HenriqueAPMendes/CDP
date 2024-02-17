#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define vi vector<int>
#define ii pair<int,int>
#define endl '\n'

string to_string128(__int128_t t){
    string ans;
    while (t > 0){
        ans += ('0'+t%10);
        t /= 10;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

vector<__int128_t> v(110);

__int128_t tribonacci(__int128_t n){
    if (n == 1 or n == 2 or n == 3) return 1;
    for (int i = 4; i <= n; i++) v[i] = v[i-1]+v[i-2]+v[i-3];
    return v[n];
}

signed main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    v[1]=v[2]=v[3]=1;

    int n; cin >> n;
    __int128_t ans = tribonacci((__int128_t)n);

    string s = to_string128(ans);
    cout << s << endl;

    return 0;
}