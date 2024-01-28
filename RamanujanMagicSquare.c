#include<stdio.h>
#include<conio.h>

int a[4][4], b[4][4];
int dd, mm, yy1, yy2, sum=0;

void getInput(){
    printf("Enter your date of birth\nDD: ");
    
    scanf("%d", &dd);
    printf("MM: ");
    scanf("%d", &mm);
    printf("YYYY: ");
    int temp;
    scanf("%d", &temp);

    yy1 = temp/100;
    yy2 = temp%100;
}

void executeProgram(){
    sum = dd + mm + yy1 + yy2;
	
    a[2][0] = dd;
	a[0][3] = mm;
	a[1][2] = yy1;
	a[3][1] = yy2;
	
    a[0][0] = a[0][3] - 3;
    a[0][1] = a[0][3] - 2;
    a[0][2] = a[0][3] - 1;
    a[1][0] = a[1][2] - 2;
    a[1][1] = a[1][2] - 1;
    a[1][3] = a[1][2] + 1;
    a[2][1] = a[2][0] + 1;
    a[2][2] = a[2][0] + 2;
    a[2][3] = a[2][0] + 3;
    a[3][0] = a[3][1] - 1;
    a[3][2] = a[3][1] + 1;
    a[3][3] = a[3][1] + 2;

    b[0][0] = a[2][0];
    b[0][1] = a[0][3];
    b[0][2] = a[1][2];
    b[0][3] = a[3][1];
    b[1][0] = a[3][2];
    b[1][1] = a[1][1];
    b[1][2] = a[0][0];
    b[1][3] = a[2][3];
    b[2][0] = a[0][1];
    b[2][1] = a[2][2];
    b[2][2] = a[3][3];
    b[2][3] = a[1][0];
    b[3][0] = a[1][3];
    b[3][1] = a[3][0];
    b[3][2] = a[2][1];
    b[3][3] = a[0][2];
}

void showOutput(){
    printf("\n------------------------------\n");
    printf("YOUR MAGIC SQUARE:");
    printf("\n------------------------------\n");
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            printf("%d \t",b[i][j]);
        }
        printf("\n");
    }
    printf("------------------------------\n");
    printf("Sum of Numbers is: %d", sum);
    printf("\n------------------------------\n");
}

int main() {
    getInput();
    executeProgram();
    showOutput();

    // getch(); // for cmd
    return 0;
}