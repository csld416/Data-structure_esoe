#include <iostream>

/*
 * This program defines functions to find prime numbers and calculate the
 * nearest prime numbers around a given integer p. Returns p and 0 if p is a
 * prime number.
 *
 * The `isPrime` function is used to check whether a number is prime, while
 * `showPrime` handles finding the nearest primes.
 *
 * @author      陳澤諒
 * @ID          B12505047
 * @Department  Engineering Science and Ocean Engineering
 * @Affiliation National Taiwan University
 */

using namespace std;

// Function to check if a number is prime
bool isPrime(int num) {
    if (num <= 1) {
        return false;
    }
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) return false;
    }
    return true;
}

// Function to find the nearest primes smaller and larger than p
int *showPrime(int p) {
    int *result = new int[2];  // Allocate memory for the result array

    if (p == 1) {
        result[0] = 0;  // No prime smaller than 1
        result[1] = 2;  // Nearest prime larger than 1
        return result;
    }

    // Special case for p = 2 (smallest prime number)
    if (p == 2) {
        result[0] = 2;
        result[1] = 0;  // 2 is prime, so second element is 0
        return result;
    }

    if (isPrime(p)) {
        result[0] = p;  // If p is prime, return p and 0
        result[1] = 0;
        return result;
    }

    // Find nearest smaller prime (ps)
    int ps = p - 1;
    while (ps > 1 && !isPrime(ps)) {
        ps--;
    }

    // Find nearest larger prime (pl)
    int pl = p + 1;
    while (!isPrime(pl)) {
        pl++;
    }

    // Return the result [ps, pl]
    result[0] = ps;
    result[1] = pl;

    return result;
}