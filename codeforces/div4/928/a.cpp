#include <bits/stdc++.h>
using namespace std;

#define int long long int 
#define endl '\n'
#define vi vector<int>

signed main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    int t; cin >> t;
    while(t--){
        string s; cin >> s;
        int freqA = 0, freqB = 0;
        for (int i = 0; i < s.length(); i++){
            if (s[i] == 'A') freqA++;
            else freqB++;
        }
        if (freqA > freqB) cout << 'A' << endl;
        else cout << 'B' << endl;
    }

    return 0;
}