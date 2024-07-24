#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define endl '\n'
#define ii pair<int,int>
#define vi vector<int>
#define vvi vector<vi>
#define ii pair<int,int>
#define vii vector<ii>
#define vvii vector<vii>

void solve(){
    int n; cin >> n;
    vi h(n);
    vector<multiset<int>> occurences(1e6+1);
    for (int i = 0; i < n; i++) { 
        cin >> h[i];
        occurences[h[i]].insert(i);
    }
    int ans = 0;
    vi shot(n);
    for (int i = 0; i < n; i++){
        if (shot[i]) continue;
        shot[i] = 1; // atira no indice i
        ans++;
        int lastindex = *occurences[h[i]].begin();
        occurences[h[i]].erase(occurences[h[i]].begin()); 
        // procura por h[i]-1
        int nextshot = h[i]-1;
        while(nextshot >= 1 && occurences[nextshot].size()){
            auto index = occurences[nextshot].lower_bound(lastindex);
            // index deve ser o primeiro indice de ocorrencia de nextshot que seja > que lastindex 
            if (*index < lastindex) break;
            lastindex = *index;
            shot[*index] = 1;
            occurences[nextshot].erase(index);
            nextshot--;
        }
    }
    cout << ans << endl;
}

signed main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);
    solve();
    return 0;
}