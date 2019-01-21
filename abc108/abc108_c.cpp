#include <iostream>

using namespace std;

int main(){
    int n,k;
    cin >> n >> k;
    unsigned long long count = 0;
    //mod k = k/2 or mod k = 0
    if(k % 2 == 0){
        unsigned long long oddnum = 0;
        if ( n < k / 2){
            oddnum = 0;
        } else {
            oddnum = (n - (k / 2)) / k + 1;
        }
        //cout << oddnum << endl;
        count += oddnum * oddnum * oddnum;
    }
    unsigned long long evennum = n / k;
    count += evennum * evennum * evennum;

    cout << count << endl;
}