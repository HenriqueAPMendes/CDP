#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define endl '\n'
#define vi vector<int>
#define ii pair<int,int>

bool isCapicua(string s){
    int n = s.length();
    for (int i = 0; i < n/2; i++)
        if (s[i] != s[n-1-i]) return false;

    return true;
}

signed main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    int a, ar, sum;
    string n; cin >> n;
    string ans;

    if (isCapicua(n)) {cout << n << endl; return 0;}
    
    a = stoi(n);
    reverse(n.begin(), n.end());
    ar = stoi(n);
    sum = a+ar;
    ans = to_string(sum);
    if (isCapicua(ans)) {cout << ans << endl; return 0;}

    a = stoi(ans);
    reverse(ans.begin(), ans.end());
    ar = stoi(ans);
    sum = a+ar;
    ans = to_string(sum);
    if (isCapicua(ans)) {cout << ans << endl; return 0;}

    a = stoi(ans);
    reverse(ans.begin(), ans.end());
    ar = stoi(ans);
    sum = a+ar;
    ans = to_string(sum);
    if (isCapicua(ans)) {cout << ans << endl; return 0;}

    a = stoi(ans);
    reverse(ans.begin(), ans.end());
    ar = stoi(ans);
    sum = a+ar;
    ans = to_string(sum);
    if (isCapicua(ans)) {cout << ans << endl; return 0;}

    cout << 0 << endl;

    return 0;
}