/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\                                                           
 * Hanoi tower solution without recursion                *
 *                                                                   *
 *                                                                   *
 * prepared by:                                                      *
 * Supun Athukorala                                                  *
 * Department of Computer Engineering                                *
 * Faculty of Engineering											 *
 * University of Peradeniya                                          *
 *                                                                   * 
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */ 

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* Data structure used :- Stacks */
struct stack_node { 
  int data; 						
  struct stack_node *next; 
};

typedef struct stack_node stack_node_t; 
typedef stack_node_t *stack_t; 


int push(int data, stack_t *stack); 
int pop(int *data, stack_t *stack);

int main(){

    int n,i,j,k;
    char peg1='A',peg2='B',peg3='C'; 
	stack_t pegA=NULL;
	stack_t pegB=NULL;
	stack_t pegC=NULL;


    printf("Please enter the number of disks:\n");
    scanf("%d",&n);
    
	
	push(n+2, &pegA);	//  These pieces are added to the pegs to ensure that the all disks are moved  
	push(n+2, &pegB);	//  from pag A to Peg C 
	push(n+2, &pegC);	//  Also to start the process;

	for(i=n;i>=1;i--)
		{
		push(i, &pegA);
		}
	printf("These are the movements you should do:\n");
	
if ( n==1 ) 
{
printf("Move Disk %d from %c to %c\n",n,peg1,peg3); 
} 
else if (n%2==0)
{

/*__________________For Even Number of Disks_______________________________________*/
for(k=1;k<=pow (2,n);k++)
	{


		pop(&i, &pegA);
		pop(&j, &pegB);
		if(i==n+2 && j == n+2){break;}     // to see the process is done(n+2 pieces are popped)
		if(i<j){
		printf("Move Disk %d from %c to %c\n",i,peg1,peg2);  // move from peg A to B
		push(j, &pegB);
		push(i, &pegB);
		k=k+1;
		}
		else
		{
		printf("Move Disk %d from %c to %c\n",j,peg2,peg1);  // move from peg B to A
		push(i, &pegA);
		push(j, &pegA);
		k=k+1;
		}

		

		pop(&i, &pegA);
		pop(&j, &pegC);
		if(i<j){	
		printf("Move Disk %d from %c to %c\n",i,peg1,peg3);  //  move from peg A to C 
		push(j, &pegC);
		push(i, &pegC);
		
		k=k+1;		
		}
		else
		{	
		printf("Move Disk %d from %c to %c\n",j,peg3,peg1);  //  move from peg C to A 
		push(i, &pegA);
		push(j, &pegA);
		k=k+1;
		}


		pop(&i, &pegB);
		pop(&j, &pegC);
		if(i<j){	
		printf("Move Disk %d from %c to %c\n",i,peg2,peg3);  // move from peg B to C 
		push(j, &pegC);
		push(i, &pegC);
		}
		else
		{	
		printf("Move Disk %d from %c to %c\n",j,peg3,peg2);  //  move from peg C to B 
		push(i, &pegB);
		push(j, &pegB);
	
		}
	}
}
else 

/*________ For odd Number of Disks _____________________________________________________*/	
{
for(k=1;k<=pow(2,n);k++)
	{
		pop(&i, &pegA);
		pop(&j, &pegC);
		if(i<j){	
		printf("Move Disk %d from %c to %c\n",i,peg1,peg3);  //move disk from peg A to C 
		push(j, &pegC);
		push(i, &pegC);
		k=k+1;
		}
		else
		{	
		printf("Move Disk %d from %c to %c\n",j,peg3,peg1);  //  move disk from peg C to A 
		push(i, &pegA);
		push(j, &pegA);
		k=k+1;
		}


		pop(&i, &pegA);
		pop(&j, &pegB);
		if(i==n+2 && j == n+2){break;}            // to see the process is done(n+2 pieces are popped)
		if(i<j){
		printf("Move Disk %d from %c to %c\n",i,peg1,peg2);  // move from peg A to B 
		push(j, &pegB);
		push(i, &pegB);
		k=k+1;
		}
		else
		{	
		printf("Move Disk %d from %c to %c\n",j,peg2,peg1);  //  move from peg B to A 
		push(i, &pegA);
		push(j, &pegA);
		k=k+1;
		}


		pop(&i, &pegB);
		pop(&j, &pegC);
		if(i<j){
		printf("Move Disk %d from %c to %c\n",i,peg2,peg3);  //move from peg B to C 
		push(j, &pegC);
		push(i, &pegC);
		}
		else
		{	
		printf("Move Disk %d from %c to %c\n",j,peg3,peg2);  //  move from peg C to B 
		push(i, &pegB);
		push(j, &pegB);
		}
	
	}

}
return 0;
}

/*_________________Functions that are used in___________________________*/
int push(int data, stack_t *stack)
{
  stack_node_t *tmp = malloc(sizeof(stack_node_t));
  if(tmp) {
    tmp -> data = data; 
    tmp -> next = *stack; 
    *stack = tmp; 
    return 0; 
  }
  return -1; 
}

int pop(int *data, stack_t *stack) 
{
  if(*stack) { 
    stack_node_t *tmp;
    tmp = *stack; 
    *stack = (*stack) -> next; 
    *data = tmp -> data; 
  free(tmp);
    return 1;
  }
  return 0;
}

