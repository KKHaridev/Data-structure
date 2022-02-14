#include<stdio.h>
#include<stdlib.h>

struct node{
	int ele;
	int exp;
	struct node *n_link;
};

struct node *head1=NULL,*head2=NULL,*head=NULL,*current_node_f,*current_node_s,*current_node,*result,*temp,*new_node;

struct node * get_node(int data,int power){
	temp=(struct node *)malloc(sizeof(struct node));
	if(temp==NULL)
		return NULL;
	else{
		temp->ele=data;
		temp->exp=power;
		temp->n_link=NULL;
	}


	return temp;
}

void insert_f(int ele,int exp){
	new_node=get_node(ele,exp);
	if(new_node!=NULL){
		if(head1==NULL)
			head1=new_node;
		else{
			current_node_f=head1;
			while(current_node_f->n_link!=NULL){
				current_node_f=current_node_f->n_link;
			}
			current_node_f->n_link=new_node;
		}
	}
}

void insert_s(int ele,int exp){
	new_node=get_node(ele,exp);
	if(new_node!=NULL){
		if(head2==NULL)
			head2=new_node;
		else{
			current_node_s=head2;
			while(current_node_s->n_link!=NULL){
				current_node_s=current_node_s->n_link;
			}
			current_node_s->n_link=new_node;
		}
	}
}

void insert(int ele,int exp){
	new_node=get_node(ele,exp);
	if(new_node!=NULL){
		if(head==NULL)
			head=new_node;
		else{
			current_node=head;
			while(current_node->n_link!=NULL){
				current_node=current_node->n_link;
			}
			current_node->n_link=new_node;
		}
	}
}

void r_esult(){
	int data,expo;
	current_node_f=head1;
	current_node_s=head2;
	while(current_node_f!=NULL && current_node_s!=NULL){
		if(current_node_f->exp==current_node_s->exp){
			
			data=current_node_f->ele+current_node_s->ele;
			expo=current_node_s->exp;
			insert(data,expo);
			current_node_s=current_node_s->n_link;
			current_node_f=current_node_f->n_link;

			
		}
		else if(current_node_f->exp>current_node_s->exp){
			data=current_node_f->ele;
			expo=current_node_f->exp;
			insert(data,expo);
			current_node_f=current_node_f->n_link;

		}
		else if(current_node_f->exp<current_node_s->exp){
			data=current_node_s->ele;
			expo=current_node_s->exp;
			insert(data,expo);
			current_node_s=current_node_s->n_link;

		}
	}
			
	

	
}


void display(){
		printf("\n***************Doubly linked list***************\n\n");
		if(head1==NULL&&head2==NULL)
			printf("Empty");
		else{
			current_node_f=head1;
			current_node_s=head2;
			current_node=head;
			printf("First\n");
			while(current_node_f!=NULL){
	            
				printf("|%d||%d||%u|",current_node_f->ele,current_node_f->exp,current_node_f->n_link);
	            
				current_node_f=current_node_f->n_link;
	            if(current_node_f!=NULL){
	                printf("-->");
	            }
			}
			printf("\n\n");
			printf("Second\n");

			while(current_node_s!=NULL){
				            
					printf("%d^%d",current_node_s->ele,current_node_s->exp);
		            
					current_node_s=current_node_s->n_link;
		            if(current_node_s!=NULL){
		                printf("+");
		            }
				}

			printf("\n\n");
			printf("Result\n");

			while(current_node!=NULL){
				            
					printf("%d^%d",current_node->ele,current_node->exp);
		            
					current_node=current_node->n_link;
		            if(current_node!=NULL){
		                printf("+");
		            }
				}
		}
		
	    printf("\n\n***************Doubly linked list***************\n");
}
void main(){
	int ch,ele,exp;
	do{
		printf("\n1.Insert first equ\n2.insert second equ\n3.Display\n4.Exit\nEnter choice : ");
		scanf("%d",&ch);
		switch(ch){
			case 1:
				do{
					printf("enter ele and exp (to exit type 0 0): ");
					scanf("%d%d",&ele,&exp);
					if(ele==0&&exp==0)
						break;
					insert_f(ele,exp);
				}while(ele!=0 && exp!=0);
				break;
			case 2:
				do{
					printf("enter ele and exp (to exit type 0 0): ");
					scanf("%d%d",&ele,&exp);
					if(ele==0&&exp==0)
						break;
					insert_s(ele,exp);
				}while(ele!=0 && exp!=0);
				break;
			case 3:
				r_esult();
				display();
				break;
			case 4:
				printf("\nBack to main menu...");
				break;
			default:
				printf("\n\tEnter valid choice\n");
		}
	}while(ch!=4);
}
