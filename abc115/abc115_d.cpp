#include <iostream>
#include <vector>
#include <stdlib.h>
#include <algorithm>
using namespace std;

unsigned long long S[51] = {0};
unsigned long long p[51] = {0};
int layerstate[51] = {0};

void init(){

    S[0] = 1;
    p[0] = 1;
    for(int i = 1; i < 51; i++)
    {
        S[i] = S[i-1] * 2 + 3;
        p[i] = p[i-1] * 2 + 1;
    }
    
}

int main(){
    int N;
    unsigned long long X;

    init();   
    cin >> N >> X;

    for(int i = N; i >= 0; i--)
    {
        printf("S[%d]:%lld  X:%lld", i, S[i], X);
        unsigned long long halfthr = (S[i]+ 1) / 2;
        if (X > S[i]) printf("error");
        if (X == S[i]){
            layerstate[i] = 2;
            X -= S[i];
        } else if(X >= halfthr){
            layerstate[i] = 1;
            X -= halfthr;
        } else {
            layerstate[i] = 0;
            X -= 1;
        }
        printf(" state[%d]: %d\n", i, layerstate[i]);
        if (X == 0){
            break;
        }

    }
    unsigned long long ans = 0;
    for(int i = N; i >= 0; i--){
        if (layerstate[i] >= 1) ans++;
        ans += p[i - 1] * layerstate[i];
    }

    cout << ans;

}