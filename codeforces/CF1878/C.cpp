#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    long long t, n, k, x;
    cin >> t;

    while(t--){
        cin >> n >> k >> x;
        long long sum = 0;
        for (int i = 0; i < k; i++)
            sum += (n-i);
        long long min = k*(k+1)/2;

        if (sum >= x && min <= x) cout << "yes" << endl;
        else cout << "no" << endl;
    }
    return 0;
}