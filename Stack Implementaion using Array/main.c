#include <stdio.h>          // fro using printf() and scanf()
#include <stdlib.h>         // for using malloc()
#include <windows.h>       
/* 
 for using sleep(5) function
 5 is in seconds, this is dos style, using header file <dos.h>
 we can use windows style too
 use header file <windows.h> and function Sleep(5000), here 5000 is in milliseconds
*/

// the following are 4 functions of stack. Will pass stack's address here as paramater
void push(char *);           
void pop(char *);
void display(char *);
void peek(char *);

// our main menu and settings menufunction prototype
void main_menu();
void settings_menu();

void exit_in_3_2_1();          // our self created exit message function
void settings();               // will have option to change the time settings of delay

int len_of_string(char *);

int size = 0;                   // wil have size of stack
int top = -1;                   // will have top, used in stack
int delay = 3000;               // will keep the delay time
int exit_time = 3000;           // will keep the exit time

int main() {
    printf("Enter the \'SIZE of STACK\' you want\n(Type \"-1\" to exit)\n\n");      // will ask size from user
    scanf("%d", &size);
    system("cls");          // for clearing the console
 
    if(size==(-1)){             // if user exited at the start
        exit_in_3_2_1();           // our self created delay function
        return 0;
    }

    char *stack;                 // stack pointer
    stack = (char*) calloc(size, sizeof(char));       // allocating stack in heap

    char choice[20];                    // will track the user's choice
    for(;;){
        main_menu();                // displaying the menu
        scanf("%s", choice);       // taking the user input
        system("cls");              // clearing console after input

        //Error Handling, if user entered some strings or other values
        if(len_of_string(choice) != 1){
            system("cls");      // clearing console
            printf("ERROR :\nWrong Choice!\n");     // default error message
            Sleep(delay);             
            system("cls"); 
        }
        else if( (int)(choice[0]) == 49)
            push(stack);
        else if((int)(choice[0]) == 50)
            pop(stack);
        else if((int)choice[0] == 51)
            display(stack);
        else if((int)choice[0] ==52)
            peek(stack);
        else if((int)choice[0] == 53)
            settings();
        else if((int)choice[0] == 54){
            free(stack);        // freeing the memory while exiting
            exit_in_3_2_1();    // exit message display
            return 0;
        }
        else{
            system("cls");      // clearing console
            printf("ERROR :\nWrong Choice!\n");     // default error message
            Sleep(delay);             
            system("cls");
        }
    }

    return 0;
}
// creating push()
void push(char *sta){
    // fflush(stdin);          // I don't know where I am making an error, but some buffer is comming
                            // Therefore i'm clearing the buffer    
                            // Note: removed it, workign fine now, maye be some other error was causing the problem

    if(top == (size-1)){        // when stack is full
        printf("Error:\nCan not Insert, Stack is Full!\n");
        Sleep(delay);           // delay after message
        system("cls");          // clearing console
    }
    else{
        char data[20];               
        printf("Enter the data to be pushed -> ");
        scanf("%s", &data);     // taking data from user
        system("cls");          // clearing console

        if(len_of_string(data) !=1){
            printf("Error:\nEnter only character\n");
            Sleep(delay);
            system("cls");
            // fflush(stdin);
        }
        else{
            top += 1;               // increasing top by 1, IMPORTANT STEP
            sta[top] = data[0];        // inserting the data

            printf("%c has been pushed!", data[0]);
            Sleep(1000);            // a delay after the message
            system("cls");          // clearing console
        }
    } 
}
// defining pop()
void pop(char *sta){
    if(top == (-1)){        // when stack is empty
        printf("Error:\nStack is Empty, Nothing to pop!\n");
        Sleep(2000);        // delay
        system("cls");      // clearing the console
    }
    else{
        top -= 1;           // removing the top, by decreasing the index
        printf("%c is popped!", sta[top]);  // printing the message
        Sleep(2000);        // delay message
        system("cls");      // clear console
    }
}
// defining display()
void display(char *sta){
    if(top == (-1)){        // when stack is empty
        printf("Error:\nStack is Empty, Nothing to Display!\n");
        Sleep(2000);        // delay
        system("cls");      // clearing the console
    }
    else{
        int temp = top;     // taking a temp with top value
        printf("STACK:\n\n");   // printing top value using temp
        while(temp!=(-1)){      // checking when end is reached
            printf("%c\n", sta[temp]);
            temp--;             // decreasing the value
        }
        Sleep(delay);           // delay
        system("cls");          // clearing console
    }
}

void peek(char *sta){
    if(top == (-1)){
        printf("Error:\nStack is Empty, Nothing to peek from!\n");
        Sleep(2000);
        system("cls");
    }
    else{
        printf("The top most element is -> %c", sta[top]);
        Sleep(delay);
        system("cls");
    }
}

void exit_in_3_2_1(){
    exit_time /= 1000;
    for(int i=exit_time; i>0; i--){
        printf("Exiting in %d ", i);
        for(int j=0; j<i; j++)
            printf(". ");
        Sleep(1000);
        system("cls");
    }
}

void settings(){
    char choice[20];
    for(;;){
        system("cls");
        settings_menu();
        
        scanf("%s", choice);            // we don't use & for pointers, it already has an address
        system("cls");
        if(len_of_string(choice) != 1)
        {
            system("cls");      // clearing console
            printf("ERROR :\nWrong Choice!\n");     // default error message
            Sleep(delay);             
            system("cls");
        }
        else if((int)(choice[0]) == 49){
            printf("Enter new Display Time\n(Default Time = %d ms)\n", delay);
            scanf("%d", &delay);
            system("cls");
            printf("New Display Time is set to %d ms\n", delay);
            Sleep(delay);
        }
        else if((int)(choice[0]) == 50){
            printf("Enter new Exit Time\n(Default Exit Time = %d ms)\n", exit_time);
            scanf("%d", &exit_time);
            system("cls");
            printf("New Exit Time has been set to %d ms\n", exit_time);
            Sleep(delay);
        }
        else if((int)(choice[0]) == 51){
            return;
        }
        else{
            system("cls");      // clearing console
            printf("ERROR :\nWrong Choice!\n");     // default error message
            Sleep(delay);             
            system("cls");
        }   
    }
}

void main_menu(){
    printf("What do you want to perform?\n1 - Push an Element into stack\n");
    printf("2 - Pop the top most element out of stack\n3 - Display the elements of the stack\n");
    printf("4 - Peek the top most element\n5 - Time Settings\n6 - To exit the program\n\n");
}

void settings_menu(){
     printf("What do you want to change?\n1 - Display time of messages\n2 - Exiting time\n3 - Exit\n\n");
}

int len_of_string(char *str){
    int i=0, len=0;
    while(str[i]!='\0'){
        len++;
        i++;
    }
    return len;
}