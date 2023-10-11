#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int t; cin >> t;

    while(t--){
        int n, k;
        cin >> n >> k;
        
        string s;
        cin >> s;
        vector<int> l(k);
        vector<int> r(k);

        for (int i; i < k; i++)
            cin >> l[i];
        for (int i; i < k; i++)
            cin >> r[i];
        
        int q; cin >> q;

        for (int i; i < q; i++){
            int x; cin >> x;

            // manipulates string
        }
    }
    return 0;
}