#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long int
#define vi vector<int>

signed main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    int t; cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        vi a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        sort(a.begin(), a.end());

        // for (int i = 0; i < n; i++) cout << a[i] << ' ';
        // cout << endl;

        int maxSubSequence = 1;
        int current = 1;
        for (int i = 1; i < n; i++){
            if (a[i] <= a[i-1]+k) current++;
            else {
                maxSubSequence = max(maxSubSequence, current);
                current = 1;
            }
        }
        maxSubSequence = max(maxSubSequence, current);

        cout << n-maxSubSequence << endl;
    }

    return 0;
}