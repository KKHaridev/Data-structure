/*
K K Haridev
CSE B
*/
#include<stdio.h>
#include<stdlib.h>


struct node{
	int data;
    struct node *before_link;
	struct node *next_link;
};

struct node *head=NULL;
struct node *new_node,*current_node,*prev_node,*next_node,*last_node;
int key;

struct node * get_node(){
	int ele;
	struct node *temp;
	temp = (struct node*)malloc(sizeof(struct node));
	if(temp==NULL){
		return NULL;
	}
	else{
		printf("\tEnter the element to insert : ");
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
		printf("\nNo node created\n");
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
			printf("\nNo node created\n");
		}
}
void insert_mid(int key){
	int i;
		new_node=get_node();
		if(new_node!=NULL){
			current_node=head;
			while(current_node!=NULL&&current_node->data!=key){
                current_node=current_node->next_link;
			}
            if(current_node==NULL){
                printf("\nElement not found\n");
            }
			else if(current_node->next_link==NULL){
				current_node=head;
				while(current_node->next_link!=NULL)
				{
					current_node=current_node->next_link;
				}
				current_node->next_link=new_node;
				new_node->before_link=current_node;
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
			printf("\nNo node created\n");
		}
}
void display(){
	int count=0;
	printf("\n***************Doubly linked list***************\n\n");
	if(head==NULL)
		printf("Empty");
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
	printf("\n\nCount : %d",count);
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
        printf("\nEmpty\n");
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
        printf("\nEmpty\n");
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

void delete_mid(int key){
    if(head==NULL){
        printf("\nEmpty\n");
    }
    else{
        current_node=head;
        next_node=current_node->next_link;
        while(current_node->data!=key&&current_node->next_link!=NULL){
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
		printf("\n1.Insert\n2.Delete\n3.Traverse\n4.Exit\nEnter choice : ");
		scanf("%d",&ch);

		switch(ch){
			case 1:
				
				do{
					printf("\n\t1.Insert first\n\t2.Insert end\n\t3.Insert mid\n\t4.Exit\n\tEnter choice : ");
					scanf("%d",&sub);
					switch(sub){
						case 1:
							insert_beg();
							break;
						case 2:
							insert_last();
							break;
						case 3:
							printf("\tKey : ");
							scanf("%d",&key);
							insert_mid(key);
							break;
						case 4:
							printf("\nBack to main menu...");
							break;
						default:
							printf("\n\tEnter valid choice\n");
					}
				}while(sub!=4);
				break;
			case 2:
				do{
					printf("\n\t1.Delete first\n\t2.Delete end\n\t3.Delete mid\n\t4.Exit\n\tEnter choice : ");
					scanf("%d",&sub);
					switch(sub){
						case 1:
							delete_beg();
							break;
						case 2:
							delete_last();
							break;
						case 3:
							printf("\tKey : ");
							scanf("%d",&key);
							delete_mid(key);
							break;
						case 4:
							printf("\nBack to main menu...");
							break;
						default:
							printf("\n\tEnter valid choice\n");
					}
				}while(sub!=4);
				break;
			case 3:
				do{
					printf("\n\t1.Forward traversal\n\t2.Reverse traversal\n\t3.Exit\n\tEnter choice : ");
					scanf("%d",&sub);
					switch(sub){
						case 1:
							display();
							break;
						case 2:
							display_rev();
							break;
						case 3:
							printf("\nBack to main menu...");
							break;
						default:
							printf("\n\tEnter valid choice\n");
					}
				}while(sub!=3);
				break;
			case 4:
				printf("\nExiting...");
				break;
			default:
				printf("\nEnter valid choice\n");
		}
		}while(ch!=4);
}
