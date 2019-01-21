#include <iostream>
#include <vector>
#include <stdlib.h>
#include <algorithm>
using namespace std;

#define INF 1000000001

int main(){
    int n, k;
    vector<int> p;
    cin >> n >> k;

    for(int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        p.push_back(tmp);
    }
    
    sort(p.begin(), p.end());

    int mindiff = INF;

    for(int i = 0; i < p.size() - (k - 1); i++)
    {
        mindiff = min(mindiff, p[i+(k-1)] - p[i]);       
    }
    
    cout << mindiff << endl;

}