#include <bits/stdc++.h>
using namespace std;

#define int unsigned long long int
#define vi vector<int>
#define endl '\n'
#define MAX 11234


signed main(){
    // cin.tie(0); cout.tie(0);
    // ios_base::sync_with_stdio(0);

    setlocale(LC_ALL, "pt_BR.UTF-8");

    unordered_set<int> mapped;
    vi v;
    
    wstring s;
    getline(wcin, s);
    wstringstream ss(s);
    int x;
    while(ss >> x)
        mapped.insert(x);
    
    getline(wcin, s);
    wstringstream ss2(s);
    while(ss2 >> x)
        v.push_back(x);

    sort(v.begin(), v.end());

    for (auto &i : v) cout << i << (mapped.count(i) ? " Está mapeado" : " Não está mapeado") << endl;

    return 0;
}