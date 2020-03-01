#include <bits/stdc++.h>
using namespace std;


int main(){

    map<string, vector<int>> m;
    m["aa"].push_back(100);
    m["aa"].push_back(200);

    for (auto p: m){
        cout << p.first << " " << endl; 
        for (auto i: p.second) cout << i << " ";
    }
    /*
    aa
    100 200
    */
}