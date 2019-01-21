#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


int main(){
    int A, B, K;
    cin >> A >> B >> K;    
    for(int i = 0; i < K; i++)
    {
        int tmp;
        if (i % 2 == 0){
            //A->B
            A -= A % 2;
            tmp = A / 2;
            A -= tmp;
            B += tmp;
        }else{
            //B->A
            B -= B % 2;
            tmp = B / 2;
            B -= tmp;
            A += tmp;
        }
    }    
    cout << A << " " << B << endl;
}