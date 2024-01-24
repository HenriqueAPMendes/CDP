#include <bits/stdc++.h>
using namespace std;

#define MAX 112345
int a[MAX], b[MAX];

int main (){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    int d, c, r, x;
    cin >> d >> c >> r;

    for (int i = 0; i < c; i++)
        cin >> a[i];
    for (int i = 0; i < r; i++)
        cin >> b[i];
        
    int i = 0, j = 0;

    int ans = 0;
    int remainingR = r;
    while(remainingR){
        if (i < c && d >= a[i]){
            d -= a[i++];
            ans++;
        }
        else if (j < r) {
            d += b[j++];
            ans++;
        }
        else break;
    }

    cout << ans << endl;

    return 0;
}