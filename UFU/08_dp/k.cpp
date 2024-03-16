#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define endl '\n'
#define vi vector<int>
#define ii pair<int,int>

signed main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    int x;
    vi v;
    while(cin >> x) v.push_back(x);

    int n = v.size();
    vi presum(n);
    presum[0] = v[0];
    for (int i = 1; i < n; i++) presum[i] = presum[i-1] + v[i];

    int maxSum = 0;

    for (int i = 0; i < n; i++){
        for (int j = i; j < n; j++){
            int sum;
            if (i > 0) sum = presum[j] - presum[i-1];
            else sum = presum[j];
            maxSum = max(maxSum, sum);
        }
    }
    cout << maxSum << endl;

    return 0;
}