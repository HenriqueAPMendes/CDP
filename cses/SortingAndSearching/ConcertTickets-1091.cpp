#include <bits/stdc++.h>
using namespace std;

#define MAX 212345

int main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    int n, m, p;
    cin >> n >> m;

    multiset<int> tickets;

    for (int i = 0; i < n; i++) {cin >> p; tickets.insert(-p);}
    
    for (int i = 0; i < m; i++) {
        cin >> p;
        auto it = tickets.lower_bound(-p);
        if (it == tickets.end()) cout << -1 << endl;
        else{
            cout << -*it << endl;
            tickets.erase(it);
        }
    }


    return 0;
}