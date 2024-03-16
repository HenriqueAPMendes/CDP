#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define endl '\n'
#define vi vector<int>
#define ii pair<int,int>

signed main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    int n, k; cin >> n >> k;
    vi arab(n), con(n);
    for (int i = 0; i < n; i++) cin >> arab[i];
    for (int i = 0; i < n; i++) cin >> con[i];

    int price = 0, left = 0, right = 1e9;
    int x = 0;
    
    // busca binaria na resposta do X
    while(left < right){
        x = (left+right)/2;
        // cout << left << ' ' << x << ' ' << right << endl;
        // calcula preco com x
        price = 0;
        for (int i = 0; i < n; i++){
            price += (arab[i]+con[i])*x;
        }
        // cout << x << ' ' << price  << ' ' << left << ' ' << right << endl;
        if (price == k) break;
        if (price > k) right = x;
        else left = x+1;
    }
    if (price > k) x--;

    cout << x << endl;
    

    return 0;
}