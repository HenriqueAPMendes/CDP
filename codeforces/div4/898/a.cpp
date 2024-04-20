#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int t;
    string s;
    cin >> t;
    while(t--){
        cin >> s;
        if (s[0] == 'a' or s[1] == 'b' or s[2] == 'c') cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}