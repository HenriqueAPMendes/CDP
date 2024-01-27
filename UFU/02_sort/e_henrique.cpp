#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define vi vector<int>
#define endl '\n'

struct Data{
    int d, m, y, hr, min, sec;
    string str;
    Data(){
        d=m=y=hr=min=sec=0;
        str = "";
    }
    Data(int _d, int _m, int _y, int _hr, int _min, int _sec, string _str) :
    d(_d), m(_m), y(_y), hr(_hr), min(_min), sec(_sec), str(_str) {} 
};

signed main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    vector<Data> v;


    string s;
    while(getline(cin, s)){
        int day = stoi(s.substr(0,2));
        int month = stoi(s.substr(3,2));
        int year = stoi(s.substr(6,4));
        int hour = stoi(s.substr(11,2));
        int minute = stoi(s.substr(14,2));
        int second = stoi(s.substr(17,2));
        // cout << day << ' ' << month << ' ' << year << ' ' << hour << ':' << minute << ':' << second << endl;

        v.push_back(Data(day, month, year, hour, minute, second, s));
    }

    sort(v.begin(), v.end(), [](Data d1, Data d2){
        if (d1.y < d2.y) return true;
        if (d1.y > d2.y) return false;
        if (d1.m < d2.m) return true;
        if (d1.m > d2.m) return false;
        if (d1.d < d2.d) return true;
        if (d1.d > d2.d) return false;

        if (d1.hr < d2.hr) return true;
        if (d1.hr > d2.hr) return false;
        if (d1.min < d2.min) return true;
        if (d1.min > d2.min) return false;
        if (d1.sec < d2.sec) return true;
        if (d1.sec > d2.sec) return false;

        // if its all exactly the same, the first keeps first
        return false;
    });

    for (auto &d : v) cout << d.str << endl;

    return 0;
}