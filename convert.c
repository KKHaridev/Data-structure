#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define max 20

int top=-1,i=0;
char infix[max],postfix[max],stack[max];


void push(char x)
{
  top++;
  stack[top] = x;
}

char pop()
{
    if(top == -1)
        return -1;
    else
        return stack[top--];
}

int priority(char item){
  if(item=='('){
    return(0);}
  if(item=='+'||item=='-'){
    return(1);}
  if(item=='*'||item=='/'){
    return(2);}
  if(item=='^'){
    return(3);
  }
  return 0;
}
void convert(){
  char exp[100];
  char *e, x;
  printf("Enter the expression : ");
  scanf("%s",exp);
  printf("\n");
  push('(');
  strcat(exp,")");
  e = exp;
  
  while(*e != '\0')
  {
    if(isalnum(*e))
      {
        postfix[i++]=*e;
      }
    else if(*e == '('){
        push(*e);

    }
    else if(*e == ')')
    {
      while((x=pop()) != '('){
        postfix[i++]=x;
      }
    }
    else{
      while(priority(stack[top]) >= priority(*e)){
        x=pop();
        postfix[i++]=x;        
      }
      push(*e);


    }
    e++;
  }
}
void evaluate(){
  char *pe;
  float A,B;
  pe=postfix;
  float value=0;
  while(*pe!='\0'){
    if(isalpha(*pe)){
      printf("Enter the value of %c :",*pe);
      scanf("%f",&value);
      push(value);
    }
    else if(isdigit(*pe)){
      push(*pe-'0');
    }
    else if(*pe=='*'||*pe=='/'||*pe=='+'||*pe=='-'||*pe=='^'){
      A=pop();

      B=pop();

      switch(*pe){
        case '*' :
            value=A*B;
            break;
        case '/' :
            value=A/B;
            break;
        case '+' :
            value=A+B;
            break;
        case '-' :
            value=A-B;
            break;
      }
    push(value);
     
    }
    pe++;
    
  }
  printf("%.2f\n",value);
}
int main(void) {
  convert();
  printf("Postfix Expression : ");
  puts(postfix);
  printf("Postfix Evaluation : ");
  evaluate();

  return 0;
}
