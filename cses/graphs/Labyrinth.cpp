#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

const int MAX = 1123;
const int oo = 112345678;

const int L = 0;
const int R = 1;
const int D = 2;
const int U = 3;

vector<vector<int>> d(MAX,vector<int>(MAX,-1));

void bfs(int i, int j, int n, int m){
    queue<pair<int,int>> q;
    int ni, nj;
    q.push({i,j});
    while(!q.empty()){
        ni = q.front().first; 
        nj = q.front().second;
        q.pop();

        if (ni-1>=0 and d[ni-1][nj] == oo) {
            q.push({ni-1,nj});
            d[ni-1][nj] = d[ni][nj]+1;
        }
        if (ni+1<n and d[ni+1][nj] == oo) {
            q.push({ni+1,nj});
            d[ni+1][nj] = d[ni][nj]+1;
        }
        if (nj-1>=0 and d[ni][nj-1] == oo) {
            q.push({ni,nj-1});
            d[ni][nj-1] = d[ni][nj]+1;
        }
        if (nj+1<m and d[ni][nj+1] == oo) {
            q.push({ni,nj+1});
            d[ni][nj+1] = d[ni][nj]+1;
        }
    
    }
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    pair<int,int> A;
    pair<int,int> B;

    int n, m;
    char c;
    cin >> n >> m;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> c;
            if (c != '#') d[i][j] = oo;
            if (c == 'A') A = {i,j};
            if (c == 'B') B = {i,j};
        }
    }

    d[A.first][A.second] = 0;
    bfs(A.first,A.second,n,m);


    if (d[B.first][B.second] == oo) cout << "NO\n";
    else{
        stack<int> s;
        int dist = d[B.first][B.second];
        int ni = B.first;
        int nj = B.second;
        cout << "YES\n";
        cout << dist << endl;
        while (dist){
            if (ni-1>=0 and d[ni-1][nj] == dist-1 and d[ni-1][nj] != -1) 
                {s.push(D); ni--;}
            if (ni+1<n and d[ni+1][nj] == dist-1 and d[ni+1][nj] != -1) 
                {s.push(U); ni++;}
            if (nj-1>=0 and d[ni][nj-1] == dist-1 and d[ni][nj-1] != -1) 
                {s.push(R);nj--;}
            if (nj+1<m and d[ni][nj+1] == dist-1 and d[ni][nj+1] != -1) 
                {s.push(L);nj++;}
            
            dist--;
        }

        while (!s.empty()){
            switch (s.top())
            {
            case L:
                cout << 'L';
                break;
            case R:
                cout << 'R';
                break;
            case D:
                cout << 'D';
                break;
            case U:
                cout << 'U';
                break;
            
            default:
                break;
            }   
            s.pop();
        }
        cout << endl;
    }

    return 0;
}