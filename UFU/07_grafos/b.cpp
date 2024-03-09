#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define endl '\n'
#define vi vector<int>
#define ii pair<int,int>

signed main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    int n, c;
    cin >> n >> c; cin.ignore();
    vi infected(n+1,0);
    while(c--){
        int infectante; cin >> infectante;
        int infectados; cin >> infectados;
        while(infectados--){
            int x; cin >> x;
            infected[x] = 1;
        }
    }
    for (int i = 1; i <= n; i++) 
        if (infected[i] == 0)
            cout << i << endl;
            
    return 0;
}