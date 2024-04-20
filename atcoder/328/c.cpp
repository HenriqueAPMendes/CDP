#include <bits/stdc++.h>
using namespace std;

#define MAX 312345

int n, q;
string s;

vector<int> a(MAX,0), sum(MAX,0);

int main (){
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n >> q;
    cin >> s;

    for (int i = 0; i < n-1; i++)
        if (s[i] == s[i+1]) 
            a[i] = 1;
    
    sum[0] = a[0];
    for (int i = 1; i < n; i++) sum[i] = sum[i-1]+a[i];

    int l, r;
    while(q--){
        cin >> l >> r;
        cout << sum[r-2]-sum[l-2] << endl;
    }


    return 0;
}