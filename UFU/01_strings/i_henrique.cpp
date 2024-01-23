#include <bits/stdc++.h>
using namespace std;

// pair estruturado como {E,D}

int main(){

    int cntD = 0, cntE = 0;

    __int128_t n;

    map<__int128_t,pair<int,int>> cnt;

    int t; cin >> t;
    while(t--){
        int x;
        char c;
        cin >> x >> c;
        if (c == 'D') cnt[x].second++;
        else cnt[x].first++;
    }
    int ans = 0;
    for (auto &b : cnt)
        ans += min(b.second.first, b.second.second);
    
    cout << ans << endl;
}