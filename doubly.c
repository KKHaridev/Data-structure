#include<stdio.h>
#include<stdlib.h>


struct node{
	int data;
    struct node *before_link;
	struct node *next_link;
};

struct node *head=NULL;
struct node *new_node,*current_node,*prev_node,*next_node,*last_node;
int pos;

struct node * get_node(){
	int ele;
	struct node *temp;
	temp = (struct node*)malloc(sizeof(struct node));
	if(temp==NULL){
		return NULL;
	}
	else{
		printf("enter the element to insert");
		scanf("%d",&ele);
		temp->data=ele;
		temp->next_link=NULL;
	}
	return temp;	
}
void insert_beg(){
	new_node=get_node();
	if(new_node!=NULL){
		if(head==NULL){
			head=new_node;
		}
		else{
            new_node->before_link=NULL;
			new_node->next_link=head;
			head=new_node;
            current_node=new_node->next_link;
            current_node->before_link=new_node;
		}
	}
	else{
		printf("\nno node created\n");
	}
}
void insert_last(){
	new_node=get_node();
		if(new_node!=NULL){
			if(head==NULL){
				head=new_node;

			}
			else{
				current_node=head;
				while(current_node->next_link!=NULL)
				{
					current_node=current_node->next_link;
				}
				current_node->next_link=new_node;
				new_node->before_link=current_node;
			}
		}
		else{
			printf("\nno node created\n");
		}
}
void insert_mid(int pos){
	int i;
		new_node=get_node();
		if(new_node!=NULL){
			current_node=head;
			while(current_node!=NULL&&current_node->data!=pos)
                current_node=current_node->next_link;
            if(current_node==NULL){
                printf("\nelement not found\n");
            }
            else{
                new_node->before_link=current_node;
                new_node->next_link=current_node->next_link;
				next_node=new_node->next_link;
				next_node->before_link=new_node;
                current_node->next_link=new_node;
				

            }
		}
		else{
			printf("\nno node created\n");
		}
}
void display(){
	int count=0;
	printf("\n***************Doubly linked list***************\n\n");
	if(head==NULL)
		printf("empty");
	else{
		current_node=head;
		while(current_node!=NULL){
            
			printf("|%u||%d||%u|",current_node->before_link,current_node->data,current_node->next_link);
            
			current_node=current_node->next_link;
            if(current_node!=NULL){
                printf("-->");
            }
			count=count+1;
		}
	}
	printf("\n\ncount : %d",count);
    printf("\n\n***************Doubly linked list***************\n");
}
void display_rev(){
	int count=0;
	printf("\n***************Doubly linked list Reverse***************\n\n");
	if(head==NULL)
		printf("empty");
	else{
		current_node=head;
		while(current_node->next_link!=NULL)
				{
					current_node=current_node->next_link;
				}
		last_node=current_node;
		while(last_node!=NULL){
		    
				
			printf("|%u||%d||%u|",last_node->next_link,last_node->data,last_node->before_link);
			last_node=last_node->before_link;
			            if(last_node!=NULL){
			                printf("-->");
			            }
			
		}
	
    printf("\n\n***************Doubly linked list Reverse***************\n");
	}
}
void delete_beg(){
	current_node=head;
    if(head==NULL){
        printf("\nempty\n");
    }
	else if(current_node->next_link==NULL){
		free(current_node);
		head=NULL;
	}
    else{
        
        head=current_node->next_link;
        next_node=head;
        next_node->before_link=NULL;

        free(current_node);

    }
}
void delete_last(){
        current_node=head;
    if(head==NULL){
        printf("\nempty\n");
    }
	else if(current_node->next_link==NULL){
		free(current_node);
		head=NULL;
	}
    else{
		
		while(current_node->next_link!=NULL)
		{
			current_node=current_node->next_link;
		}
		prev_node=current_node->before_link;
		prev_node->next_link=NULL;

        free(current_node);
    }
}

void delete_mid(int pos){
    if(head==NULL){
        printf("\nempty\n");
    }
    else{
        current_node=head;
        next_node=current_node->next_link;
        while(current_node->data!=pos&&current_node->next_link!=NULL){
            next_node=next_node->next_link;
            current_node=current_node->next_link;
        }
        new_node=next_node->next_link;
        current_node->next_link=next_node->next_link;
        new_node->before_link=current_node;
        free(next_node);
    }
}


void main(){
	int ch;
	int sub;
	do{
		printf("\n1.insert\n2.delete\n3.traverse\n4..exit\nenter choice");
		scanf("%d",&ch);

		switch(ch){
			case 1:
				
				do{
					printf("\n1.insert first\n2.insert end\n3.insert mid\n4.exit\nenter choice");
					scanf("%d",&sub);
					switch(sub){
						case 1:
							insert_beg();
							break;
						case 2:
							insert_last();
							break;
						case 3:
							printf("key : ");
							scanf("%d",&pos);
							insert_mid(pos);
							break;
						default:
							printf("\nenter valid choice\n");
					}
				}while(sub!=4);
				break;
			case 2:
				do{
					printf("\n1.delete first\n2.delete end\n3.delete mid\n4.exit\nenter choice");
					scanf("%d",&sub);
					switch(sub){
						case 1:
							delete_beg();
							break;
						case 2:
							delete_last();
							break;
						case 3:
							printf("key : ");
							scanf("%d",&pos);
							delete_mid(pos);
							break;
						default:
							printf("\nenter valid choice\n");
					}
				}while(sub!=4);
				break;
			case 3:
				do{
					printf("\n1.forward traversal\n2.reverse traversal\n3.exit\nenter choice");
					scanf("%d",&sub);
					switch(sub){
						case 1:
							display();
							break;
						case 2:
							display_rev();
							break;
						default:
							printf("\nenter valid choice\n");
					}
				}while(sub!=3);
				break;
			default:
				printf("\nenter valid choice\n");
		}
		}while(ch!=4);
}
