#include <iostream>
#include <vector>
#include <stdlib.h>
#include <algorithm>
#include <map>
using namespace std;


int main(){
    int n, k;
    vector<int> p[100001];
    cin >> n >> k;
    
    for(int i = 0; i < n; i++)
    {
        int tmp1, tmp2;
        cin >> tmp1 >> tmp2;
        //std:make_pair
        p[tmp1].push_back(tmp2);
    }
    
    for(int i = 1; i < 100001; i++)
    {
        sort(p[i].begin(),p[i].end());

    }
    


}