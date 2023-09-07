#include <iostream>
using namespace std;

int main(void){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    int response = 1;
    int nGrenais = 0;
    int winsInter = 0, winsGremio = 0, draws = 0;

    int golsGremio, golsInter;

    while(response == 1){
        nGrenais++;

        cin >> golsInter >> golsGremio;

        if (golsInter > golsGremio) winsInter++;
        else if (golsGremio > golsInter) winsGremio++;
        else draws++;

        cout << "Novo grenal (1-sim 2-nao)" << endl;
        cin >> response;
    }
    
    cout << nGrenais << " grenais" << endl;
    cout << "Inter:" << winsInter << endl;
    cout << "Gremio:" << winsGremio << endl;
    cout << "Empates:" << draws << endl;
    if (winsGremio > winsInter) cout << "Gremio venceu mais" << endl;
    else if (winsGremio < winsInter) cout << "Inter venceu mais" << endl;
    else cout << "Empate" << endl;

    return 0;
}