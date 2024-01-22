#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    int t; cin >> t;
    string s;
    getline(cin,s);
    while(t--){
        getline(cin, s);
        int n = s.length();

        string s1 = s.substr(0,n/2);
        string s2 = s.substr(n/2, n-n/2);

        for(int i = s1.length()-1; i >= 0; i--) cout << s1[i];
        for(int i = s2.length()-1; i >= 0; i--) cout << s2[i];
        cout << endl;
    
    }

    return 0;
}