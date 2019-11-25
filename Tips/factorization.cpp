#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
typedef long long ll;

template<class X> void factorization(X input, vector<X>& Pnumber){
    for(X i = 2; i*i <= input; i++)
    {
        if (input % i == 0){
            while (input % i == 0){
                input /= i;
                Pnumber.push_back(i);
            }
        }
    }
    if (input != 1) Pnumber.push_back(input);
}

template<class X> void divisor(X input, vector<X>& Dnumber){
    for (X i = 2; i*i <= input; i++)
    {
        if (input % i == 0){
            Dnumber.push_back(i);
            if (i * i  != input) Dnumber.push_back(input / i);
        }
    }
    sort(Dnumber.begin(), Dnumber.end());
}

int main(){
    long long N;
    vector<long long> Pnumber;
    vector<long long> Dnumber;
    cout << "Input>";
    cin >> N;

    factorization(N, Pnumber);
    divisor(N, Dnumber);
    cout << "OutputP>";
    for (auto i: Pnumber) cout << i << " ";
    cout << "OutputD>";
    for (auto i: Dnumber) cout << i << " ";
    
}