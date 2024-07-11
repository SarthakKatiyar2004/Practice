#include<stdio.h>
#include<stdlib.h>

int lift[5];
int total = 0;
int level = 0;

void takeup(){
    if (level == 4){
        printf("The lift is at the topmost level.");
    }
    else{
        level++;
    }
}

void takedown(){
    if (level == 0){
        printf("The lift is at the ground floor.");
    }
    else{
        level--;
    }
}

void letpplenter(){
    int ppl;
    printf("Enter the no. of people entering at the floor: ");
    scanf("%d",&ppl);
    total += ppl;
}

void letpplexit(){
    if (total <= 0){
        printf("The lift is empty");
    }
    else{
        int ppl;
        printf("Enter the no. of people exiting at the floor: ");
        scanf("%d",&ppl);
        if(ppl > total){
            printf("There are only %d people, so %d people can't exit the lift", ppl, total);
        }
        else{
            total -= ppl;
        }
    }
}

int main(){
    
    while(1){
        (level == 0)?printf("\nThe lift is at Ground floor and there are %d people inside it.", total):printf("\nThe lift is at floor no. %d and there are %d people inside it.", level, total);
        printf("\n1. Take lift up.");
        printf("\n2. Take lift down.");
        printf("\n3. Let people enter.");
        printf("\n4. Let people exit.");
        printf("\n5. Quit.");
        
        int choice;
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        
        switch(choice){
            case 1: takeup(); break;
            case 2: takedown(); break;
            case 3: letpplenter(); break;
            case 4: letpplexit(); break;
            case 5: exit(0); break;
            default: printf("Invalid choice!"); break;
        }
        
    }
    
    return 0;
}
