#include <bits/stdc++.h>
using namespace std;

bool isVowel(char c){
    string vowels = "aeiouAEIOU";
    for (int i = 0; i < vowels.length(); i++)
        if (vowels[i] == c) return true;
    return false;
}

int main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    string s;
    getline(cin, s);

    int ans = 0;
    for (int i = 0; i < (int)s.length(); i++)
        if (isVowel(s[i])) ans++;

    cout << ans << endl;

    return 0;
}