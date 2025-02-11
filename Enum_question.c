#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef enum{
    ONE,
    LOG_N,
    SQRT_N,
    N,
    N_LOG_N,
    N_K,
    TWO_N,
    FACTORIAL_N,
}Complexity;

typedef struct node{
    Complexity time_complexity;
    Complexity space_complexity;
    struct node* next;
}node;

node* create_node(Complexity time_complexity, Complexity space_complexity){
    node* newnode = (node*)malloc(sizeof(node));
    newnode->time_complexity = time_complexity;
    newnode->space_complexity = space_complexity;
    newnode->next = NULL;
    return newnode;
}

void modify(char complexity[100]){
    if(strcmp(complexity,"1")==0){
        strcpy(complexity,"ONE");
    }
    else if(strcmp(complexity,"n")==0){
        strcpy(complexity,"N");
    }
    else if(strcmp(complexity,"logn")==0){
        strcpy(complexity,"LOG_N");
    }
    else if(strcmp(complexity,"n!")==0){
        strcpy(complexity,"FACTORIAL_N");
    }
    else if(strcmp(complexity,"2^n")==0){
        strcpy(complexity,"TWO_N");
    }
    else if(strcmp(complexity,"n^k")==0){
        strcpy(complexity,"N_K");
    }
    else if(strcmp(complexity,"sqrt(n)")==0){
        strcpy(complexity,"SQRT_N");
    }
    else if(strcmp(complexity,"nlogn")==0){
        strcpy(complexity,"N_LOG_N");
    }
}

Complexity get_enum(char input[100]){
    if(strcmp("ONE", input) == 0) return ONE;
    if(strcmp("LOG_N", input) == 0) return LOG_N;
    if(strcmp("SQRT_N", input) == 0) return SQRT_N;
    if(strcmp("N", input) == 0) return N;
    if(strcmp("N_LOG_N", input) == 0) return N_LOG_N;
    if(strcmp("N_K", input) == 0) return N_K;
    if(strcmp("TWO_N", input) == 0) return TWO_N;
    return FACTORIAL_N;
}

char* mapFromComplexity(Complexity complexity){
    switch (complexity){
        case ONE: return "1";
        case LOG_N: return "logn";
        case SQRT_N: return "sqrt(n)";
        case N: return "n";
        case N_LOG_N: return "nlogn";
        case N_K: return "n^k";
        case TWO_N: return "2^n";
        default: return "n!";
    }
}

void insert(node** head, Complexity time_complexity, Complexity space_complexity){
    node* newnode = create_node(time_complexity,space_complexity);
    if(*head == NULL){
        *head = newnode;
        return;
    }
    node* current = *head;
    while(current->next!=NULL){
        current = current->next;
    }
    current->next = newnode;
}


void get_input(node** head){
    char time_complexity[100];
    char space_complexity[100];
    int numberofoperations = 0;
    scanf("%d",&numberofoperations);
    while (numberofoperations)
    {
        scanf("%s %s",time_complexity,space_complexity);
        modify(time_complexity);
        modify(space_complexity);
        insert(head,get_enum(time_complexity),get_enum(space_complexity));
        numberofoperations--;
    }
}
node* findmiddle(node* head){
    node* slow  = head;
    node* fast = head->next;
    while(fast && fast->next){
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}
node* merge(node* left, node* right){
    node* dummy = create_node(get_enum("1"),get_enum("1"));
    node* ans = dummy;
    Complexity temp_time;
    Complexity temp_space;
    while(left!=NULL && right!=NULL){
        if(left->time_complexity < right->time_complexity){
            ans->next = left;
            left = left->next;
            ans = ans->next;
        }else if(left->time_complexity > right->time_complexity){
            ans->next = right;
            right = right->next;
            ans = ans->next;
        }else{
            if(left->space_complexity < right->space_complexity){
                ans->next = left;
                left = left->next;
                ans = ans->next;
            }else{
                ans->next = right;
                right = right->next;
                ans = ans->next;
            }
        }
    }
    if(left){
        ans->next = left;
    }
    if(right){
        ans->next = right;
    }
    return dummy->next;
}
node* mergesort(node* head){

    if(head == NULL || head -> next == NULL) {
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

void sort(node** head){
    *head = mergesort(*head);
}
void print(node* head){
    node* current = head;
    printf("\n");
    while(current!= NULL){
        printf("%s %s\n",mapFromComplexity(current->time_complexity), mapFromComplexity(current->space_complexity));
        current = current->next;
    }
}

int main(){
    node* head = NULL;
    get_input(&head);
    sort(&head);
    print(head);
    return 0;
}
