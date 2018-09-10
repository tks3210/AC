#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    int N;
    int flag = 0;
    string sent[100];
    cin >> N;

    for (int i = 0; i < N ; i++) {
        cin >> sent[i];
    }
    for (int i = 1; i < N ; i++){
        int ssize = sent[i-1].size();
        if(sent[i-1][ssize-1] != sent[i][0]){
            flag = 1;
        }
    }
    sort(sent, sent+N);
    for (int i = 1; i < N;i++){
        if(sent[i-1] == sent[i]){
            flag = 1;
        }
    }
    if (flag == 1){
        cout << "No" << endl;
    } else {
        cout << "Yes" << endl;
    }

   
} 