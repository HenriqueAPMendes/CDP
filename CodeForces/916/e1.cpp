#include <bits/stdc++.h>
using namespace std;

#define MAX 2123435
#define ll long long
#define ii pait<int,int>
#define vi vector<int>
#define vii vector<ii>
#define endl '\n'

bool check(vector<ll> a, vector<ll> b){
    for (int i = 0; i < (int)a.size(); i++) if (b[i] && a[i]) return true;
    return false;
}
/*
void solve(){
    int n;
    cin >> n;

    vector<ll> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    ll sumA = 0, sumB = 0;
    for (int i = 0; i < n; i++) sumA += a[i];
    for (int i = 0; i < n; i++) sumB += b[i];

    ll score = sumA - sumB;

    while(check(a, b)){
        // choose to eliminate bob's max
        int maxB = 0;
        for (int i = 0; i < n; i++) 
            if (a[i] && b[i] > b[maxB]) maxB = i;
        
        ll diff = b[maxB]-1;
        // score += b[maxB]-1;
        // a[maxB]--;
        // b[maxB] = 0;

        // choose to save alice's max

        int maxA = 0;
        for (int i = 0; i < n; i++) 
            if (b[i] && a[i] > a[maxA]) maxA = i;

        diff = maxb[maxA]-1;


        cout << "alice chose color: " << maxB << endl;

        if (check(a,b)) break;

        int maxA = 0;
        for (int i = 0; i < n; i++) 
            if (b[i] && a[i] > a[maxA]) maxA = i;
        
        score += -a[maxA]+1;
        a[maxA] = 0;
        b[maxA]--;

        cout << "bob chose color: " << maxA << endl;
    }
    cout << score << endl;

}
*/

// backtracking method
void solve(){
    
}
int main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    int t;
    cin >> t;
    while(t--) solve();

    return 0;
}