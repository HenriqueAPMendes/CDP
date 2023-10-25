#include <bits/stdc++.h>
using namespace std;

int divisible(string str){
	int r = 0;
	for (int i = 0; i < str.length(); i++){
		r << 1;
		r += str[i] - '0';
		r %= 131071;
	}

	return r;
}


int main (){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	vector<string> testcases;
	string str, prevStr;

	while (cin >> str){

		if(str[str.length()-1] == '#'){
			prevStr += str;
			testcases.push_back(prevStr.substr(0, prevStr.length()-1));
		}
		else {
			prevStr += str;
				
		}
	}

	for (unsigned int i = 0; i < testcases.size(); i++){
		string ans = divisible(testcases[i]) ? "NO\n" : "YES\n";
		cout << ans;
	}

	return 0;
}

