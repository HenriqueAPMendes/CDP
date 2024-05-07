#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define endl '\n'

signed main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    int n; cin >> n;
    multiset<int> tops;
    for (int i = 0; i < n; i++){
        int x; cin >> x;
        auto it = tops.upper_bound(x);
        if (it == tops.end()) tops.insert(x);
        else { 
            if (*it > x) 
                tops.erase(it);
            tops.insert(x);
            
        }
    }

    cout << tops.size() << endl;


    return 0;
}
