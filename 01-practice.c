#include <stdio.h>

// presentation function to introduce the program
void presentation(){
    // Program presentation
    printf("\nProgram to print a matrix from 2x2 up to 8x8 in different orders.\n");
    printf("Author: Sofia Moreno\n");
    printf("Date: 2025-06-15\n");
    printf("Description: This program prints the elements of a matrix from 2x2 up to 8x8 in horizontal order (rows), vertical order (columns), and zigzag order (diagonal up and diagonal down).\n");
    printf("\n");
}

// Function to print the matrix in different ways

// Function to print the matrix in horizontal order
void  horizontal_way(int d, int matriz[][8]){
    int x = 0; // current row
    int y = 0; // current column
    printf("Row Print:\n"); // message to indicate the start of horizontal printing
    // print the elements of the matrix in horizontal order
    while(x<d){
        printf("%d ", matriz[x][y]);
        if(y<(d-1)){
            y = y + 1; // Move to the right in the same row
        }else{
            x = x + 1; // Move down to the next row
            y = 0;  // Reset to the first column
            printf("\n"); // Print a newline when reaching the end of a row
        };
    };
    printf("\n"); // At the end, to ensure a newline
}

// Function to print the matrix in vertical order
void vertical_way(int d, int matriz[][8]){
    int x = 0; // current row
    int y = 0; // current column
    printf("Column Print:\n"); // message to indicate the start of vertical printing
    // print the elements of the matrix in vertical order
    while(y<d){
        printf("%d ", matriz[x][y]);  // print the current element
        if(x<(d-1)){
            x = x + 1; // Move down in the same column
        }else{
            y = y + 1; // Move to the next column
            x = 0; // Reset to the first row
            printf("\n");  // Print a newline when reaching the end of a column
        };
    };
    printf("\n"); // At the end, to ensure a newline
}

// Function to print the matrix in zigzag order
void zigzag_way(int d, int matriz[][8]) {
    int x = 0; // current row
    int y = 0; // current column
    int cant = 0; // counter for the number of elements printed
    int direccion = 1; // direction of movement: 1 for down-left, -1 for up-right
    printf("ZigZag Print:\n"); // message to indicate the start of zigzag printing
    // print the elements of the matrix in zigzag order
    while (cant < d * d) {
        printf("%d ", matriz[x][y]); // Print the current element
        cant++; // Increment the counter for the number of elements printed

        // Check the current direction and update coordinates accordingly
        if (direccion == 1) { // moveing down-left
            if (y == 0 || x == d - 1) { // If reaching the left edge or the bottom edge
                printf("\n"); // Print a newline when reaching an edge
                if (x == d - 1) { // If reaching the bottom edge
                    y++; // Move to the right in the same row
                } else { // If reaching the left edge
                    x++; // Move down in the same column
                }
                direccion = -1; // Change direction to up-right
            } else { // If not reaching an edge, continue down-left
                printf(" "); // Space to separate numbers
                x++;
                y--;
            }
        } else { // moving up-right
            if (x == 0 || y == d - 1) { // If reaching the top edge or the right edge
                printf("\n"); // Print a newline when reaching an edge
                if (y == d - 1) { // If reaching the right edge
                    x++; // Move down in the same column
                } else { // If reaching the top edge
                    y++; // Move to the right in the same row
                }
                direccion = 1; // Change direction to down-left
            } else { // If not reaching an edge, continue up-right
                printf(" "); // Space to separate numbers
                x--;
                y++;
            }
        }
    }
    printf("\n"); // At the end, to ensure a newline
}

// Main function to execute the program
int main()
{
    int dimention = 4; // Variable to define the dimension of the matrix (2x2 to 8x8)
    // Define a 2D array (matrix) with dimensions 8x8
    int table[8][8]={
        {0,1,2,3,4,5,6,7},
        {8,9,10,11,12,13,14,15}, 
        {16,17,18,19,20,21,22,23},
        {24,25,26,27,28,29,30,31},
        {32,33,34,35,36,37,38,39},
        {40,41,42,43,44,45,46,47},
        {48,49,50,51,52,53,54,55},
        {56,57,58,59,60,61,62,63}
    };
    
    presentation(); // Call the presentation function to introduce the program
    horizontal_way(dimention, table); // Call the function to print in horizontal order
    vertical_way(dimention,table); // Call the function to print in vertical order
    zigzag_way(dimention,table); // Call the function to print in zigzag order
    // End of the program
    printf("Program End.\n"); // Message indicating the end of the program

    return 0;
}