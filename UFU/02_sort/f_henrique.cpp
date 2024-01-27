#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define vi vector<int>
#define endl '\n'

signed main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    // setlocale(LC_ALL, "pt_BR.UTF-8");

    int n; cin >> n; 
    cin.ignore();
    vector<pair<int,string>> order(n);
    for (int i = 0; i < n; i++){
        string s;
        getline(cin, s);
        int comma = s.find(',');
        string name = s.substr(0, comma);
        int age = stoi(s.substr(comma+1, s.length()-comma));
        order[i] = {age,name};
    }


    sort(order.begin(), order.end(), [](pair<int,string> p1, pair<int,string> p2){
        if (p1.first > p2.first) return true;
        if (p1.first < p2.first) return false;
        return (p1.second < p2.second);
    });

    for (int i = 0; i < n; i++) cout << order[i].second << endl;

    return 0;
}