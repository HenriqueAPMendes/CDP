#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define vi vector<int>
#define ii pair<int,int>
#define endl '\n'
#define vii vector<ii>

signed main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        string ans;

        for (int j = 0; j < n; j++)
            for (int i = 0; i < k; i++)
                 ans += 'a'+i;

        cout << ans << endl;
    }

    return 0;
}