#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int N; cin >> N;
    vector<vector<int> > D(N);
    for (int i = 0; i < N; i++)
        D[i] = vector<int>(N);


    for (int i = 0; i < N; i++)
        for (int j = i+1; j < N; j++)
            cin >> D[i][j];

    vector<int> usedIndex;

    /*
    0  1  2  3  4  5  6  7  8  9 11 12 13 14 15

    0    5  6  5  2  1  7  9  7  2  5  5  2  4  7  6
    1       8  7  7  9  8  1  9  6 10  8  8  6 10  3
    2         10  5  8  1 10  7  8  4  8  6  5  1 10
    3             7  4  1  4  5  4  5 10  1  5  1  2
    4                2  9  9  7  6  2  2  8  3  5  2
    5                   9 10  3  1  1  2 10  7  7  5
    6                     10  6  1  8  9  3  2  4  2
    7                        10 10  8  9  2 10  7  9
    8                            5  8  8  7  5  8  2
    9                               4  2  2  6  8  3
    10                                 2  7  3 10  3
    11                                    5  7 10  3
    12                                       8  5  7
    13                                          9  1
    14                                             4

    OUTPUT: 75

    // pick max from each column, limited one per line, starting from end

    */

    return 0;
}