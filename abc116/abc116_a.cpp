#include <iostream>
#include <vector>
#include <stdlib.h>
#include <algorithm>
using namespace std;


int main(){
    vector<int> p;
    for(int i = 0; i < 3; i++)
    {
        int tmp;
        cin >> tmp;
        p.push_back(tmp);
    }

    sort(p.begin(), p.end());

    cout << p[0]*p[1]/2 << endl;

}