#include <bits/stdc++.h>
using namespace std;

#define MAX 112

int n;
vector<vector<int>> g(MAX, vector<int>(MAX));

int fw(){
    vector<vector<int>> elim(n, vector<int>(n));

    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++){
                if (g[i][j] > g[i][k]+g[k][j]) return -1;
                if(g[i][k]+g[k][j] == g[i][j] and k!=i and k!=j) elim[i][j] = 1; // pode ser eliminado se existe caminho igual por outras rotas
            }

    int ans = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            ans += elim[i][j];

    return ans>>1;
}


int main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> g[i][j];

    cout << fw() << endl;

    return 0;
}