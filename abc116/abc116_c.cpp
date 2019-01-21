#include <iostream>
#include <vector>
#include <stdlib.h>
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

    int ans = 0;
    for(int i = 0; i < 100; i++)
    {
        int brkflg = 0;
        int nonezeroflg = 1; //非ゼロの値が直前にあるとき1を立てる
        for(int j = 0; j < n; j++)
        {
            if (p[j] > 0){
                p[j]--;
                if(nonezeroflg == 1){
                    ans++;
                }
                brkflg = 1;
                nonezeroflg = 0;
            }else {
                nonezeroflg = 1;
            }
        }
        if(brkflg == 0) break;
    }
    
    cout << ans;

}