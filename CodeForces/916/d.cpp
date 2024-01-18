#include <bits/stdc++.h>
using namespace std;

#define MAX 2123435
#define INF 212345678
#define ll long long
#define ii pair<int,int>
#define vi vector<int>
#define vii vector<ii>
#define endl '\n'

vii a(MAX), b(MAX), c(MAX);

void solve(){
    int n; cin >> n;
    int x;
    for (int i = 0; i < n; i++) {cin >> x; a[i] = {x,i};}
    for (int i = 0; i < n; i++) {cin >> x; b[i] = {x,i};}
    for (int i = 0; i < n; i++) {cin >> x; c[i] = {x,i};}

    sort(a.begin(), a.begin()+n, greater());
    sort(b.begin(), b.begin()+n, greater());
    sort(c.begin(), c.begin()+n, greater());

    int ans = a[0].first + b[0].first + c[0].first;

    int ia = 0;
    int ib = 0;
    int ic = 0;

    // if (ia == ib or ia == ic or ib == ic) cout << "DUPLICATE DAYS: ";

    // cout << "first answer: " << ans << endl;

    /*
    4
    30 20 10 1
    30 5 15 20
    30 25 10 10
    */

    

    while(a[ia].second == b[ib].second or a[ia].second == c[ic].second or b [ib].second == c[ic].second){
        if (a[ia].second == b[ib].second and b[ib].second == c[ic].second){
            
            int diffA = a[ia].first - a[ia+1].first;
            int diffB = b[ib].first - b[ib+1].first;
            int diffC = c[ic].first - c[ic+1].first;
            if (a[ia+1].second == b[ib].second or a[ia+1].second == c[ic].second) diffA = INF;
            if (b[ib+1].second == a[ia].second or b[ib+1].second == c[ic].second) diffB = INF;
            if (c[ic+1].second == b[ib].second or c[ic+1].second == a[ia].second) diffC = INF;
            // cout << diffA << ' ' << diffB << ' ' << diffC << endl;
            if ((diffA <= diffB and diffB <= diffC) or
                (diffA <= diffC and diffC <= diffB)) ia++;
            else if ((diffB <= diffA and diffA <= diffC) or
                (diffB <= diffC and diffC <= diffA)) ib++;
            else ic++;
        }
        if (a[ia].second == b[ib].second){
            int diffA = a[ia].first - a[ia+1].first;
            int diffB = b[ib].first - b[ib+1].first;
            if (a[ia+1].second == b[ib].second) diffA = INF;
            if (a[ia].second == b[ib+1].second) diffB = INF;
            // cout << diffA << ' ' << diffB << endl;
            if (diffA < diffB) ia++;
            else ib++;
        }
        if (a[ia].second == c[ic].second){
            int diffA = a[ia].first - a[ia+1].first;
            int diffC = c[ic].first - c[ic+1].first;
            if (a[ia+1].second == c[ic].second) diffA = INF;
            if (a[ia].second == c[ic+1].second) diffC = INF;
            // cout << diffA << ' ' << diffC << endl;
            if (diffA < diffC) ia++;
            else ic++;
        }
        if (b[ib].second == c[ic].second){
            int diffB = b[ib].first - b[ib+1].first;
            int diffC = c[ic].first - c[ic+1].first;
            if (c[ic+1].second == b[ib].second) diffC = INF;
            if (c[ic].second == b[ib+1].second) diffB = INF;
            // cout << diffB << ' ' << diffC << endl;
            if (diffB < diffC) ib++;
            else ic++;
        }
    }

    cout << a[ia].first + b[ib].first + c[ic].first << endl;
}

int main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    int t; cin >> t;
    while(t--) solve();

    return 0;
}