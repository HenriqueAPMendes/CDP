#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    map<char,int> letters;
    letters['A'] = 0;
    letters['B'] = 0;
    letters['C'] = 0;

    int t;
    string s;
    cin >> t;
    while(t--){

        letters['A'] = 0;
        letters['B'] = 0;
        letters['C'] = 0;
        cin >> s;

        letters[s[0]] = 1;
        letters[s[1]] = 1;
        letters[s[2]] = 1;

        if (letters['A'] == 0) cout << 'A\n';
        if (letters['B'] == 0) cout << 'B\n';
        if (letters['C'] == 0) cout << 'C\n';
    }

    return 0;
}