#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    unsigned long long sqsum = (1+n)*n/2;
    unsigned long long summasq = sqsum*(2*n+1)/3;
    sqsum = sqsum*sqsum;
    cout << sqsum - summasq << endl;
    return 0;
}