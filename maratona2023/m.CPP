#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int oo = 987654321;

// Floyd-Warshall algorithm

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n; cin >> n;
    vector<vector<int>> c (n, vector<int>(n));
    vector<vector<pair<int,int>>> d (n, vector<pair<int, int>>(n, make_pair(oo, 0)));

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> c[i][j];
            d[i][j] = make_pair(c[i][j], 1);
        }
    }

    for (int i = 0; i < n; i++){
        d[i][i] = make_pair(0, 1);
    }

    for (int m = 0; m < n; m++){
        for (int u = 0; u < n; u++){
            for (int v = 0; v < n; v++){
                d[u][v] = min(d[u][v], make_pair(d[u][m].first + d[m][v].first, m != u && m != v ? 0 : min(d[u][m].second, d[m][v].second)));
            }
        }
    }

    int ans = 0;
    for (int u = 0; u < n; u++){
        for (int v = u+1; v < n; v++){
            if (c[u][v] > d[u][v].first){
                cout << -1 << endl;
                return 0;
            } else if (!d[u][v].first){
                ans++;
            }
        }
    }

    cout << ans << endl;

    return 0;
}