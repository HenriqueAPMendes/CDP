#include <bits/stdc++.h>
using namespace std;


void bubble_sort(vector<pair<double, pair<int, int>>>& pontos, int n){
    pair<double, pair<int, int>> aux;

    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            if (pontos[j].first < pontos[j-1].first){
                aux = pontos[j];
                pontos[j] = pontos[j-1];
                pontos[j-1] = aux;
            }
                
        }
    }
}


int main (){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    int n; cin>>n;
    vector<pair<double, pair<int, int>>> pontos(n);

    for(int i=0; i<n; i++){cin>>pontos[i].second.first>>pontos[i].second.second;}

    for(int i=0; i<n; i++){
        pontos[i].first = sqrt(pontos[i].second.first*pontos[i].second.first + pontos[i].second.second*pontos[i].second.second);
    }

    bubble_sort(pontos, n);

    for(int i=0; i<n; i++){
        cout<<pontos[i].second.first<<" "<<pontos[i].second.second<<endl;
    }


    return 0;
}