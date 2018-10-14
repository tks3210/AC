#include <iostream>
#include <vector>
using namespace std;
 
long mod=1000000007;



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
    long long x,a;
    printf("calc mod(x/a) (x%a = 0)\n");
    cin >> x >> a;

    int tmp = x * modpow(a, mod - 2) % mod;

    cout << tmp << endl;



}