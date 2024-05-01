#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define vi vector<int>
#define endl '\n'

signed main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    int n; cin >> n;
    vi v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    sort(v.begin(), v.end());

    if (v[0] != 1) { cout << 1 << endl; return 0; }
    
    int maxSum = 1;
    for (int i = 1; i < n; i++){
        if (v[i] > maxSum+1) { cout << maxSum+1 << endl; return 0; }
        maxSum += v[i];
    }
    cout << maxSum+1 << endl;

    return 0;
}
