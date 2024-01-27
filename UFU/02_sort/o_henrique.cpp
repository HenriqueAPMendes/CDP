#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define vi vector<int>
#define endl '\n'

int insertion_sort(string s){
    string str;
    int ans = 0;

    str = s[0];

    for (int i = 0; i < s.length(); i++){ // inserting s[i]
        for (int j = 0; j < i; j++){
            ans++;
            if (str[j] > s[i]){
                str = str.substr(0, j-1) + s[i] + str.substr(j, str.length()-j+1);
                // str[j+1] = str[j]; // check overflow    
                // str[j] = s[i];
            }
        }
        cout << str << endl;
    }
    cout << s << ' ' << str << endl;

    return ans;    
}

void solve(){
    string s;
    cin >> s;
    cout << insertion_sort(s) << endl;
}

signed main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    int n; cin >> n;
    while(n--) solve();

    return 0;
}