#include <bits/stdc++.h>
using namespace std;

#define MAX_SIZE 212345

long long a[MAX_SIZE];

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int t; cin >> t;
    while(t--){
        int n; cin >> n;

        for (int i = 0; i < n; i++)
            cin >> a[i];
        
        int q; cin >> q;

        while (q--){
            int l, k; cin >> l >> k;
            l--;

            if (k > a[l]) {
                cout << -1 << " ";
                continue;
            }

            int test = a[l];
            while(test >= k && l < n){
                test &= a[l++];
            }
            if (l == n && test >= k) cout << l << " ";
            else cout << l-1 << " ";
        }
        cout << endl;   
    }

    return 0;
}