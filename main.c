#include "functions.h"

#include <stdio.h>

void main()
{

    DubList l;

    ListEntry arr[500];
    int option = 0;
    int diff;

    while (option != 2)
    {

        printf("\n1=> Enter text\n");
        printf("2=> Exit\n");
        printf("answer: ");

        scanf("%d", &option);

        if (option == 2)
            break;

        printf("Enter text: ");
        scanf("%s", &arr);

        CreateList(&l);

        for (int i = 0; arr[i] != '\0'; i++)
        {
            InsertList(&l, arr[i], i);
        }

        if (!FindColon(&l))
            printf("N");
        else
        {
            diff = Difference(&l);

            if (diff > 0) // left > right
            {
                printf("L");
            }

            else if (diff < 0) // right > left
            {
                // IsPartOfRight(&l)
                if (isFoundInRight(&l))
                    printf("Q");
                // else printf("R");
            }

            else // right == left
            {
                // IsIdentical(&l)
                // IsMirror(&l)
                // else printf("D");
            }
        }
        DestroyList(&l);
    }
}
