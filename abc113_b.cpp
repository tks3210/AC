#include <iostream>
#include <vector>
#include <stdlib.h>
#include <algorithm>
#define min(x, y) (x > y ? y : x)
using namespace std;

int main(){
    int N;
    int T, A;
    int H[1000];
    int TEMP[1000];
    cin >> N;
    cin >> T >> A;
    
    for(int i = 0; i < N; i++)
    {
        int tmp;
        cin >> tmp;
        H[i] = tmp;
    }
    //calc temp*1000
    
    int tempdifmin = 10000000;
    int ans = 1001;
    for(int i = 0; i < N; i++)
    {
        TEMP[i] = T*1000 - 6*H[i];
        int tempdif = abs(TEMP[i] - A*1000);
        if (tempdifmin > tempdif){
            ans = i + 1;
            tempdifmin = tempdif;
        }
    }

    cout << ans << endl;    
}