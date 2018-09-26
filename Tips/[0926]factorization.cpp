#include <iostream>
#include <vector>
using namespace std;

vector<int> soinsu;
int main(){
    int N;
    cin >> N;

    int amari = N;
    
    for(int i = 2; i*i <= amari; i++)
    {
        if (amari % i == 0){
            while (amari % i == 0){
                amari /= i;
                soinsu.push_back(i);
            }
        }
    }
    if (amari != 1) soinsu.push_back(amari);

    for (auto i:soinsu) cout << i << endl;
}