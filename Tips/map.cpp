#include <bits/stdc++.h>
using namespace std;


int main(){

    map<string, vector<int>, greater<string>> m;
    m["aa"].push_back(100);
    m["aa"].push_back(200);
    m["bb"].push_back(200);


    for (auto p: m){
        cout << p.first << ":" << endl; 
        for (auto i: p.second) cout << i << " ";
        cout << endl;
    }
    /*
    aa
    100 200
    */
}