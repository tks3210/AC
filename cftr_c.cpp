#include <bits/stdc++.h>
using namespace std;
 

 int main(){
    int N, H;
    cin >> N >> H;

    /* こんな使い方できるの？ */
    vector<int> h(N);

    for(int i = 0; i < N; i++)
    {
        int tmp;
        cin >> tmp;
        h[i] = tmp;
    }
    
    vector<int> dp(1 << N);
    /* 
    dp[i]の値は、組み合わせの数を表す。
    iの数値は二進数で考えられ、
    例えば0011ならば、1冊目と2冊目が抜き取られた状態であり、
    dp[3]は、1,2冊目が抜き取られた際の組み合わせ数を示す。
    */

    dp[0] = 1;
    
    for(int i = 0; i < (1 << N); i++)
    {
        int total = 0;
        vector<int> p;
        for(int j = 0; j < N; j++)
        {
            if ((i >> j & 1) == 0 && h[j] + total <= H) p.push_back(j);
            if ((i >> j & 1) == 0) total += h[j];
        }
        for (auto a: p){
            dp[i | (1 << a)] += dp[i];
            //printf("%d => %d(%d)\n",i,(i | (1 << a)), dp[i]);
        }
    }
    cout << dp[(1 << N) - 1] << endl;
 }
