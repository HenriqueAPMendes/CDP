#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define endl '\n'
#define vi vector<int>
#define ii pair<int,int>

signed main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    string s; cin >> s;
    bool valid = true;
    valid =  (s[0] >= 'A' and s[0] <= 'Z');

    for (int i = 1; i < (int)s.length(); i++)
        if (s[i] < 'a' or s[i] > 'z') valid = false;

    cout << (valid ? "Yes" : "No") << endl;

    return 0;
}