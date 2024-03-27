#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>

int main(){
    int n; cin >> n;
    vector<vi> adj(n);
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            int x; cin >> x;
            if (x == 1) adj[i].push_back(j+1);
        }
    }
    for (int i = 0; i < n; i++){
        for (auto x : adj[i]) cout << x << ' ';
        cout << endl;
    }
    return 0;
}