#include <iostream>
#include <string>
#include <string.h>
using namespace std;

long gcd(int x, int y){ return y?gcd(y, x%y):x;}


int main(){
    long N, M;
    string S,T;

    cin >> N >> M;
    cin >> S >> T;
    long lcdev = gcd(N,M);
    long lcmul = (N * M) / lcdev;
    //printf("%d\n",lcmul);
    
 
    int NGflag = 0;
    //i j 0 0 5 3 10 6
    for(int i = 0; i < lcdev; i++)
    {
        if (S[i*N/lcdev] != T[i*M/lcdev]){
            NGflag = 1;
        }
    }


    if (NGflag == 0){
        cout << lcmul << endl;
    } else {
        cout << "-1" << endl;
    }

}