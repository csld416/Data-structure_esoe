#include <iostream>

/*
 * This program checks if one number (n) is a multiple of another number (m).
 *
 * @author      陳澤諒
 * @ID          B12505047
 * @Department  Engineering Science and Ocean Engineering
 * @Affiliation National Taiwan University
 */

using namespace std;

// Function to check if n is a multiple of m
bool isMultiple(long n, long m) {
    if (m == 0) {
        printf("m should not be zero\n");
        return false;  // Avoid division by zero
    }
    return (n % m == 0);
}