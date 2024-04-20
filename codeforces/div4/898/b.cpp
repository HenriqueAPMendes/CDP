#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int v[9];

    int t;
    cin >> t;
    while(t--){
        int n, x, prod = 1;
        int minX = 11, minI = 0;
        cin >> n;
        for (int i = 0; i < n; i++){
            cin >> v[i];
            if (minX > v[i]) {minX = v[i]; minI = i; }
        }
        v[minI]++;
        for (int i = 0; i < n; i++) prod *= v[i];
        cout << prod << endl;

    }

    return 0;
}