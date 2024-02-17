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

signed main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    int n; cin >> n;
    __int128_t ans = 1;
    for (int i = 0; i < n; i++){
        int x; cin >> x;
        ans *= x;
    }

    cout << to_string128(ans) << endl;

    return 0;
}