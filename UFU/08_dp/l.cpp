#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define endl '\n'
#define vi vector<int>
#define ii pair<int,int>

void solve(){
    // times: m1 == v2 e m2 == v1
    int m1, m2, v1, v2;
    char c; // pular o x
    cin >> m1 >> c >> v1;
    cin >> m2 >> c >> v2;

    int pontos1 = 0;
    int pontos2 = 0;

    if (m1 > v1) pontos1 += 3;
    else if (m1 == v1){ pontos1++; pontos2++;}
    else pontos2 += 3;

    if (v2 > m2) pontos1 += 3;
    else if (m2 == v2) {pontos1++; pontos2++;}
    else pontos2 += 3;
    
    int saldo1 = m1-v1 + v2-m2;
    int saldo2 = -saldo1;
    int golsAdv1 = v2;
    int golsAdv2 = v1;

    if (pontos1 > pontos2){
        cout << "Time 1" << endl;
    }
    else if (pontos1 < pontos2){
        cout << "Time 2" << endl;
    }
    else{
        if (saldo1 > saldo2)
            cout << "Time 1" << endl;
        else if (saldo1 < saldo2)
            cout << "Time 2" << endl;
        else{
            if (golsAdv1 > golsAdv2)
               cout << "Time 1" << endl;
            else if (golsAdv1 < golsAdv2)
               cout << "Time 2" << endl;
            else 
                cout << "Penaltis" << endl;
        }

    }
}

signed main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    int t; cin >> t;
    while(t--) solve();

    return 0;
}