#include<iostream>
using namespace std;

int main(){
    int x[4], y[4];
    cin >> x[0] >> y[0] >> x[1] >> y[1];
    int hen_x = x[1] - x[0];
    int hen_y = y[1] - y[0];
    x[2] = x[1] - hen_y;
    y[2] = y[1] + hen_x;
    x[3] = x[2] - hen_x;
    y[3] = y[2] - hen_y;
    cout << x[2] << " " << y[2] << " " << x[3] << " "<< y[3] << endl;
}