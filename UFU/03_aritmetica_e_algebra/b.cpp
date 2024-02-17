#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define endl '\n'
#define vi vector<int>
#define ii pair<int,int>

signed main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    int n; cin >> n;
    while(n--){
        int t, ai, r;
        cin >> t >> ai >> r;
        // busca binaria na resposta
        int left = 0, right = t, mid, sum;
        while(left < right){
            mid = (left+right)>>1;
            int an = ai + mid*r;
            sum = ((mid+1)*(ai+an))/2;
            // cout << mid << ' ' << an  << ' ' << sum << endl;
            // cout << left << ' ' << mid << ' ' << right << ' ' << sum << endl;
            if (sum == t){mid--; break;}
            if (sum < t) left = mid+1;
            else right = mid;
        }
        if (sum <= t) cout << mid+2 << endl;
        else cout << mid+1 << endl;
    }

    return 0;
}