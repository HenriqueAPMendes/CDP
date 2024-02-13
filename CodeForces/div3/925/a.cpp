#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define vector<int>  vi
#define ii pair<int,int>
#define iii pair<int,ii>
#define endl '\n'

void solve(){
    int n; cin >> n;
    for(int i = 1; i <= 26; i++)
        for(int j = 1; j <= 26; j++)
            for(int k = 1; k <= 26; k++){
                int sum = i+j+k;
                if (sum == n){
                    char a,b,c;
                    a = 'a'+i-1;
                    b = 'a'+j-1;
                    c = 'a'+k-1;
                    string ans = "";
                    ans += a; ans += b; ans += c;
                    cout << ans << endl;
                    return ;
                }
            }
}

signed main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    int t; cin >> t;
    while(t--) solve();

    return 0;
}