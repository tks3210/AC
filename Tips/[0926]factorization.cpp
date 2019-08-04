#include <iostream>
#include <vector>
using namespace std;


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

int main(){
    long long N;
    vector<long long> Pnumber;
    cout << "Input>";
    cin >> N;

    factorization(N, Pnumber);
    cout << "Output>";
    for (auto i: Pnumber) cout << i << " ";
}