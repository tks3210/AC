#include <iostream>
#include <vector>
using namespace std;

int main(){
    int D;
    cin >> D;
    
    if (D >= 22 && D <= 25){
        D -= 25;
        cout << "Christmas";
        while(D != 0){
            cout << " Eve";
            D++;
        }
    }
    cout << endl;

}