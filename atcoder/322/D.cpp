#include <bits/stdc++.h>
using namespace std;

vector<vector<string>> pols(3, vector<string>(4, string(4, ' ')));

vector<string> tab(7+5, string(7+5, ' '));

void rotaciona90(vector<string> &mat){
    vector<string> tmp = mat;
    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 4; j++){
            mat[j][3-i] = tmp[i][j];
        }
    }
}

bool coloca(vector<int> dx, vector<int> dy){
    for (int p = 0; p < 3; p++){
        for (int i = 0; i < 4; i++){
            for (int j = 0; j < 4; j++){
                if (pols[p][i][j] == '.') continue
                int i2 = i*dx[p];
                int j2 = j*dy[p];
                if (i2 < -3 || i2 > 3 || j2 < -3 || j2 > 3) return false;

                i2 += 3;
                j2 += 3;

                if (tab[i2][j2] == '.') return false;

                tab[i2][j2] = pols[p][i][j];
            }
        }
    }
    return true;
}

// bruteforce
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    for (int p = 0; p < 3; p++){
        for (int i = 0; i < 4; i++){
                cin >> pols[p][i];
            
        }
    }

    for(int p0 = 0; p0 < 4; p0++){
        for (int p1 = 0; p1 < 4; p1++){
            for (int p2 = 0; p2 < 4; p2++){

                bool ok = false;

                for (int dx0 = -3; dx0 < 3; dx0++){
                for (int dy0 = -3; dy0 < 3; dy0++){
                for (int dx1 = -3; dx1 < 3; dx1++){
                for (int dy1 = -3; dy1 < 3; dy1++){
                for (int dx2 = -3; dx2 < 3; dx2++){
                for (int dy2 = -3; dy2 < 3; dy2++){

                    if (!coloca({dx0, dx1, dx2}, {dy0, dy1, dy2})) continue;

                    bool now = true;
                    for (int i = -3; i <=3; i++){
                        for (int j =-3; j <= 3; j++){
                            if(){
                                now &= tab[i+3][j+3] = '#';
                            }
                            else{
                                now &= tab[i+3][j+3] = '.';
                            }
                        }
                    }
                    ok |= now;
                }}}}}}

                rotaciona90(pols[2]);
            }
            rotaciona90(pols[1]);
        }
        rotaciona90(pols[0]);
    }

    return 0;
}