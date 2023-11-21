#include <bits/stdc++.h>
using namespace std;

#define MAX 2123
#define INF 112345678

int n, init, m, p;
int c[MAX], v[MAX], 
memo[MAX][MAX], 
nxt[MAX][MAX]; // grava a escolha da dp (1 se trocou destilador, !=1 se nao)

int dp(int t, int age){
    int ch1, ch2 = INF;
    if (t == n+1) return 0; // neutro da soma
    if (memo[t][age] != -1) return memo[t][age];
    ch1 = p + c[0] - v[age] + dp(t+1, 1);
    if (age < m) ch2 = c[age] + dp(t+1, age+1);

    nxt[t][age] = (ch1 <= ch2) ? 1 : age+1; // <= pois sempre que é possivel trocar, troca

    return memo[t][age] = min(ch1, ch2);
}

int main (){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    while (cin >> n >> init >> m >> p){
        for (int i = 0; i < m; i++) cin >> c[i];
        for (int i = 1; i <= m; i++) cin >> v[i];
        memset(memo, -1, sizeof(memo));
        memset(nxt, -1, sizeof(nxt));

        cout << dp(1, init) << '\n';
        int t = 1, age = init, first = 1;
        do {
            if (nxt[t][age] == 1){
                if (!first) cout << ' ';
                first = 0;
                cout << t;
            }

            age = nxt[t++][age];

        } while(t <= n);
        if (first) cout << 0;
        cout << '\n';
    }

    return 0;
}