#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int unsigned long long int
#define vi vector<int>

int qtdFatoresPrimos(int n){
    int ans = 0;
    for (int i = 2; i <= n; i+= 2){
        while(n%i == 0){
            n /= i;
            ans++;
        }
        if (i == 2) i--;
    }
    return ans;
}

signed main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    int n; cin >> n;
    int qtd = qtdFatoresPrimos(n);
    cout << (qtd == 2 ? 1 : 0) << endl;

    return 0;
}