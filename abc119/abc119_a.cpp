#include <bits/stdc++.h>

using namespace std;
 
typedef long long ll;
 

int main(){
    string hizuke;

    cin >> hizuke;

    int heiseiflag = 0;
    if (stoi(hizuke.substr(0, 4)) <= 2019){
        if (stoi(hizuke.substr(5, 7)) <= 4){
            if (stoi(hizuke.substr(8, 10)) <= 30){
                heiseiflag++;
            }
        }
    }
    if (heiseiflag){
        cout << "Heisei" << endl;
    } else {
        cout << "TBD" << endl;
    }

}