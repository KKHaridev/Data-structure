#include<stdio.h>
#include<stdlib.h>


struct node{
	int data;
	struct node *next_link;
};

struct node *head=NULL;
struct node *new_node,*current_node,*prev_node,*next_node;
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
			new_node->next_link=head;
			head=new_node;
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
			else
				current_node=head;
				while(current_node->next_link!=NULL)
				{
					current_node=current_node->next_link;
				}
				current_node->next_link=new_node;
			
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
                new_node->next_link=current_node->next_link;
                current_node->next_link=new_node;

            }
		}
		else{
			printf("\nno node created\n");
		}
}
void display(){
	int count=0;
	printf("\n***************linkedlist***************\n\n");
	if(head==NULL)
		printf("empty");
	else{
		current_node=head;
		while(current_node!=NULL){
            
			printf("|%d||%u|",current_node->data,current_node->next_link);
            
			current_node=current_node->next_link;
            if(current_node!=NULL){
                printf("-->");
            }
			count=count+1;
		}
	}
	printf("\n\ncount : %d",count);
    printf("\n\n***************linkedlist***************\n");
}
void delete_beg(){
    if(head==NULL){
        printf("\nempty\n");
    }
    else{
        current_node=head;
        head=current_node->next_link;

        free(current_node);

    }
}
void delete_last(){
    if(head==NULL){
        printf("\nempty\n");
    }
    else{
        current_node=head;
        while(current_node->next_link!=NULL){
            prev_node=current_node;
            current_node=current_node->next_link;
        }
        free(current_node);

        prev_node->next_link=NULL;
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
        current_node->next_link=next_node->next_link;
        free(next_node);
    }
}
void search(int pos){
	if(head==NULL){
        printf("\nempty\n");
    }
	else{
		int count=0;
		if(new_node!=NULL){
			current_node=head;
			while(current_node!=NULL&&current_node->data!=pos){
                current_node=current_node->next_link;
				count=count+1;
			}
            if(current_node==NULL){
                printf("\nelement not found\n");
            }
            else{
			printf("|%d||%u|",current_node->data,current_node->next_link);
            }
		printf("\n\nin %d node",count+1);

		}
			
		
		else{
			printf("\nnot found\n");
		}
	}
}


void main(){
	int ch;
	do{
		printf("\n1.insert first\n2.insert end\n3.insert mid\n4.delete first");
		printf("\n5.delete last\n6.delete mid\n7.display & count\n8.search\n9.exit\nenter choice");
		scanf("%d",&ch);

		switch(ch){
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
			case 4:
                delete_beg();
				break;
			case 5:
                delete_last();
				break;
			case 6:
                printf("key : ");
				scanf("%d",&pos);
                delete_mid(pos);
				break;
			case 7:
				display();
				break;
			case 8:
				printf("key : ");
				scanf("%d",&pos);
				search(pos);
				break;
			} 
		}while(ch!=9);
}