#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ii pair<int,int>
#define vi vector<int>
#define vvi vector<vi>
#define ii pair<int,int>
#define vii vector<ii>
#define vvii vector<vii>

void solve(){
    int n; cin >> n;
    int john = 0, mary = 0;
    vi cards(14,4);
    int x;
    cin >> x; cards[x]--; john += min(x,10);
    cin >> x; cards[x]--; john += min(x,10);
    cin >> x; cards[x]--; mary += min(x,10);
    cin >> x; cards[x]--; mary += min(x,10);
    for (int i = 0; i < n; i++){
        cin >> x; cards[x]--; 
        john += min(x,10);
        mary += min(x,10);
    }
    if (john > mary){ // aim to bust john and not bust mary
        int target = 24-john;
        if (target > 10) { cout << -1 << endl; return; }
        while(cards[target] == 0) target++;
        if (mary + target <= 23) cout << target << endl;
        else cout << -1 << endl;
    }
    else { // aim marys 23
        int target = 23-mary;
        if (cards[target] == 0) cout << -1 << endl;
        else cout << target << endl;
    }
}

signed main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);
    solve();
    return 0;
}