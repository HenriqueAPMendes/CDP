#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define vi vector<int>
#define ii pair<int,int>
#define vii vector<ii>

signed main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    int n, x;
    cin >> n >> x;
    vii v(n);
    for (int i = 0; i < n; i++) {cin >> v[i].first; v[i].second = i;}
    sort(v.begin(), v.end());

    int left = 0, right = n-1;

    while (left < right){
        int sum = v[left].first + v[right].first;
        if (sum < x) left++;
        else if (sum > x) right--;
        else break;
    }
    if (left == right) cout << "IMPOSSIBLE" << endl;
    else cout << v[left].second+1 << ' ' << v[right].second+1 << endl;

    return 0;
}
