#include <stdio.h>
#include <stdbool.h>

int main() {
    // START MAIN

    bool running = true;
    while (running) {
        // START WHILE TRUE

        // Variables
        float num1;
        char op;
        float num2;
        float result;

        // Input
        printf("Enter first number: ");
        if (scanf("%f", &num1) != 1) {
            printf("Invalid input!\n");
            while (getchar() != '\n'); // clear bad input
            continue;
        }
        printf("Enter operator(+, -, * or /): ");
        scanf(" %c", &op);
        while (getchar() != '\n');
        
        printf("Enter second number: ");

        if (scanf("%f", &num2) != 1) {
            printf("Invalid input!\n");
            while (getchar() != '\n'); // clear bad input
            continue;
        }

        // Check operator
        switch (op) {
                case '+':
                    result = num1 + num2;
                    running = false;
                    break;
                case '-':
                    result = num1 - num2;
                    running = false;
                    break;
                case '*':
                    result = num1 * num2;
                    running = false;
                    break;
                case '/':
                    /* We have to be careful, as num1 could be divided by zero! */
                    if (num2 != 0) {
                        result = num1 / num2;
                        running = false;
                        break;
                    } else {
                        printf("Second number cannot be 0!\n");
                        continue;
                    }
                default:
                    printf("Enter a valid operator!\n");
                    continue;
        }

        printf("The result is %.2f\n", result);
        // END WHILE TRUE
    }
    // END MAIN
}