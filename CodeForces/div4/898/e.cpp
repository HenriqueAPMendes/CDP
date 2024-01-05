#include <bits/stdc++.h>
using namespace std;

#define MAX 212345
#define INF 1123456789
#define ll long long
#define endl '\n'

vector<int> a(MAX);
ll n, x;

ll calc(int h){
    ll vol = n*h;
    for (int i = 0; i < n; i++)
        vol -= min(h,a[i]);
    
    return vol; // mudar para intervalos
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int t, bot, top, mid;
    ll qtd;
    cin >> t;
    while(t--){
        cin >> n >> x;
        for (int i = 0; i < n; i++) cin >> a[i];
        
        bot = 0;
        top = INF;
        ll vol;
        while (bot < top){
            mid = (bot+top)>>1;
            vol = calc(mid);
            if (vol > x)
                top = mid;
            else
                bot = mid+1;
            
        }
        if (vol > x)
            cout << mid-1 << endl;
        else
            cout << mid << endl;
    }

    return 0;
}