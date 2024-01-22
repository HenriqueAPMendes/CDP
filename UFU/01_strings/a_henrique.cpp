#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    string s; cin >> s;

    bool isPalindrome = true;
    int n = s.length();

    for (int i = 0; i < n/2; i++)
        if (s[i] != s[n-1-i]) { isPalindrome = false; break; }
    

    cout << (isPalindrome ? "sim" : "nao") << endl;

    return 0;
}