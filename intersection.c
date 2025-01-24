#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node* next;
}node;

node* createNode(int value) {
    node* newNode = (node*)malloc(sizeof(node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

int getlength(node* head){
    node* current = head;
    int length = 0;
    while(current!=NULL){
        length++;
        current = current->next;
    }
    return length;
}

node* findIntersection(node* head1, node* head2){
    int list1_length = getlength(head1);
    int list2_length = getlength(head2);

    //printf("l1 = %d l2 = %d\n",list1_length,list2_length);

    if(list1_length<list2_length)return findIntersection(head2,head1);

    int length_difference = list1_length-list2_length;

    //printf("Diff = %d\n",length_difference);

    node* current1 = head1;
    while (length_difference>0)
    {   
        if(current1==NULL){
            return NULL;
        }
        //printf("%d ",current1->data);
        current1 = current1->next;
        length_difference--;
    }

    node* current2 = head2;
    while(current1!=NULL && current2!=NULL){
        if(current1 == current2){
            return current1;
        }
        current1 = current1->next;
        current2 = current2->next;
    }
    return NULL;
}
int main(){

    node* head1 = NULL;
    node* head2 = NULL;

    head1 = createNode(10);
    head1->next = createNode(15);
    head1->next->next = createNode(30);

    // creation of second list: 3 -> 6 -> 9 -> 15 -> 30
    head2 = createNode(3);
    head2->next = createNode(6);
    head2->next->next = createNode(9);
    head2->next->next->next = head1->next;

    node* intersectionNode = findIntersection(head1,head2);

    if(intersectionNode == NULL){
        printf("No intersection b/w lists\n");
    }
    else{
        printf("Intersection Node = %d",intersectionNode->data);
    }
    return 0;
}