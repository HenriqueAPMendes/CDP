#include <bits/stdc++.h>
using namespace std;

int main(){
    int H, W, N, h, w;
    cin >> H >> W >> N >> h >> w;

    vector<vector<int> > A(H);
    for (int i = 0; i < H; i++)
        A[i] = vector<int> (W);

    vector<vector<int> > out(H-h);
    for (int i = 0; i < H-h; i++)
        out[i] = vector<int> (W-w);
    
    for (int i = 0; i < H; i++)
        for (int j = 0; j < W; j++)
            cin >> A[i][j];
    

    map<int, int> digits;

    for (int k = 0; k < H-h; k++){
        for (int l = 0; l < W-w; l++){
            digits.clear();
            for (int i = 0; i < H-h; i++){
                for (int j = 0; j < W-w; j++){
                    if((k < i && i <= k+h) && (l < j && j <= l+w)) continue;
                    if (digits.count(A[i][j])) continue;
                    else digits.insert(make_pair(A[i][j], 1));
                }
            }
            out[k][l] = digits.size();
            
        }
    }

    for (int k = 0; k < H-h; k++){
        for (int l = 0; l < W-w; l++){
            cout << out[k][l];
        }
        cout << endl;
    }

    return 0;
}