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
    for (int i = 0; i < n; i++) {
        cin >> l[i] >> r[i];
        minSum += l[i];
        maxSum += r[i];
    }

    int diff_max = 0;
    for(int i = 0; i < n; i++)
        diff_max += r[i] - l[i];
   
    int max_sum = 0;
    for(int i = 0; i < n; i++)
        max_sum += r[i];

    if (minSum > 0 || maxSum < 0) {cout << "No" << endl; return;}
    if(max_sum - diff_max > 0){ cout << "No" << endl; return; }

    vi sequence(n);
    for(int i = 0; i < n; i++){
        if(max_sum - (r[i] - l[i]) >= 0){
            sequence[i] = l[i];
            max_sum-=r[i] - l[i];
        } else {
            if(max_sum == 0){
                sequence[i] = r[i];
            } else {
                sequence[i] = r[i] - max_sum;
                max_sum = 0;
            }
        }
    }

    cout << "Yes" << endl;
    for (auto x : sequence) cout << x << ' '; cout << endl;
}

signed main (){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    solve();

    return 0;
}