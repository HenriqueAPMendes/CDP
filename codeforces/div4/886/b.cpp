#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long int
#define vi vector<int>

signed main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    int t; cin>>t;
    int maxB = 0;
    int winner;
    while(t--){
        int n;
        cin >> n;
        maxB = 0;
        for (int i = 1; i <= n; i++){
            int a, b;
            cin >> a >> b;
            if (a <= 10 && b > maxB){
                maxB = b;
                winner = i;
            } 
        }
        cout << winner << endl;
    }

    return 0;
}