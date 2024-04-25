#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define vi vector<int>
#define endl '\n' 
#define ii pair<double, double>
#define vii vector<ii>


signed main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);
    
    int h, c, s, p;
    double w;
    cin >> h >> c >> s >> p >> w;
    
    vii bombachas(h), boots(c), hats(s), scarves(p);
    for (int i = 0; i < h; i++)
        cin >> bombachas[i];
    for (int i = 0; i < c; i++)
        cin >> boots[i];
    for (int i = 0; i < s; i++)
        cin >> hats[i];
    for (int i = 0; i < p; i++)
        cin >> scarves[i];
    
        

    return 0;
}
