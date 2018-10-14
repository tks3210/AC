#include <iostream>
#include <vector>
using namespace std;
 
long mod=1000000007;
long a[100001];
long sumlist[100001];
int ncalc(int N){
    long tmp = 1;
    while(1){
        tmp *= (long)N;
        N--;
        tmp %= mod;
        if (N == 0) break;
    }
    return tmp;
}

//aのp乗を求めるアルゴリズム
//p=62>31>30>15>14>7>6>3>2>1>0
//計算量はO(logp)になる。
long long modpow(long a, int p){
    if (p == 0) return 1;
    if (p%2 == 0){
        //p even
        int halfP = p/2;
        long long half = modpow(a, halfP);
        //a^(p/2)をhalfとしてhalf*halfを計算
        return half * half % mod;
    }
    else {
        return a * modpow(a, p-1) % mod; 
    }
}

int main(){
    int N;
    cin >> N;
    for(int i = 0; i < N; i++)
    {
        int tmp = 0;
        cin >> tmp;
        a[i] = tmp;
    }
    
    int nex = ncalc(N);
    printf("%d\n",nex);
    int sum = 0;
    for(int i = 2; i <= N; i++)
    {
        //nexが1000000007を超えたとき、nex / iの計算が想定通りにならない。
        int tmp = nex * modpow((long)i, mod - 2) % mod;
        sum += tmp;
        sum %= mod;
        sumlist[i-2] = sum;
    }
    //sumlist[0] = 24/2  24/3 24/4
    long long ans = 0;
    for(int i = 0; i < N; i++){
        long long anum = 0;
 
        //ai - ai
        anum += nex;
                //printf("aunm %d %d\n",anum, a[i]);
        //ai - ai+1 - an
        if(i != N - 1){  
            anum += sumlist[N - i - 2];
            anum %= mod;
        }
              //printf("aunm %d %d %d\n",anum, a[i], sumlist[N-i-1]);
        //ai - ai-1 a0
        if(i != 0){
            anum += sumlist[i - 1];
            anum %= mod;
        }
        //printf("aunm %d %d\n",anum, a[i]);
        ans += a[i] * anum;
        ans %= mod;
    }
    cout << ans << endl;
}