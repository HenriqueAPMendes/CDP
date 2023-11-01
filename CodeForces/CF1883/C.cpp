#include <bits/stdc++.h>
using namespace std;

int main (){
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int t;
    cin >> t;

    while (t--){
        int n, k;
        cin >> n >> k;
        vector<int> a(n,0);

        
        int maxRest = -1;
        int nEven = 0;
        for (int i = 0; i < n; i++){
            cin >> a[i];
            if (a[i]%k == 0){
                maxRest = 0;
                break;
            }
            if (a[i]%k == 2) nEven++;
            maxRest = max(maxRest, a[i]%k);
        }
        if (maxRest == 0) cout << 0 << endl;
        else if (nEven >= 2 && k == 4) {
            cout << "test even "<< 0 << endl;}
        else cout << k - maxRest << endl;
        
    }
}