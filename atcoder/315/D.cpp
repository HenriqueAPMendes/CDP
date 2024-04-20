#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base:: sync_with_stdio(0);
    cin.tie(0);

    unsigned int H, W; cin >> H >> W;
    unsigned int i, j;

    vector<vector<char>> c(H);

    for (i = 0; i < H; i++)
        c[i] = vector<char> (W);

    for (i = 0; i < H; i++){
        for (j = 0; j < W; j++){
            cin >> c[i][j];
        }
    }


    vector<bool> valid_cols(W, true);
    vector<bool> valid_rows(H, true);

    bool change = true;
    char first;

    int cont1=0;
    int cont2=0;

    int size_rows = H;
    int size_cols = W;

    vector<int> rows_to_clear;
    vector<int> cols_to_clear;

    while(change){
        rows_to_clear.clear();
        cols_to_clear.clear();

        cont1=0;
        cont2=0;
        change = false;
        //loop rows
        for (i = 0; i < c.size(); i++){

            first = c[i][0];
            
            cout << "first: " << first << endl;

            for (j = 0; j < c[0].size() ; j++){
                if (c[i][j] != first) break;
            }
            if (j == W && size_cols >= 2) {
                cont1++;
                change = true;
                rows_to_clear.push_back(i);
                cout << i << "-th row became false" << endl;
            
            }
        }

        //loop cols
        for (j = 0; j < c[0].size(); j++){

            first = c[0][j];

            cout << "first: " << first << endl;

            for (i = 0; i < c.size(); i++){
                if (c[i][j] != first) break;
            }
            if (i == H && size_rows >= 2) {
                cont2++;
                change = true;
                cols_to_clear.push_back(j);
                cout << j << "-th col became false" << endl;
            }
        }
        size_rows-=cont1;
        size_cols-=cont2;
        for (unsigned int i = 0; i < rows_to_clear.size(); i++){
            vector<vector<char>>::iterator it = c.begin() + i;
            c.erase(it);
        }

        for (unsigned int i = 0; i < cols_to_clear.size(); i++){
            vector<char>::iterator it;
            for (j = 0; j < c.size(); j++){
                it = c[j].begin() + i;
                c[j].erase(it);
            }
                
        }
    }
  

    cout << size_rows * size_cols << endl;   

    return 0;
}