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

__int128_t expbin(int a, int b){
    if (b == 0) return 1;
    if (b&1) return a*expbin(a,b-1);
    int x = expbin(a,b/2);
    return x*x;
}

void solve(int n){
    __int128_t total = 10*expbin(9,n-1);
    cout << to_string128(total) << endl;
}

signed main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    int n; cin >> n;
    solve(n);

    return 0;
}