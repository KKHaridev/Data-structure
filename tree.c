#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *l_child;
    struct node *r_child;
};

struct node *root=NULL,*new_node,*ptr,*temp,*parent;

struct node * get_node(int ele){
    temp=(struct node *)malloc(sizeof(struct node));
    if(temp==NULL){
        return NULL;
    }
    else{
        temp->data=ele;
        temp->l_child=NULL;
        temp->r_child=NULL;
    }
    return temp;
}

void insert(int ele){
    new_node=get_node(ele);
    if(new_node!=NULL){
        if(root==NULL)
            root=new_node;
        else{
            ptr=root;
            int flag=0;
            while(ptr!=NULL && flag==0){
                if(ptr->data<new_node->data){
                    parent=ptr;
                    ptr=ptr->r_child;
                }
                else if(ptr->data>new_node->data){
                    parent=ptr;
                    ptr=ptr->l_child;
                }
                else{
                    flag=1;
                }
            }
            if(flag==1)
                printf("\nElement exist");
            else{
                if(parent->data<new_node->data)
                    parent->r_child=new_node;
                else
                    parent->l_child=new_node;
            }
        }
    }
    else{
        printf("no node created");
    }
}

void inorder(struct node *ptr){
    if(root==NULL)
        printf("\nEmpty");
    else{
        if(ptr!=NULL){
            inorder(ptr->l_child);
            printf("%d ",ptr->data);
            inorder(ptr->r_child);
        }
    }
}

void preorder(struct node *ptr){
    if(root==NULL)
        printf("\nEmpty");
    else{
        if(ptr!=NULL){
            printf("%d ",ptr->data);
            preorder(ptr->l_child);
            preorder(ptr->r_child);
        }
    }
}

void postorder(struct node *ptr){
    if(root==NULL)
        printf("\nEmpty");
    else{
        if(ptr!=NULL){
            postorder(ptr->l_child);
            postorder(ptr->r_child);
            printf("%d ",ptr->data);
        }
    }
}



void main(){
    int option,sub,num;
    do{
        printf("\n1.Insert\n2.Traverse\n3.exit\nEnter any option to continue : ");
        scanf("%d",&option);
        switch(option){
            case 1:
            printf("Enter the element : ");
            scanf("%d",&num);
            insert(num);
            break;
            case 2:
                do{
                    printf("\n1.Inorder\n2.Preorder\n3.Postorder\n4.Exit\nEnter any option to continue");
                    scanf("%d",&sub);
                    switch(sub){
                    case 1:
                    inorder(root);
                    break;
                    case 2:
                    preorder(root);
                    break;
                    case 3:
                    postorder(root);
                    break;
                    case 4:
                    printf("Exiting......");
                    break;
                    default:
                    printf("Enter valid option");

                    }
                }while(sub!=4);
                break;
            case 3:
            printf("Exiting......");
            break;
            default:
            printf("Enter valid option");

        }
    }while(option!=3);

}