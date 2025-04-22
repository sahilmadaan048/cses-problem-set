 
#include <bits/stdc++.h>
using namespace std;
 
// Function to calculate a^b using binary exponentiation
long long power(long long a, long long b)
{
    // If b = 0, whatever be the value of a,
    // our result will be 1.
    long long res = 1;
    while (b > 0) {
        // If b is an odd number, then
        // (a^b) = (a * (a^(b–1)/2)^2)
        if (b & 1) {
            res = (res * a);
        }
 
        // If b is an even number, then
        // (a^b) = ((a^2)^(b/2))
        a = (a * a);
        b >>= 1;
    }
    return res;
}
 
long long findDigit(long long int N)
{
    // No of digits
    long long digits = 1;
    // Total numbers in current digit interval
    long long base = 9;
 
    // Find the interval in which the Nth digit lies
    while (N - digits * base > 0) {
        N -= digits * base;
        base *= 10;
        digits++;
    }
    long long index = N % digits;
 
    // Calculate the number which contains the Nth digit
    long long res
        = power(10, (digits - 1)) + (N - 1) / digits;
 
    // Find out which digit in the number is the result
    if (index != 0)
        res = res / power(10, digits - index);
    return res % 10;
}
 
// Drive Code
int main()
{
    // Example 1
    long long q ; cin>>q;
	while(q--){
		long long k; cin>>k;
		cout << findDigit(k) << "\n";
	}
 
    cout << endl;
 
    return 0;
}