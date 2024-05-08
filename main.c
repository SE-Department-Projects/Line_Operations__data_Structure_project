#include <stdio.h>
#include <stdlib.h>
#include "DoubleLinkedList.c"

int ValidateInput(char arr[]);
int MainMenu();



int main() {


    DubList l;
    ListEntry arr[500];
    int option = 0;
    int diff;

    while (option != 2) {


        option = MainMenu();
                

        if (option != 1 && option != 2) {
            printf("\nEnter a valid option\n");
            continue;
        }

        if (option == 1) {
            printf("Enter text: ");
            
            gets(arr);

            CreateList(&l);

            for(int i = 0; arr[i] != '\0' ; i++){
                InsertList(&l,arr[i],i);
                // printf("%c\n",arr[i]);
            }

            if (!FindColon(&l))
                printf("N\n");
            else {
                diff = Difference(&l);

                if (diff > 0) //left > right
                {
                    printf("L\n");
                }
                else if (diff < 0) // right > left
                {
                    printf("R\n");
                    if (IsPartOfRight(&l))
                        printf("P\n");
                    else if (IsFoundInRight(&l))
                        printf("Q\n");
                }
                else // right == left
                {
                    if (IsIdentical(&l) || IsMirror(&l)) {
                        if (IsIdentical(&l))
                            printf("S\n");
                        if (IsMirror(&l))
                            printf("M\n");
                    } else
                        printf("D\n");
                }
            }
            DestroyList(&l);
        }
    }

    return 0; // Exit the program
}

int ValidateInput(char arr[]){

    if((arr[0] == '1' || arr[0] == '2') && arr[1] == '\0'){
        return 1;
    }
    return 0;
}



int MainMenu(){
        printf("\nSelect an Option\n");
        printf("1=> Enter text\n");
        printf("2=> Exit\n");
        printf("answer: ");

        char ans[100];
        // int opt = ans[0];
        gets(ans);
        if(ValidateInput(ans))
            return ans[0] - '0';
        return 0;
}
