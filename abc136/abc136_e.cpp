#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
typedef long long ll;

template<class X> void divisor(X input, vector<X>& Dnumber){
    for (X i = 2; i*i <= input; i++)
    {
        if (input % i == 0){
            Dnumber.push_back(i);
            if (i * i  != input) Dnumber.push_back(input / i);
        }
    }
    Dnumber.push_back(input);
    sort(Dnumber.begin(), Dnumber.end());
}



int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> a;
    vector<int> fac;
    int sum = 0;
    rep(i, n){ 
        int tmp; 
        cin >> tmp; 
        a.push_back(tmp);
        sum += tmp;
    }
    divisor(sum , fac);
    //printf("%d\n",sum);
    vector<int> kaisu;
    /* 余りの算出アルゴリズムが違う */
    for (int i = 0; i < fac.size(); i++)
    {
        vector<int> amari;
        vector<int> amari_sum;
        vector<int> amari_sum_inv;

        for(auto j: a) {
            if (j % fac[i] != 0) {amari.push_back(j % fac[i]);}
        }
        sort(amari.begin(), amari.end());

        int tmp1 = 0; 
        int tmp2 = 0;      
        for (int j = 0; j < amari.size(); j++)
        {
           tmp1 += amari[j];
           tmp2 += (fac[i] - amari[j]);
           //printf("[%d]-[%d]",fac[i], amari[j]);
           amari_sum.push_back(tmp1);
           amari_sum_inv.push_back(tmp2);
        }
        int ans = amari_sum_inv[amari.size() - 1];
        for (int i = 1; i < amari.size(); i++)
        {
            ans = min(ans, (amari_sum[i - 1]) + (amari_sum_inv[amari.size() - 1] - amari_sum_inv[i])); 
        }
        kaisu.push_back(ans);
    }
   //for ( auto i: fac) {cout << i <<" "; }
    //cout << endl;
    //for ( auto i: kaisu) {cout << i <<" "; }

    int ans_ = -1;
    for (int i = kaisu.size() - 1; i >= 0 ; i--)
    {
        if (kaisu[i] <= k) {
            ans_ = i;
            break;
        }
    }
    
    cout << ((ans_ != -1) ? fac[ans_] : 1 )<< endl;
}

