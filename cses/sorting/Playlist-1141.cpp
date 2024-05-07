#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define endl '\n'

signed main() {
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    int n; cin >> n;
    map<int,int> index;
    vector<int> maxlen(n);
    maxlen[0] = 1;
    int x; cin >> x;
    index[x] = 0;
    int firstIndex = 0;
    for (int i = 1; i < n; i++){
        cin >> x;
        if (!index.count(x)) {
            maxlen[i] = maxlen[i-1] + 1;
        } else {
            if (index[x] < firstIndex)
                maxlen[i] = maxlen[i-1] + 1;
            else {
                maxlen[i] = i - index[x];
                firstIndex = index[x] + 1;
            }
        }
        index[x] = i;
    }

    cout << *max_element(maxlen.begin(), maxlen.end()) << endl;

    return 0;
}
