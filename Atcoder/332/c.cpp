#include <bits/stdc++.h>
using namespace std;

int main (){
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n, m;
    string s;
    cin >> n >> m;
    cin >> s;

    int plain = m;
    int needed = 0, max_needed = 0;

    for (int i = 0; i < n; i++){
        if (s[i] == '0') {
            plain = m;
            max_needed = max(max_needed, needed);
            needed = 0;
        }
        else if (s[i] == '1'){
            if (plain) plain--;
            else needed++;
        }
        else{
            needed++;
        }
    }
    max_needed = max(max_needed, needed);

    cout << max_needed << '\n';

    return 0;
}