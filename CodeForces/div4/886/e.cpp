#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long int
#define vi vector<int>

void solve(){
    int n, c;
    cin >> n >> c;
    vi s(n);
    for (int i = 0; i < n; i++) cin >> s[i];
    int sum = 0;
    for (int i = 0; i < n; i++) sum += s[i]*s[i];
    c-= sum;

    int left = 1;
    int right = 1e9;
    int w;
    while(left <= right){
        w = (left+right)>>1;
        int area = 0;
        for (int i = 0; i < n; i++){
            area += 2*w*(s[i]+2*w) + 2*s[i]*w;
            if (area > 1e18) break;    
        }
        
        if (area == c) break;
        if (area < c) left = w+1;
        else right = w-1;
    }
    cout << w << endl;
}

signed main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    int t; cin >> t;
    while(t--) solve();

    return 0;
}