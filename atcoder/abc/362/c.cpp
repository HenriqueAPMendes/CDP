#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define endl '\n'
#define ii pair<int,int>
#define vi vector<int>
#define vii vector<ii>
#define vvi vector<vi>

void solve(){
    int n; cin >> n;
    vi l(n), r(n);
    int minSum = 0, maxSum = 0;
    vi minS(n), maxS(n);
    for (int i = 0; i < n; i++) {
        cin >> l[i] >> r[i];
        minSum += l[i];
        maxSum += r[i];
        minS[i] = minSum;
        maxS[i] = maxSum;
    }
    if (minSum > 0 || maxSum < 0) {cout << "No" << endl; return;}

    // É possível, construir gulosamente?
    cout << "Yes" << endl;
    int target = 0;
    for (int i = n-1; i >= 0; i--){
        // compara i e i-1
        
    }
    
    

}

signed main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);
    solve();
    return 0;
}