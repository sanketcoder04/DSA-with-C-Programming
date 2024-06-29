#include<stdio.h>
#include<string.h>
#define max 100
#define true 1
#define false 0

char str[max];
int top = -1;

void push(char data){
    if(top == max-1){
        printf("Stack is Overflow");
        return;
    }
    top++;
    str[top] = data;
}

char pop(){
    if(top == -1){
        printf("Stack is Underflow");
    }
    //printf("Popped item is %d\n",arr[top]);
    return str[top--];
}

void getExp(){
    printf("Enter Expression");
    gets(str);
}

void checkValid(){
    int valid = true;
    for(int i = 0;i<strlen(str);i++){
        if(str[i] == '(' || str[i] == '{' || str[i] == '['){
            push(str[i]);
        }
        if(str[i] == ')' || str[i] == '}' || str[i] == ']'){
            if(top == -1){  //Empty Stack
                valid = false;
            }
            else{
                int temp = pop();
                if(str[i] == ')' && (temp == '{' || temp == '[')){  //Check with )
                    valid = false;
                }
                if(str[i] == '}' && (temp == '(' || temp == '[')){  //Check with }
                    valid = false;
                }
                if(str[i] == ']' && (temp == '{' || temp == '(')){  //Check with ]
                    valid = false;
                }
            }
        }
    }
    if(top>=0){     //Not Empty Stack
        valid = false;
    }
    if(valid == true){
        printf("Valid Expression");
    }else{
        printf("Non-valid Expression");
    }
}
int main(){
    getExp();
    checkValid();
    return 0;
}

