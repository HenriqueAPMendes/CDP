#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define endl '\n'
#define vi vector<int>
#define ii pair<int,int>

signed main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    vi v;
    int x;
    while(cin >> x) v.push_back(x);
    int n = v.size();

    vi maxsub(n, 1);

    for (int i = n-1; i >= 0; i--){
        for (int j = i; j < n; j++){
            if (v[j] > v[i]) maxsub[i] = max(maxsub[i], maxsub[j]+1);
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++) ans = max(maxsub[i], ans);
    cout << ans << endl;

    return 0;
}