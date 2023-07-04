#include <stdio.h>

// Function to count the number of numbers with given digits
int countNumbers(int n) {
    if (n == 1) {
        return 2; // For 1 digit, there are two possible numbers: 5 and 9
    }

    int count[2][n]; // Matrix to store the count of numbers with digits
    count[0][0] = count[1][0] = 1; // The first digit can be 5 or 9
    count[0][1] = count[1][1] = 2; // The second digit can be 5 or 9 since three consecutive identical digits are not allowed

    for (int i = 2; i < n; i++) {
        count[0][i] = count[0][i - 1] + count[1][i - 1]; // Count of numbers with i digits ending in 5
        count[1][i] = count[0][i - 1] + count[1][i - 1]; // Count of numbers with i digits ending in 9
    }

    return count[0][n - 1] + count[1][n - 1]; // Return the total count of numbers with n digits
}

int main() {
    int n;
    printf("Enter the number of digits: ");
    scanf("%d", &n);

    int result = countNumbers(n);
    printf("Number of possible numbers: %d\n", result);

    return 0;
}
