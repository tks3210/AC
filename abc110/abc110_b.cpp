#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> x,y;
int main(){
    int N, M;
    int X, Y;
    cin >> N >> M;
    cin >> X >> Y;
    for (int i = 0; i < N; i++){
        int tmp;
        cin >> tmp;
        x.push_back(tmp);
    }
    x.push_back(X);
    for (int i = 0; i < M; i++){
        int tmp;
        cin >> tmp;
        y.push_back(tmp);
    }
    y.push_back(Y);

    int max = *max_element(x.begin(),x.end());
    int min = *min_element(y.begin(),y.end());

    if (max < min){
        cout << "No War" << endl;
    }else{
        cout << "War" << endl;
    }
}