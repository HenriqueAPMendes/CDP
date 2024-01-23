#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

void solve(int k){
    queue<pair<int,int>> q;
    int x, y;
    for (y = k+1; y <= 2*k; y++){
        // cout << "rest: " << (k*y)%(y-k) << endl;
        if ((k*y)%(y-k)) continue;
        x = (k*y)/(y-k);
        q.push({x,y});
        
    }
    cout << q.size() << endl;
    while (!q.empty()){
        x = q.front().first;
        y = q.front().second;
        cout << "1/" << k << " = 1/" << x << " + 1/" << y << endl;
        q.pop();
    }
}

int main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    int k;
    while (cin >> k)
        solve(k);
    
    return 0;
}