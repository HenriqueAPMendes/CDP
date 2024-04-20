#include <bits/stdc++.h>
using namespace std;

#define MAX 2123435
#define ll long long
#define ii pair<ll,int>
#define vi vector<int>
#define vii vector<ii>
#define endl '\n'

vector<ll> a(MAX), b(MAX);
vii op(MAX); // optimal plays

void solve(){
    int n; 
    cin >> n;
    // cout << n << endl;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    
    for (int i = 0; i < n; i++) op[i] = {a[i]+b[i], i};
    
    sort(op.begin(), op.begin()+n, greater<>());

    ll score = 0;

    for (int i = 0; i < n ; i++){
        int index = op[i].second;
        if (i&1)// bob is playing
            score -= (b[index]-1);
        
        else // alice is playing
            score += (a[index]-1);    
    }

    
    cout << score << endl;
}

int main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    int t;
    cin >> t;
    while(t--) solve();

    return 0;
}