#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define endl '\n'
#define vi vector<int>
#define ii pair<int,int>

signed main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    int n, v;
    while(cin >> n >> v){
        if (n == 0 && v == 0) break;

        vi possivel(n+1);
        for (int i = v; i >= 0; i--){
            // simula jogada
            int pos = 0;
            v = i;
            while(v){
                for (int i = 0; i < v; i++){
                    pos += v;
                    if (pos <= n) possivel[pos] = 1;
                }
                v--;
            }
        }

        cout << possivel[n] << endl;
    }


    return 0;
}