#include<iostream>
#include<vector>
using namespace std;
long calcComb(int a, int b);
long mod = 1000000007;
long long modpow(long a, int p);

int main(){
    int N,M;
    cin >> N >> M;
    long ans = 1;
    int MNokori = M;

    for (int i = 2; i*i <= MNokori; i++){
        if (MNokori % i == 0){
            int cnt = 0;
            while (MNokori % i == 0){
                cnt++; 
                MNokori /= i;
            }
            ans *= calcComb(N + cnt - 1, N-1);
            ans %= mod;
        }
    }
    if (MNokori != 1){
        ans *= calcComb(N, N-1);
        ans %= mod;
    }
    cout << ans << endl;
    cerr << calcComb(4,2) << endl;
}

//aCb
long calcComb(int a, int b){
    if (b > a-b) return calcComb(a,a-b);
    long ansMul =1;
    long ansDiv =1;
    for(int i = 0; i < b; i++)
    {
        /* code */
        ansMul *= (a-i);
        ansDiv *= (i+1);
        ansMul %= mod;
        ansDiv %= mod;
    }
    //ansDivの逆元を使う。
    long ans = ansMul * modpow(ansDiv, mod -2) % mod;
    return ans;
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