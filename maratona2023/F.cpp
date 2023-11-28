#include <bits/stdc++.h>
using namespace std;

#define MAX 112345
int a[MAX];

int main (){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    int d, c, r, i, x;
    cin >> d >> c >> r;

    for (i = 0; i < c; i++)
        cin >> a[i];
    for (i = 0; i < r; i++){
        cin >> x;
        d += x;
    }
        
    i = 0;
    while(d - a[i] >= 0)
        d -= a[i++];
    
    cout << i+r << endl;

    return 0;
}