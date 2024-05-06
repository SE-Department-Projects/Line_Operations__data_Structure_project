#include <stdio.h>
#include <stdlib.h>
#include "DoubleLinkedList.h"

int main() {
    DubList l;
    ListEntry arr[500];
    int option = 0;
    int diff;

    while (option != 2) {
        printf("\n1=> Enter text\n");
        printf("2=> Exit\n");
        printf("answer: ");

        char input;
        scanf(" %c", &input);
        option = input - '0';

        if (option != 1 && option != 2) {
            printf("Enter a valid option (1 or 2)\n");
            while (getchar() != '\n');
            continue;
        }

        if (option == 1) {
            printf("Enter text: ");
            scanf("%s", arr);

            CreateList(&l);

            for(int i = 0; arr[i] != '\0' ; i++){
            InsertList(&l,arr[i],i);
        }

            if (!FindColon(&l))
                printf("N");
            else {
                diff = Difference(&l);

                if (diff > 0) //left > right
                {
                    printf("L");
                } else if (diff < 0) // right > left
                {
                    if (IsPartOfRight(&l))
                        printf("P");
                    else if (IsFoundInRight(&l))
                        printf("Q");
                    else
                        printf("R");
                } else // right == left
                {
                    if (IsIdentical(&l) || IsMirror(&l)) {
                        if (IsIdentical(&l))
                            printf("S\n");
                        if (IsMirror(&l))
                            printf("M");
                    } else
                        printf("D");
                }
            }
            DestroyList(&l);
        }
    }

    return 0; // Exit the program
}
