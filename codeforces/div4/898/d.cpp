#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int t, n, k;
    string s;
    cin >> t;
    while(t--){
        int ans = 0;
        cin >> n >> k;
        cin >> s;
        for (int i = 0; i < n; i++){
            // cout << i << ' ';
            if (s[i] == 'B'){
                ans++; i+=k-1;
            }
        }
        // cout << endl;
        cout << ans << endl;    
    }

    return 0;
}