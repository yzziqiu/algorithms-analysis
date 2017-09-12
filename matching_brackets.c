//matching bracket
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LENMAX 50
typedef struct stack
{
	char ch[50];
	int top;
}SK;
//initialize stack
SK *SK_init()
{
	SK *sk;
	if (sk=(SK *)malloc(sizeof(SK)))
	{
		sk->top=0;
		return sk;
	}
	return NULL;
}
//pop
int SK_pop(SK *sk)
{
	if (sk->top==0)
	{
		printf("stack is empty\n");
		return 0;
	}
	sk->top--; //stack pointer moves down
	return sk->ch[sk->top];
}
//push
void SK_push(SK *sk, char c)
{
	if (sk->top==LENMAX)
	{
		printf("overflow\n");
		return;
	}
	sk->ch[sk->top]=c;
	sk->top++; //stack pointer moves up
}
//matching function
void match(SK *sk, char *a)
{
	int i;
	//push to stack
	SK_push(sk,a[0]);
	//iterate
	for(i=1;i<strlen(a);i++)
	{
		//match
		if((a[i]==']'&& sk->ch[sk->top-1]=='[')||(a[i]==')'&&sk->ch[sk->top-1]=='('))
		{
			SK_pop(sk);
		}
		else
		{
			SK_push(sk,a[i]);

		}
	}
	if(sk->top==0)
	{printf("matched\n");}
	else
	{printf("not matched")}
}
