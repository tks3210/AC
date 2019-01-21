#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

string day[7] = {"Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun"};

int main(){
    int N;
    cin >> N;
    
    int s[50] = {0};
    for(int i = 0; i < N; i++)
    {
        string tmp;
        cin >> tmp;
        for(int j = 0; j < 7; j++)
        {
            if (tmp == day[j]){
                s[i] = j;      
            }
        }        
    }
    
    
    for(int i = 0; i < N; i++)
    {
        cout << day[(s[i]+1) % 7] << endl;
    }
    

}