
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

// Structure to save length and value
typedef struct {
    int length;
    int value;
} Piece;

// -------------------------------------------------------------------
// This function, read_input, reads input data to populate an array of Piece structures with their 
// lengths and values. The function also will check the length and value are valid or not.
//      Input: 1. pieces[]:An array of Piece structures where each Piece has two fields:
//                  length: The length of the piece.
//                  value: The value of the piece.
//             2. max_pieces: The maximum number of pieces the array can hold (i.e., its size).
//      Output: 1. count: The number of pieces successfully read and stored in the pieces[] array.
// -------------------------------------------------------------------
int read_input(Piece pieces[], int max_pieces) {
    int count = 0;
    char input[50];

    while (count < max_pieces) {
        if (fgets(input, sizeof(input), stdin) == NULL) {
            break; // Stop reading if no more input is entered
        }

        if (input[strlen(input) - 1] == '\n') {
            input[strlen(input) - 1] = '\0';
        }

        char *token1 = strtok(input, ",");
        char *token2 = strtok(NULL, ",");

        if (token1 == NULL || token2 == NULL) {
            fprintf(stderr, "Error: Input must be in the format <length,value>.\n");
            exit(1);
        }

        char *end_ptr1, *end_ptr2;
        long length = strtol(token1, &end_ptr1, 10);
        long value = strtol(token2, &end_ptr2, 10);

        // Check for invalid input
        if (*end_ptr1 != '\0' || *end_ptr2 != '\0') {
            fprintf(stderr, "Error: Input must be in the format <length,value>.\n");
            exit(1);
        }

        // Check for negative or zero length/value
        if (length <= 0 || value <= 0) {
            fprintf(stderr, "Error: Length and value must be positive integers.\n");
            exit(1);
        }

        // Save valid input
        pieces[count].length = (int)length;
        pieces[count].value = (int)value;
        count++;
    }

    return count;
}

// -------------------------------------------------------------------
// This function will determines the optimal way to cut a rod of a given length to maximize its 
// total value based on the input pieces.
//      Input: 1. pieces[]: An array of Piece structs where each struct contains:
//                  length: The length of a piece.
//                  value: The value of that piece.
//             2. piece_count: The total number of pieces available.
//             3. rod_length: The total length of the rod to be cut.
//      Output: 1. dp[] (Dynamic Programming Array): Stores the maximum value obtainable for each
//                 rod length from 0 to rod_length.
//              2. cuts[]: Tracks which piece was used to achieve the maximum value for a given rod 
//                 length. This helps in reconstructing the cuts for the solution.
// ------------------------------------------------------------------- 
void rod_cutting(Piece pieces[], int piece_count, int rod_length) {
    int dp[rod_length + 1];
    int cuts[rod_length + 1];

    // Initialize dp and cuts arrays
    for (int i = 0; i <= rod_length; i++) {
        dp[i] = 0;
        cuts[i] = -1;
    }

// -------------------------------------------------------------------
// Tis function will calculates the maximum value obtainable for each rod length using dynamic programming.
//      Outer loop: Outer loop (i): Iterates over every rod length (1 to rod_length).
//      Inner loop (j): Iterates over all available pieces.
// -------------------------------------------------------------------
    for (int i = 1; i <= rod_length; i++) {
        for (int j = 0; j < piece_count; j++) {
            if (pieces[j].length <= i) {
                int new_value = dp[i - pieces[j].length] + pieces[j].value;
                if (new_value > dp[i]) {
                    dp[i] = new_value;
                    cuts[i] = j;
                }
            }
        }
    }

    // Output the cutting list and calculate remainder
    int remaining_length = rod_length;
    int total_value = dp[rod_length];

    while (remaining_length > 0 && cuts[remaining_length] != -1) {
        int piece_index = cuts[remaining_length];
        int piece_length = pieces[piece_index].length;
        int piece_value = pieces[piece_index].value;

        int count = 0;

        // By repeatedly identifying the piece getting to the maximum value, 
        // reducing the rod length as well, and printing the cuts.
        while (remaining_length >= piece_length &&
               dp[remaining_length] == dp[remaining_length - piece_length] + piece_value) {
            remaining_length -= piece_length;
            count++;
        }

        if (count > 0) {
            printf("Cut %d pieces of length %d for total value %d\n", count, piece_length, count * piece_value);
        }
    }

    printf("Remainder: %d\n", remaining_length);
    printf("Value: %d\n", total_value);
}

// Manage input validation and program initialization
int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <rod_length>\n", argv[0]);
        return 1;
    }

    char *end_ptr;
    long rod_length = strtol(argv[1], &end_ptr, 10);

    // Check if the input is not an integer or contains invalid characters
    if (*end_ptr != '\0') {
        fprintf(stderr, "Error: Rod length must be an integer.\n");
        return 1;
    }

    // Check if the input is a positive integer
    if (rod_length <= 0) {
        fprintf(stderr, "Error: Rod length must be a positive integer.\n");
        return 1;
    }

    // Check if the rod length exceeds the maximum size for an integer
    if (rod_length > INT_MAX) {
        fprintf(stderr, "Error: Rod length exceeds the maximum limit.\n");
        return 1;
    }

    // Allocate space for pieces
    Piece pieces[100];
    int piece_count = read_input(pieces, 100);

    // Call the rod_cutting function
    rod_cutting(pieces, piece_count, (int)rod_length);

    return 0;
}
