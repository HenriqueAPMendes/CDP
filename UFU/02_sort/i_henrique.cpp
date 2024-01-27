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
    vi yes, no;
    
    wstring s;
    getline(wcin, s);
    wstringstream ss(s);
    int x;
    while(ss >> x)
        mapped.insert(x);
    
    getline(wcin, s);
    wstringstream ss2(s);
    while(ss2 >> x){
        // cout << x << endl;
        if (mapped.count(x)) yes.push_back(x);
        else no.push_back(x);
    }

    sort (yes.begin(), yes.end());
    sort (no.begin(), no.end());

    for (auto &i : no) cout << i << " Não está mapeado" << endl;
    for (auto &i : yes) cout << i << " Está mapeado" << endl;

    // while(cin >> v[i++]){}
    // int qtd = i-1;
    // for (int i = 0; i < qtd-2; i++) {
    //     mapped.insert(v[i]);
    // }
    // for (auto &m : mapped) cout << m << ' ';
    // cout << endl;

    return 0;
}