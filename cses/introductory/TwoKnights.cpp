#include <bits/stdc++.h>
using namespace std;

int main (){
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    long long n;
    cin >> n;
    if (n > 4){
        cout << "0\n6\n28\n96\n";
        for (long long k = 5; k <= n; k++){
            
            long long ans = (k-4)*(k-4)*(k*k-9) + 4*(k*k-3) + 8*(k*k-4) + 4*(k-4)*(k*k-7) + 4*(k-3)*(k*k-5);
            cout << ans/2 << endl;
        }
    }
    else if (n == 4) cout << "0\n6\n28\n96\n";
    else if (n == 3) cout << "0\n6\n28\n";
    else if (n == 2) cout << "0\n6\n";
    else cout << "0\n";
    
    return 0;
}