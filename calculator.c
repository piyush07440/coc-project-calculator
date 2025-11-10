#include <stdio.h>
#include <math.h> // for predefined fxn of maths
#include <ctype.h> // to convert char in lower.

// replacing PI with the value given (preprocessor directive).
#define PI 3.14159265358979323846

// Function for factorial.
long long factorial(int n) {
    if (n < 0) return 0; // Error for negative numbers.
    if (n == 0) return 1;
    long long result = 1;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}

int main() {
    char user_operator;
    double num1, num2;

    printf("--- Calculator ---\n");
    printf("Enter 'e' at any time to quit.\n");
    printf("Operators you can use: +, -, *, /, %, p (Power), r (Root), ! (Factorial),\n");
    printf("l (Log10), n (LogE), s (Sin), c (Cos), t (Tan), w (ASin), x (ACos), y (ATan),\n");
    printf("m (Max), z (Min), f (Floor), i (Ceil), a (Abs).\n");
    
    // continuous loop untill user explicitly want to exit.
    while(1) {
        printf("\n-------------------------------------------------\n");
        printf("Enter operator: ");
        // Read the character and convert it to lowercase for consistency
        scanf(" %c", &user_operator); 
        user_operator = tolower(user_operator); 

        // Check for exit condition first
        if (user_operator == 'e') {
            printf("Exiting calculator.\n");
            break; // Exits the while loop
        }

        // to chec number of inputs needed
        int need_two_nums = (user_operator == '+' || user_operator == '-' || user_operator == '*' || user_operator == '/' || 
                             user_operator == '%' || user_operator == 'p' || user_operator == 'm' || user_operator == 'z');
        int need_one_num = (user_operator == 'r' || user_operator == '!' || user_operator == 'l'||
                            user_operator == 's' || user_operator == 'c' || user_operator == 't' || user_operator == 'w' || 
                            user_operator == 'x' || user_operator == 'y' || user_operator == 'f' || user_operator == 'i' || 
                            user_operator == 'a'||user_operator == 'n');
        
        if (need_two_nums) {
            printf("Enter two numbers (A and  B): ");
            if (scanf("%lf %lf", &num1, &num2) != 2) {
                printf("Error: Invalid number input. Please try again.\n");
                 while(getchar() != '\n');
                continue;
            }
        } else if (need_one_num) {
            printf("Enter one number (A): ");
            if (scanf("%lf", &num1) != 1) {
                printf("Error: Invalid number input. Please try again.\n");
                while(getchar() != '\n');
                continue;
            }
        } else {
            printf("Error: Invalid operator entered. try again or enter 'e' to exit.\n");
            continue;
        }

        printf("Result: ");

        // calculation logic: 
        switch(user_operator) {
            // operations: 
            case '+': printf("%.2lf + %.2lf = %.2lf\n", num1, num2, num1 + num2); break;
            case '-': printf("%.2lf - %.2lf = %.2lf\n", num1, num2, num1 - num2); break;
            case '*': printf("%.2lf * %.2lf = %.2lf\n", num1, num2, num1 * num2); break;
            case '/': (num2 != 0) ? printf("%.2lf / %.2lf = %.2lf\n", num1, num2, num1 / num2) : printf("Error: div by zero is not possible.\n"); break;
            case '%': (num2 != 0) ? printf("%d %% %d = %d\n", (int)num1, (int)num2, (int)num1 % (int)num2) : printf("Error: div by zero is not acceptable.\n"); break;

            case 'p': printf("%.2lf ^ %.2lf = %.2lf\n", num1, num2, pow(num1, num2)); break;
            case 'r': printf("sqrt(%.2lf) = %.2lf\n", num1, sqrt(num1)); break;
            case '!': printf("%d! = %lld\n", (int)num1, factorial((int)num1)); break;
            case 'l': printf("log10(%.2lf) = %.2lf\n", num1, log10(num1)); break;
            case 'n': printf("ln(%.2lf) = %.2lf\n", num1, log(num1)); break;
            
            // 6 Trigonometric Functions
            case 's': printf("sin(%.2lf deg) = %.2lf\n", num1, sin(num1 * PI / 180.0)); break;
            case 'c': printf("cos(%.2lf deg) = %.2lf\n", num1, cos(num1 * PI / 180.0)); break;
            case 't': if(num1 == 90)printf("undefined");else printf("tan(%.2lf deg) = %.2lf\n", num1, tan(num1 * PI / 180.0)); break;
            case 'w': printf("asin(%.2lf) = %.2lf rad (%.2lf deg)\n", num1, asin(num1), asin(num1) * 180.0 / PI); break;
            case 'x': printf("acos(%.2lf) = %.2lf rad (%.2lf deg)\n", num1, acos(num1), acos(num1) * 180.0 / PI); break;
            case 'y': printf("atan(%.2lf) = %.2lf rad (%.2lf deg)\n", num1, atan(num1), atan(num1) * 180.0 / PI); break;

            case 'm': printf("Max(%.2lf, %.2lf) = %.2lf\n", num1, num2, (num1 > num2) ? num1 : num2); break;
            case 'z': printf("Min(%.2lf, %.2lf) = %.2lf\n", num1, num2, (num1 < num2) ? num1 : num2); break;
            case 'f': printf("Floor(%.2lf) = %.2lf\n", num1, floor(num1)); break;
            case 'i': printf("Ceil(%.2lf) = %.2lf\n", num1, ceil(num1)); break;
            case 'a': printf("|%.2lf| = %.2lf\n", num1, fabs(num1)); break;
            
            default: printf("Error: Unknown operation.\n");
        }
    }

    return 0;
}