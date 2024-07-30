#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define endl '\n'
#define vi vector<int>
#define ii pair<int,int>
#define vii vector<ii>

int n, t, d, nextStop, currentDirection = -1;

int esperando0 = 0, esperando1 = 0;

void checaSeTemEsperando(){
    // cout << "espera?: " << esperando0 << ' ' << esperando1 << endl;
    if (currentDirection == 1 && esperando0) {
        nextStop += 10;
        currentDirection = 0;
        esperando0 = 0;
    }
    else if (currentDirection == 0 && esperando1) {
        nextStop += 10;
        currentDirection = 1;
        esperando1 = 0;
    }
}

void segueOBaile(){
    nextStop = t+10;
    // cout << "seguiu o baile " << nextStop << endl; 
}

void espera(){
    if (d == 0) esperando0 = 1;
    else esperando1 = 1;
    // cout << "esperando " << nextStop << ' ' << d << endl; 
}

void solve(){
    cin >> n;
    while(n--){
        cin >> t >> d;
        // cout << "deciding: " << t << ' ' << d << endl;
        if (currentDirection == -1) { // inicia
            currentDirection = d;
            nextStop = t+10;
        }

        else if (t < nextStop && currentDirection == d) 
            segueOBaile();

        else if (t < nextStop && currentDirection != d)
            espera();

        else if (t > nextStop){
            checaSeTemEsperando();
            
            if (currentDirection == d) 
                segueOBaile();
            else espera();
        }
    }
    checaSeTemEsperando();
    cout << nextStop << endl;
}

signed main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);
    solve();
    return 0;
}