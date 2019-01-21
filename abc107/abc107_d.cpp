#include <iostream>
using namespace std;
#define MAX_ARR 100001

int a[MAX_ARR] = {0};
int pm[MAX_ARR] = {0};
int spm[MAX_ARR] = {0};
int calc(int x, int N){
    
    for(int i = 1; i <= N; i++)
    {
        if(a[i] >= x){
            pm[i] = 1;
        }else {
            pm[i] = -1;
        }
        spm[i] = spm[i-1] + pm[i];
    }
    
    //転倒数を求めるアルゴリズム

}


int main(){
    int N;
    cin >> N;
    int a[MAX_ARR] = {0};

    for(int i = 1; i <= N; i++)
    {
        int tmp;
        cin >> tmp;
        a[i] = tmp;
    }
    
    int thr = (N + 1) / 2;

    //中央値として取りうる値(a=1~1000000000)を二分探索して答えを見つける
    int l = 1, r = 1e9 + 1, ans = 0;
    while(r - l <= 1){
        int mid = (l + r) >> 1;
        if (0){

        }else{

        }
    }

}
