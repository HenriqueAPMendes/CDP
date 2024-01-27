#include <bits/stdc++.h>
using namespace std;

#define int unsigned long long int
#define vi vector<int>
#define endl '\n'

signed main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    map<int,int> freq;

    int n; cin >> n;
    for (int i = 0; i < n; i++){
        int x; cin >> x;
        freq[x]++;
    }

    int maxFreq = 0, maxN;

    for (auto &x : freq) {
        if (x.second > maxFreq){
            maxN = x.first;
            maxFreq = x.second;
        }
        else if (x.second == maxFreq && x.first > maxN)
            maxN = x.first;
    }

    cout << maxN << ' ' << maxFreq << endl;
        // cout << x.first << ' ' << x.second << endl;

    return 0;
}