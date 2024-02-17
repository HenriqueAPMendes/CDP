#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define vi vector<int>
#define ii pair<int,int>
#define endl '\n'

string to_string128(__int128_t t){
    string ans;
    while (t > 0){
        ans += ('0'+t%10);
        t /= 10;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

__int128_t fact(int n){
    __int128_t ans = 1;
    for (int i = 1; i <= n; i++) ans *= i;
    return ans;
}

signed main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    vi freq(26);
    string s; getline(cin, s);
    int nvowels = 0;
    int nconsonants = 0;

    for (int i = 0; i < s.length(); i++){
        if (s[i] == ' ') continue;
        freq[s[i]-'A']++;
        if (s[i] == 'A' or s[i] == 'E' or s[i] == 'I' or s[i] == 'O' or s[i] == 'U') nvowels++;
        else nconsonants++;
    }

    __int128_t ans = fact(nvowels)*fact(nconsonants);
    for (int i = 0; i < 26; i++) ans /= fact(freq[i]);

    cout << to_string128(ans) << endl;

    return 0;
}