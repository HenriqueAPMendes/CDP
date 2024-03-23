#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define endl '\n'
#define vi vector<int>
#define ii pair<int,int>
#define vii vector<ii>
#define INF 1123456789012345

signed main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    vi a;
    int n;
    while(cin >> n) a.push_back(n);
    sort(a.begin(), a.end());
    for (auto x : a) cout << x << ' ';
    cout << endl;
    reverse(a.begin(), a.end());
    for (auto x : a) cout << x << ' ';
    cout << endl;

    return 0;
}