#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n;
    vector<int> p;
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        p.push_back(tmp);
    }
    
    sort(p.begin(), p.end());
    
    p[p.size() - 1] /= 2;

    int sum = 0;
    for(auto i : p)
    {
        sum += i;
    }
    
    cout << sum;

    
}