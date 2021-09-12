#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    //  Integer Datas (Calculation)
    int operationNumber;
    int result = 0;

    // Char[] Data (Menu)
    char operationChoice;
    char keyPress;
    typedef enum {Starting_Menu, Calculation_Menu, Exit_Menu} Menu;
    Menu PickedMenu;
    PickedMenu = Starting_Menu;

    printf("|############|\n");
    printf("| CALCULATOR |\n");
    printf("|############|\n\n");

    printf("|##########################|\n");
    printf("| PRESS X TO GO CALCULATOR |\n");
    printf("|##########################|\n\n");

    do
    {
        keyPress = getch();
        tolower(keyPress);
        PickedMenu = Calculation_Menu;
    } while(keyPress != 'x');

    while(PickedMenu == Calculation_Menu)
    {
        printf("|########|############|########|#############|#########|\n");
        printf("| SUM: S | EXTRACT: E | DIV: D | MULTIPLY: M | EXIT: X |\n");
        printf("|########|############|########|#############|#########|\n");

        printf("\n"); // | Line Breaker |

        do
        {
            operationChoice = getch();
            operationChoice = toupper(operationChoice);

            if (operationChoice != 'S' && operationChoice != 'E' && operationChoice != 'D' && operationChoice != 'M' && operationChoice != 'X')
            {
                printf("|##################|\n");
                printf("| Invalid Operator |\n");
                printf("|##################|\n\n");
            }
        } while(operationChoice != 'S' && operationChoice != 'E' && operationChoice != 'D' && operationChoice != 'M' && operationChoice != 'X');


        if (operationChoice != 'X')
        {
            printf("Operation Number --> ");
            scanf("%d", &operationNumber);
        }

        switch (operationChoice)
        {
            case 'S':
                result = result + operationNumber;
                break;
            case 'E':
                result = result - operationNumber;
                break;
            case 'D':
                result = result / operationNumber;
                break;
            case 'M':
                result = result * operationNumber;
                break;
            case 'X':
                return 1;
                PickedMenu = Exit_Menu;
                break;
            default:
                printf("\n|#########################|\n");
                printf("| Invalid Operator Choice |\n");
                printf("|#########################|\n");
                break;
        }
        if (PickedMenu != Exit_Menu)
        {
            printf("\n| %d |\n\n", result);
        }
    }

    return 0;
}