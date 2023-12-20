#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    string itoa = "0123456789";
    string letters = "0abcdefgh";

    string s;
    int t;
    cin >> t;
    while(t--){
        cin >> s;
        for (int i = 1; i <= 8; i++)
            if (itoa[i] != s[1]) cout << s[0]+itoa.substr(i,1) << '\n';
        for (int i = 1; i <= 8; i++)
            if (letters[i] != s[0]) cout << letters.substr(i,1)+s[1] << '\n';
    }
    return 0;
}