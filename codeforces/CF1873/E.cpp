#include <bits/stdc++.h>
using namespace std;

#define VEC_MAX 353123

long long a[VEC_MAX];

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int t; cin >> t;

    for (int i = 0; i < t; i++){
        memset(a, 0, sizeof(a));
        int n, x; 
        cin >> n >> x;
        
        long long sum = 0;
        long long greatest = 0;

        for (int j = 0; j < n; j++){
            cin >> a[j];
            sum += a[j];
            greatest = max(greatest, a[j]);    
        }
        
        long long h = 0;
        if (x + sum >= n*greatest){
            long long aux = x - (n*greatest-sum);
            h = greatest + aux/n;
            cout << h << endl; 
            return 0;
        }

        int exp = log2(greatest);
        while(exp >= 0){
            h += (1 << exp);
            sum = 0;
            for (int k = 0; k < n; ++k){
                sum += max(0ll, h - a[k]);
            }
            if (sum > x){
                h -= (1 << exp);
            }
            exp--;
        }

        cout << h << endl;


    }
    return 0;
}
