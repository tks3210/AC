#include <iostream>
#include <vector>
using namespace std;

int calConb(int c, int n){
    int ansMul = 1;
    int ansDev = 1;
    for(int i = 0; i < n; i++)
    {
        ansMul *= c - i;
        ansDev *= i + 1;
    }
    return ansMul / ansDev;
}

long modpow(int c, int n){
    if (n == 0) return 1;
    if (n % 2 == 0){
        long half = modpow(c, n/2);
        return half * half;
    }else{
        return modpow(c, n-1)*c;
    }

}

int main(){
    int c,n;
    cin >> c >> n;
    cout << calConb(c, n) << endl;
    cout << modpow(c, n) << endl;
}
