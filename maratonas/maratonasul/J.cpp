#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>

#define MAX 1123
#define INF 11234

vector<vector<int>> board(MAX, vector<int>(MAX,0));
vector<pii> diagNW (2*MAX, {INF, -INF});
vector<pii> diagNE (2*MAX, {INF, -INF});
vector<pii> rows (MAX, {INF, -INF});
vector<pii> cols (MAX, {INF, -INF});

int n;

int main (){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n;
    char c;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> c;
            if (c == 'P'){
                board[i][j] = 1;

                rows[i].first = min(j, rows[i].first); 
                rows[i].second = max(j, rows[i].second); 
                cols[j].first = min(i, cols[j].first);
                cols[j].second = max(i, cols[j].second);
                diagNE[i+j].first = min(i, diagNE[i+j].first);
                diagNE[i+j].second = max(i, diagNE[i+j].second);
                diagNW[j-i+n].first = min(i, diagNW[j-i+n].first);
                diagNW[j-i+n].second = max(i, diagNW[j-i+n].second);
            }
        }   
    }
    int ans = 0, x;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            x = 0;
            if (board[i][j] == 0){
                
                if (rows[i].first < j) x++;
                if (rows[i].second > j) x++;
                if (cols[j].first < i) x++;
                if (cols[j].second > i) x++;
                if (diagNE[i+j].first < i) x++;
                if (diagNE[i+j].second > i) x++;
                if (diagNW[j-i+n].first < i) x++;
                if (diagNW[j-i+n].second > i) x++;
                
                ans = max(ans, x);
                if (ans == 8){
                    cout << 8 << endl;
                    return 0;
                }
            }
        }
    }
    cout << ans << endl;

    return 0;
}