#include <iostream>

#include "CA1Prob1.cpp"

using namespace std;

int main() {
    int *a = new int[3];
    for(int i = 0; i < 3; i++){
        a[i] = i+1;
    }
    int *b = new int[3];
    for(int i = 0; i < 3; i++){
        b[i] = i+2;
    }
    printf("%d\n", dotProduct(a, b, 3));
    return 0;
}