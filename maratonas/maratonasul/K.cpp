#include <bits/stdc++.h>
using namespace std;


// AINDA NAO PASSOU

int main (){
    cin.tie(0);cout.tie(0);
    ios_base::sync_with_stdio(0);

    map<string, int> ancestors, indexes;

    int n, c, t;
    string p1, p2, f;
    cin >> n >> c >> t;
    while(c--){
        cin >> p1 >> p2 >> f;

        if (!ancestors.count(p1)) {ancestors[p1] = 0; indexes[p1] = ancestors.size();}
        if (!ancestors.count(p2)) {ancestors[p2] = 0; indexes[p2] = ancestors.size();}
        if (!ancestors.count(f)) {ancestors[f] = 0; indexes[f] = ancestors.size();}

        ancestors[f] |= (1 << indexes[p1]);
        ancestors[f] |= (1 << indexes[p2]);
        ancestors[f] |= ancestors[p1];
        ancestors[f] |= ancestors[p2];
    }

    // for (auto t : ancestors) cout << t.first << " " << t.second << endl;
    // for (auto t : indexes) cout << t.first << " " << t.second << endl;

    while(t--){
        cin >> p1 >> p2;
        string ans; 
        if (ancestors[p1] & ancestors[p2]) ans = "verdadeiro\n";
        else if (ancestors[p1] & (1 << indexes[p2])) ans = "verdadeiro\n"; // p2 ancestral direto de p1
        else if (ancestors[p2] & (1 << indexes[p2])) ans = "verdadeiro\n"; // p1 ancestral direto de p2
        else ans = "falso\n";

        cout << ans << endl;
    }
    return 0; 
}