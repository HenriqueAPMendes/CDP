#include <bits/stdc++.h>
using namespace std;


vector<int> padrao = {1,0,1,0,1,1,0,1,0,1,0,1};
vector<int> s_padrao = {1,0,1,0,1,1,0,1,0,1,0,1};
vector<string> notas = {"do","do#","re","re#","mi","fa","fa#","sol","sol#","la","la#","si"};
vector<int> vis(12, 0);

bool valid_scale(){
	for(int i = 0; i < 12; i++){   
    if((vis[i] == 1) && (s_padrao[i] == 0))
      return false;
  }
  return true;
}

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

  int n, a;
  cin >> n;
	while(n--){
		cin >> a;
 		vis[(a-1)%12] = 1;
	}

  if(valid_scale()){
    cout << notas[0] << endl;
    return 0;
  }

  for(int i = 1; i < 12; i++){
    for(int j = 0; j < 12; j++)
      s_padrao[(j+i)%12] = padrao[j];

      if(valid_scale()){
        cout << notas[i] << endl;
        return 0;
      }
  }

  cout << "desafinado\n";
  return 0;
}

