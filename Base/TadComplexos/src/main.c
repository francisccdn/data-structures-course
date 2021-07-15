#include <stdio.h>

#include "../include/complex.h"

void printOperations()
{
    printf("\nPossible operations:\n");
    printf("Operation      - Character\n");
    printf("Addition       - a\n");
    printf("Subtraction    - s\n");
    printf("Multiplication - m\n");
    printf("Division       - d\n\n");
}

void printHelp()
{
    printf("\nComplex numbers are expressed as: a + b*i\n");
    printf("Where a is the real part, and b the imaginary part.\n");
    printOperations();
}

void eraseLine()
{
    printf("\r                                                                                                                                                     ");
}

int main(void)
{
    char quit = 'h';

    printf("\t === COMPLEX NUMBER CALCULATOR ===\n\t ==== author: Francisco Cunha ====\n");

    do
    {
        if (quit == 'h')
        {
            printHelp();
        }

        float a, b;

        printf("Num1 ->\n a = ");
        scanf("%f", &a);
        printf(" b = ");
        scanf("%f", &b);

        //eraseLine();
        printf("%.2f + %.2fi\n", a, b);

        Complex *num1 = make_complex(a, b);

        char op;
        printf("\nOperation: ");
        scanf("%c%c", &op, &op);
        printf("\n\n");

        printf("Num2 ->\n a = ");
        scanf("%f", &a);
        printf(" b = ");
        scanf("%f", &b);

        //eraseLine();
        printf("%.2f + %.2fi\n", a, b);

        Complex *num2 = make_complex(a, b);

        Complex *result;
        switch (op)
        {
        case 'a':
            result = sum_complex(num1, num2);
            op = '+';
            break;

        case 's':
            result = sub_complex(num1, num2);
            op = '-';
            break;

        case 'm':
            result = mul_complex(num1, num2);
            op = '*';
            break;

        case 'd':
            result = div_complex(num1, num2);
            op= '/';
            break;

        default:
            result = NULL;
            printOperations();
            break;
        }

        if (result)
        {
            printf("\n\n");
            print_complex(num1);
            printf(" %c ", op);
            print_complex(num2);
            printf("\n=\n");
            print_complex(result);
        }

        printf("\n\n\nq to quit\nh for help\nanykey for another operation\n");
        scanf("%c%c", &quit, &quit);

        free_complex(num1);
        free_complex(num2);
        free_complex(result);
    } while (quit != 'q');

    return 0;
}