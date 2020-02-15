#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i++)
#define show(x) for(auto i: x){cout << i << " ";}
#define showm(m) for(auto i: m){cout << m.x << " ";}
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
    Dnumber.push_back(1);
    sort(Dnumber.begin(), Dnumber.end(), greater<X>());
}



int process(int num, vector<int>& a){
    vector<int> sorted_div;

    rep(i, a.size()) sorted_div.push_back(a[i]%num);
    sort(sorted_div.begin(), sorted_div.end());

    ll sum_to_next = 0;
    rep(i, a.size()) sum_to_next += num - sorted_div[i];
    int ans = 0;
    rep(i, (sum_to_next / num)) ans += sorted_div[i];
    return ans; 
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> a;
    rep(i, n) {int tmp; cin >> tmp; a.push_back(tmp);}

    int sum = 0;
    rep(i, n) sum += a[i];

    vector<int> div;
    divisor(sum, div);

    //show(div);    

    int ans = 0;
    rep(i, div.size()){
        int num = div[i];
        if(process(num, a) <= k){
            ans = num;
            break;
        }
    }

    cout << ans << endl;
}

