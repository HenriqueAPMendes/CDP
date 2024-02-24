#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long int
#define vi vector<int>

bool isPalindrome(string s){
    int n = s.length();
    for (int i = 0; i < n/2; i++)
        if (s[i] != s[n-1-i]) return 0;

    return 1;
}

int lychrel(string s){
    for (int i = 0; i < 20; i++){
        string reverted = s;
        reverse(reverted.begin(), reverted.end());
        cout << stoi(s) << ' ' << stoi(reverted) << endl;

        int current1 = stoi(s);
        int current2 = stoi(reverted);
        cout << current1 + current2 << endl;
        // string currentS = to_string(current1+current2);

        // if (isPalindrome(currentS)) return 0;
        // s = currentS;
    }
    return 1;
}

signed main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    string n; cin >> n;
    cout << lychrel(n) << endl;

    return 0;
}