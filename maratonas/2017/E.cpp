#include <bits/stdc++.h>
using namespace std;

vector<int> pressed_notes(12, 0);
vector<string> notes = {"si", "do", "do#", "re", "re#", "mi", "fa", "fa#", "sol", "sol#", "la", "la#"};

int main (){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	int N, x;
	cin >> N;

	while (N--){
		cin >> x;
		x %= 12;
		pressed_notes[x] = 1;
	}

	for (int i = 0; i < 12; i++){
		if (pressed_notes[i] == 1){
			// if no forbidden notes were pressed, then belongs to major scale (tom maior)
			if (pressed_notes[(i+1)%12] || 
					pressed_notes[(i+3)%12] || 
					pressed_notes[(i+6)%12] ||
					pressed_notes[(i+8)%12] || 
					pressed_notes[(i+10)%12]) continue;
			
			cout << notes[i] << endl;
			return 0;
			
		
		}
	}

	cout << "desafinado" << endl;
	
	return 0;
}

