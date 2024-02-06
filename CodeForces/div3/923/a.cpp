#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define ii pair<int,int>
#define vi vector<int>
#define MAX 212345
#define endl '\n'

signed main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        string s; cin >> s;
        int first = -1, last = n;
        for (int i = 0; i < n; i++)
            if (s[i] == 'B') {first = i; break;}
        for (int i = n-1; i >= 0; i--)
            if (s[i] == 'B') {last = i; break;}
        
        cout << (last-first+1) << endl;
    }

    return 0;
}