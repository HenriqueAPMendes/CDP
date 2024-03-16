#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define endl '\n'
#define vi vector<int>
#define ii pair<int,int>

signed main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    int t; cin >> t;
    while(t--){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        int intpart = (d-b)/((c-a)); 
        int resto = (d-b)%((c-a));
        double decpart = (resto)/(1.0*(c-a));
        if(resto) {
            string str = to_string(decpart);
            cout << intpart << '.' << str.substr(str.find('.')+1, 2) << endl;

        }
            else
            cout << intpart << ".00" << endl;
    }
    
    return 0;
}