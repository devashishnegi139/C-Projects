/*  NOTE
    This code works for integers only
    No Error handling for other cases has been done
    But for Integers, this code is complete

    Also, Online compiler are not taking windows.h header, works fine with VSCode
*/
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

//creating our node
struct node{
    int data;
    struct node* next;
};

// creating our head pointer, this is just a pointer which will point to head/top node
struct node *head = NULL;

// checking if our LL is Full or not
int isFull(struct node* head_t){
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    if(new_node==NULL)
        return 1;
    else
        return 0;
}

// checking if our LL is empty or not
int isEmpty(){
    if(head==NULL)
        return 1;
    else
        return 0;
}

// creating a function to insert at beginning of the LL
void insertAtBeginning(int value){
    // checking if the linked list is full or nor
    if(isFull(head)){
        printf("Error: Stack Overflow\n");
        Sleep(2000);
        system("cls");
    }

    // else creating a new node and changing the links and head
    else{
        struct node* new_node =(struct node*)malloc(sizeof(struct node));
        new_node->data = value;
        new_node->next = head;
        head = new_node;
    }
}

// for displaying the elements of the LL
void displayLL(){
    if(head==NULL){
        printf("Error: Linked List in Empty\n");
        Sleep(1000);
        system("cls");
    }
    else{
        struct node* temp = head;       // this will help in traverasl, without affecting the head node
        while(temp!=NULL){
            printf("%d\t", temp->data);
            temp = temp->next;
        }
        printf("\n");
        Sleep(2000);
        system("cls");
    }
}

// code to insert at end
void insertAtEnd(int value){
    // checking if LL is full or not
    if(isFull(head)){
        printf("Error: Stack Overflow\n");
        Sleep(2000);
        system("cls");
    }
    
    // if LL is empty than inserting a new node
    else if(isEmpty()){
        struct node* new_node = (struct node*)malloc(sizeof(struct node*));
        new_node->data = value;
        new_node->next = NULL;
        head = new_node;
    }

    // if LL is not empty than, inserting a new node
    // there is difference: if there is no node, than we just need to add a node, not traversal needed
    else{
        struct node* traverse = head;
        
        while(traverse->next != NULL){
            traverse = traverse->next;
        }
        struct node* new_node = (struct node*) malloc(sizeof(struct node));
        new_node->data = value;
        new_node->next = NULL;
        traverse->next = new_node;
    }
}

//creating a function to insert at a particular position
void insertAtPosition(int position, int value){
    // checking if LL is full or not
    if(isFull(head)){
        printf("Error: Stack Overflow\n");
        Sleep(2000);
        system("cls");
    }
    // if posistion is 0 than we simply need to insert at the beginning
    
    else if(position==0)
        insertAtBeginning(value);

    // we need to provide this check for empty Linked List case
    else if(isEmpty() && position!=0){
        printf("Error: Position not found in Linked List\n");
        Sleep(2000);
        system("cls");
    }
    
    // else we need to traverse to the position, can be done by just iteration the number of times
    else{
        int i = position;
        struct node* traverse = head;
        while(--i){
            traverse = traverse->next;
            // we need to check if position is > than the length of LL, than it's and Error
            if(traverse==NULL){
                printf("Error: Position not found in Linked List\n");
                Sleep(2000);
                system("cls");
                return;
            }
        }
        // we reached the position
        struct node* new_node = (struct node*)malloc(sizeof(struct node));
        new_node->data = value;
        new_node->next = traverse->next;
        traverse->next = new_node;
    }
}

//code for inserting after a particular value
void insertAfterValue(int value1, int value){
    // checking for empty linled list
    if(isEmpty()){
        printf("Linked List is Empty\n");
        Sleep(2000);
        system("cls");
    }
    else{
        struct node* traverse = head;           // node for traversal
        while(traverse->data != value1){        // traversal and checking value
            if(traverse->next == NULL){             // if it reached end and value is not found
                printf("Error: Value %d Not Found\n", value1);
                Sleep(1000);
                system("cls");
                return;
            }
            traverse = traverse->next;              // traversal algorithm
        }

        // creating new node and inserting it
        struct node* new_node = (struct node*) malloc(sizeof(struct node));
        new_node->data = value;
        new_node->next = traverse->next;
        traverse->next = new_node;
    }
}

// code to delete a node from beginning
void deleteFromBeginning(){
    if(isEmpty()){
        printf("Linked List is Empty\n");
        Sleep(2000);
        system("cls");
    }
    else{
        struct node* temp_node = head;      // creating a temp_node for freeing location, we can't let it be a floating node
       
       // shifting the first node, we don't need to check for it separately, this will work fine
        head = head->next;
        free(temp_node);
    }
}

//code to delete at end
void deleteAtEnd(){
    if(isEmpty()){
        printf("Error: Linked List is Empty\n");
        Sleep(2000);
        system("cls");
    }
    else{
        // checking for single node
        struct node* temp1 = head;  // will use for freeing the node

        if(head->next==NULL){
            head = NULL;
            free(temp1);
        }
        else{
            struct node* temp2 = temp1->next;   // this will be the forward node
            while(temp2->next!=NULL){
                temp1 = temp2;
                temp2 = temp2->next;
            }

            // when end is reached
            temp1->next = NULL;
            free(temp2);
        }
    }
}

