#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define vi vector<int>
#define endl '\n'
#define ii pair<int,int>

#define INF 12345678650

signed main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    int n; cin >> n; cin.ignore();
    vector<vector<string>> rotas(n);
    int i = 0;
    while(n--){
        string s;
        getline(cin, s);
        stringstream ss(s);
        while(ss >> s)
            rotas[i].push_back(s);
        i++;
    }

    map<pair<string,string>, pair<int, double>> voos;
    cin >> n; cin.ignore();
    while(n--){
        string s, t;
        int dist;
        double price;
        cin >> s >> t >> dist >> price;
        voos[{s,t}] = {dist,price};
    }

    int melhorRotaPreco = 0, melhorRotaDistancia = 0;
    int melhorDistancia = INF;
    double melhorPreco = INF, precoMenorDistancia = INF;
    for (int i = 0; i < rotas.size(); i++){
        string s, t;
        int dist = 0;
        double price = 0;
        s = rotas[i][0];
        t = rotas[i][1];
        dist += voos[{s,t}].first;
        price += voos[{s,t}].second;
        for (int j = 2; j < rotas[i].size(); j++){
            s = t;
            t = rotas[i][j];
            dist += voos[{s,t}].first;
            price += voos[{s,t}].second;
        }
        if (dist < melhorDistancia){
            melhorDistancia = dist;
            melhorRotaDistancia = i;
            precoMenorDistancia = price;
        }
        if (price < melhorPreco){
            melhorPreco = price;
            melhorRotaPreco = i;
        }

    }

    if (precoMenorDistancia < 1.2*melhorPreco){
        for (auto s : rotas[melhorRotaDistancia]) cout << s << ' '; cout << endl;
    }
    else{
        for (auto s : rotas[melhorRotaPreco]) cout << s << ' '; cout << endl;
    }
    

    return 0;
}