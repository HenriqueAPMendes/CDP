#include <bits/stdc++.h>
using namespace std;

#define endl '\n'


void solve(vector<int> &v){
    bool first = true;
    for (int i = 0; i < (int)v.size(); i++) {
    for (int j = i+1; j < (int)v.size(); j++) {
    for (int k = j+1; k < (int)v.size(); k++) {
    for (int l = k+1; l < (int)v.size(); l++) {
    for (int m = l+1; m < (int)v.size(); m++) {
    for (int n = m+1; n < (int)v.size(); n++) {
        if (!first) cout << endl; 
        first = false;
        cout << v[i] << ' ' << v[j] << ' ' << v[k] << ' ' << v[l] << ' ' << v[m] << ' ' << v[n];
    }}}}}}
    cout << endl;
}

int main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    int k; cin >> k;
    do{
        vector<int> v(k);
        for (int i = 0; i < k; i++) cin >> v[i];

        solve(v);

        cin >> k;
        if (k) cout << endl;
    }while(k);

    return 0;
}