#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define ii pair<int,int>
#define vi vector<int>
#define MAX 212345
#define endl '\n'

void solve(){
    int n; cin >> n;
    vi ltrace(26);
    for (int i = 0; i < n; i++) {
        int nxt;
        cin >> nxt;
        for (int i = 0; i < 26; i++)
            if (ltrace[i] == nxt){
                ltrace[i]++;
                char c = 'a'+i;
                cout << c;
                break;
            }
    }
    cout << endl;
}

signed main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    int t; cin >> t;
    while(t--) solve();

    return 0;
}