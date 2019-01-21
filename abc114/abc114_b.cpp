#include <string>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    string s;
    cin >> s;

    int minsa = 1000;
    for(int i = 0; i <= s.size() - 3; i++)
    {
        string buf = s.substr(i, 3);
        int num = stoi(buf);
        minsa = min(minsa, abs(num - 753));
    }
    cout << minsa << endl;

}