#include <iostream>

/*
 * This program demonstrates calculating the dot product of two arrays.
 * It takes input for two arrays of integers, calculates their dot product,
 * and prints the result.
 *
 * @author      陳澤諒
 * @ID          B12505047
 * @Department  Engineering Science and Ocean Engineering
 * @Affiliation National Taiwan University
 */

using namespace std;

// This function calculates the dot product of two integer arrays 'a' and 'b' of
// size 'n'.
int dotProduct(int a[], int b[], int n) {
    if (a == nullptr || b == nullptr || n <= 0) {
        cout << "Error." << endl; // Print error message
        return 0; // Return 0 for error case
    }
    int result = 0;
    for (int i = 0; i < n; i++) {
        result += (a[i] * b[i]);
    }
    return result;
}