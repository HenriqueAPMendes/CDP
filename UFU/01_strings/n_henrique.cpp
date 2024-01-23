#include<bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    string s; cin >> s;

    char last = s[0];
    cout << last;

    for (int i = 1; i < (int)s.length(); i++) {
        if (s[i] != last) cout << s[i];
        last = s[i];
    }
    cout << endl;   

    return 0;
}