//code to delete at a particular location
void deleteAtLocation(int location){
    if(isEmpty()){
        printf("Error: Linked List is Empty\n");
        Sleep(2000);
        system("cls");
    }
    else{
        if(location==0)
            deleteFromBeginning();
        else{
            // we need two pointers
            struct node* temp1 = head;
            struct node* temp2 = temp1->next;       // this is the forward node
            while(--location){
                temp1 = temp2;
                temp2 = temp2->next;

                // condition to check it we reached the end
                if(temp1->next==NULL){
                    printf("Error: Location is not in Linked List\n");
                    Sleep(2000);
                    system("cls");
                    return;
                }
            }

            // we reached the location
            temp1->next = temp2->next;
            free(temp2);
        }
    }
}

// code to delete a particular value
void deleteValue(int value){
    if(isEmpty()){
        printf("Error: Linked List is Empty\n");
        Sleep(2000);
        system("cls");
    }
    else{
        //checking if it's the first value
        if(head->data == value)
            deleteFromBeginning();
        else{
            struct node* temp1 = head;
            struct node* temp2 = temp1->next;       // forward node
            while(temp2->data != value){
                temp1 = temp2;
                temp2 = temp2->next;

                if(temp1->next==NULL){
                    printf("Error: Value is not in the Linked List\n");
                    Sleep(2000);
                    system("cls");
                    return;
                }
            }
            // when the particular value is found
            temp1->next = temp2->next;
            free(temp2);
        }
    }
}

// creating menu for Inserting
void INSERT(){
    int choice2, value1;
    while(choice2!=(-1)){
        printf("1 - Insert at the beginning\n2 - Insert at the End\n3 - Insert at a particular position\n4 - Insert after a value\n-1 - Return\n");
        scanf("%d", &choice2);
        system("cls");

        if(choice2==1){
            printf("Enter the Value to Insert\n");
            scanf("%d", &value1);
            system("cls");

            insertAtBeginning(value1);
        }
        else if(choice2==2){
            printf("Enter the Value to Insert\n");
            scanf("%d", &value1);
            system("cls");

            insertAtEnd(value1);
        }
        else if(choice2==3){
            printf("Enter the Value to Insert\n");
            scanf("%d", &value1);
            system("cls");

            printf("Enter the position at which %d is to inserted\n", value1);
            int pos;
            scanf("%d", &pos);
            system("cls");

            insertAtPosition(pos, value1);
        }
        else if(choice2==4){
            printf("Enter the Value to Insert\n");
            scanf("%d", &value1);
            system("cls");

            printf("Enter the value after which you want the insertion\n");
            int val;
            scanf("%d", &val);
            system("cls");

            insertAfterValue(val, value1);
        }
        else if(choice2==-1)
            return;
        else{
            printf("Wrong choice\n");
            Sleep(1000);
            system("cls");
        }
    }
}

//creating menu fro Deletion
void DEL(){
    int choice2, value1, loc;
    while(choice2!=(-1)){
        printf("1 - Delete at Start\n2 - Delete at End\n3 - Delete at a particular Location\n4 - Delete a Value\n-1 - Return\n");
        scanf("%d", &choice2);
        system("cls");

        if(choice2==1){
            deleteFromBeginning();
        }
        else if(choice2==2){
            deleteAtEnd();
        }
        else if(choice2==3){
            printf("Enter the Location to delete\n");
            scanf("%d", &loc);
            system("cls");
            
            deleteAtLocation(loc);
        }
        else if(choice2==4){
            printf("Enter the Value to Delete\n");
            scanf("%d", &value1);
            system("cls");

            deleteValue(value1);
        }
        else if(choice2==-1)
            return;
        else{
            printf("Wrong choice\n");
            Sleep(1000);
            system("cls");
        }
    }
}

// a type of Destructor
void freeEveryMemory(){
    while(head!=NULL){
        struct node* temp = head;
        head = head->next;
        free(temp);
    }
}

// function to create exit message and exit
int freeMessageAndExit(){
    for(int i=3; i>0; i--){
        system("cls");
        printf("Freeing Memory and Exiting in %d", i);
        for(int j=i; j>0; j--)
            printf(" .");
        printf("\n");
        Sleep(1000);
    }
    freeEveryMemory();  // a kind of destructor
    return 0;
}

int main(){
    int choice;
    while(choice!=(-1)){
        printf("1 - Insert an element\n2 - Delete an Element\n3 - Display the Linked List\n-1 - Exit\n");
        scanf("%d", &choice);
        system("cls");

        if(choice==1)
            INSERT();
        else if(choice==2)
            DEL();
        else if(choice==3)
            displayLL();
        else if(choice==(-1))
            freeMessageAndExit();
        else
            printf("Wrong choice\n");
    }
}