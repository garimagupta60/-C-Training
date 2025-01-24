#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node* next;
}node;

node* head = NULL;

node* createNode(int value){
    node* newnode = (node *)malloc(sizeof(node));
    if(newnode==NULL){
        printf("Memory allocation failed\n");
        exit(1);
    }
    newnode->data = value;
    newnode->next = NULL;
    return newnode;
}

node* findmiddle(node* head){
    node* slow = head;
    node* fast = head->next;
    while (fast && fast->next)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

node* merge(node* left, node* right){
    node* ans = createNode(-1);
    node* temp = ans;
    while(left!=NULL && right!=NULL){
        if(left->data <= right->data){
            temp->next = left;
            temp= temp->next;
            left = left->next;
        }else{
            temp->next = right;
            temp= temp->next;
            right = right->next;
        }
    }

    // while(left){
    //     temp->next = left;
    //     temp= temp->next;
    //     left = left->next;
    // }
    // while(right){
    //     temp->next = right;
    //     temp= temp->next;
    //     right = right->next;
    // }
    if(left){
        temp->next = left;
    }
    if(right){
        temp->next = right;
    }

    return ans->next;    

}

node* mergesort(node* head){
    if(head == NULL || head->next == NULL){
        return head;
    }
    node* middle = findmiddle(head);
    node* left = head;
    node* right = middle->next;
    middle->next = NULL;

    left = mergesort(left);
    right = mergesort(right);
    return merge(left,right);
}

void displaylist(){
    node* current = head;
    if(head==NULL){
        printf("Empty list\n");
        return ;
    }
    while(current!=NULL){
        if(current->next!=NULL){
            printf("%d->",current->data);
        }else{
            printf("%d",current->data);
        }
        current = current->next;
    }
}



// node* insertNode()
// {
//     node* tail = NULL;
//     while(1)
//     {
//         int value ;
//         scanf("%d",&value);
//         if(head == NULL)
//         {
//             head = (node*)malloc(sizeof(node));
//             head->data = value;
//             head->next = NULL;
//             tail = head;
//         }
//         else
//         {
//             node* nn = (node*)malloc(sizeof(node));
//             nn->data = value;
//             nn->next = NULL;
//             tail->next = nn;
//             tail = tail->next;
//         }

//         char ch = getchar();
//         if(ch == '\n' || ch == EOF)
//         break;


//     }
//     return head;
// }

void insertnode(int value){
    node* newnode = createNode(value);
    if(head==NULL){
        head = newnode;
        return;
    }else{
        node* current = head;
        while(current->next!=NULL){
            current = current->next;
        }
        current->next = newnode;
    }

}
int main(){ 

    while(1){
        int value;
        if(scanf("%d",&value)!=1){
            break;
        }

        insertnode(value);
        int ch = getchar();
        if(ch=='\n' || ch==EOF){
            break;
        }
    }
    printf("Original list: ");
    displaylist();

    head = mergesort(head);

    printf("Sorted list: ");

    displaylist();
    return 0;

}