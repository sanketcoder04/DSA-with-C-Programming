#include<stdio.h>
#include<stdlib.h>

//Structure Node

struct Node{
    int data;
    struct Node *next;
};

//create Linked List

struct Node* create(struct Node *head,int size){
    struct Node *temp;
    int value;
    for(int i=0;i<size;i++){
        if(i==0){
            printf("Enter Value:");
            scanf("%d",&value);
            head->data = value;
            if(size == 1){
                head->next = NULL;
            }
            temp = head;
        }else{
            struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
            printf("Enter Value:");
            scanf("%d",&value);
            temp->next = newNode;
            newNode->data = value;
            newNode->next = NULL;
            temp = newNode;
        }
    }
    return head;
}

//print Linked List

void print(struct Node *node){
    while(node != NULL){
        printf("%d -> ",node->data);
        node = node->next;
    }
    printf("NULL\n");
}

//add data at First

struct Node* addFirst(struct Node *head,int data){
    struct Node *ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->next = head;
    ptr->data = data;
    return ptr;
}

//add data at Index

struct Node* addIndex(struct Node *head,int index,int data){
    struct Node *ptr = (struct Node*)malloc(sizeof(struct Node));
    struct Node *p = head;
    int i=0;
    while(i!=index-1){
        p = p->next;
        i++;
    }
    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;
    return head;
}

//add at Last

struct Node* addLast(struct Node *head,int data){
    struct Node *ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->data = data;
    struct Node *ptr2 = head;
    while(ptr2->next != NULL){
        ptr2 = ptr2->next;
    }
    ptr2->next = ptr;
    ptr->next = NULL;
    return head;
}

//add After a Node

struct Node* addAfter(struct Node* head,struct Node* prevNode,int data){
    struct Node *ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->next = prevNode->next;
    prevNode->next = ptr;
    return head;
}

//updation at a Node

struct Node* update(struct Node* head,int index,int value){
    struct Node* ptr = head;
    int i=0;
    while(ptr != NULL){
        if(i==index-1){
            struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
            newNode->data = value;
            newNode->next = ptr->next->next;
            ptr->next = newNode;
            break;
        }
        ptr = ptr->next;
        i++;
    }
    return head;
}

//delete at First

struct Node* deleteFirst(struct Node* head){
    struct Node *ptr;
    ptr = head->next;
    head->next = NULL;
    free(head);
    return ptr;
}

//delete at Last

struct Node* deleteLast(struct Node* head){
    struct Node* ptr = head;
    struct Node* ptr2 = head->next;
    while(ptr->next->next != NULL){
        ptr = ptr->next;
        ptr2 = ptr2->next;
    }
    ptr->next = NULL;
    free(ptr2);
    return head;
}

//delete at Index

struct Node* deleteIndex(struct Node* head,int index){
    struct Node *ptr = head;
    struct Node *ptr2 = head->next;
    int i = 0;
    while(i != index-1){
        ptr = ptr->next;
        ptr2 = ptr2->next;
        i++;
    }
    ptr->next = ptr2->next;
    free(ptr2);
    return head;
}

//delete After a Node

struct Node* deleteAfter(struct Node* head,struct Node* prevNode){
    struct Node *ptr = prevNode->next;
    prevNode->next = ptr->next;
    free(ptr);
    return head;
}

//search of Element

void search(struct Node* head,int search){
    struct Node* ptr = head;
    int index = 0,flag = 0;
    while(ptr != NULL){
        if(ptr->data == search){
            printf("Element is present at %d\n",index);
            flag = 1;
            break;
        }
        ptr = ptr->next;
        index++;
    }
    if(flag==0){
        printf("Element is Not Present\n");
    }   
}

//sort a Linked List

struct Node* sort(struct Node* head){
    struct Node *ptr = head,*ptr2;
    while(ptr->next != NULL){
        ptr2 = ptr->next;
        while(ptr2 != NULL){
            if(ptr->data > ptr2->data){
                int temp = ptr->data;
                ptr->data = ptr2->data;
                ptr2->data = temp;
            }
            ptr2 = ptr2->next;
        }
        ptr = ptr->next;
    }
    return head;
}

//insert at sorted Linked List

struct Node* insertSort(struct Node* head,int value){
    struct Node* ptr = head;
    struct Node* ptr2 = head->next;
    struct Node* newNode;
    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    while(ptr2 != NULL){
        if(newNode->data < ptr2->data){
            newNode->next = ptr2;
            ptr->next = newNode;
            break;
        }
        ptr = ptr2;
        ptr2 = ptr2->next;
    }
    return head;
}

//reverse a Linked List

struct Node* reverse(struct Node* head){
    struct Node* ptr1 = head;
    struct Node* end = NULL;
    struct Node* ptr2 = head->next;
    while(ptr1 != end){
        while(ptr2 != end){
            if(ptr2->next == end){
                int t = ptr1->data;
                ptr1->data = ptr2->data;
                ptr2->data = t;
                end = ptr2;
                continue;
            }
            ptr2 = ptr2->next;
        }
        ptr1 = ptr1->next;
        ptr2 = ptr1->next;
    }
    return head;
}

//merge into a Sorted Array

struct Node* merge(struct Node* head1,struct Node* head2){
    struct Node* ptr1 = head1;
    struct Node* ptr2 = head2;
    struct Node* newNode;
    newNode = (struct Node*)malloc(sizeof(struct Node));
    while(ptr1->next != NULL && ptr2->next != NULL){
        if(ptr1->data < ptr2->data){
            newNode->data = ptr1->data;
            ptr1 = ptr1->next;
            newNode = newNode->next;
            newNode = (struct Node*)malloc(sizeof(struct Node));
            continue;
        }
        if(ptr2->data < ptr1->data){
            newNode->data = ptr2->data;
            ptr2 = ptr2->next;
            newNode = newNode->next;
            newNode = (struct Node*)malloc(sizeof(struct Node));
            continue;
        }
        if(ptr1->data == ptr2->data){
            newNode->data = ptr1->data;
            ptr1 = ptr1->next;
            newNode = newNode->next;
            newNode = (struct Node*)malloc(sizeof(struct Node));
            newNode->data = ptr2->data;
            ptr2 = ptr2->next;
            newNode = newNode->next;
            newNode = (struct Node*)malloc(sizeof(struct Node));
            continue;
        }
    }
    while(ptr1->next != NULL){
        newNode->data = ptr1->data;
        ptr1 = ptr1->next;
        newNode = newNode->next;
        newNode = (struct Node*)malloc(sizeof(struct Node));
    }
    while(ptr2->next != NULL){
        newNode->data = ptr2->data;
        ptr2 = ptr2->next;
        newNode = newNode->next;
        newNode = (struct Node*)malloc(sizeof(struct Node));
    }
    newNode->next = NULL;
    return newNode;
}
int main(){

    //Declaration of Nodes manually

    struct Node *head;
    // struct Node *first;
    // struct Node *second;
    // struct Node *third;

    // //Memory allocation for each Node

    head = (struct Node*)malloc(sizeof(struct Node));
    // first = (struct Node*)malloc(sizeof(struct Node));
    // second = (struct Node*)malloc(sizeof(struct Node));
    // third = (struct Node*)malloc(sizeof(struct Node));

    // //Insert data at head and points to first

    // head->data = 2;
    // head->next = first;

    // //Insert data at first and points to fsecond

    // first->data = 6;
    // first->next = second;

    // //Insert data at second and points to fthird

    // second->data = 9;
    // second->next = third;

    // //Insert data at third and points to NULL

    // third->data = 1;
    // third->next = NULL;

    struct Node* tail;
    tail = (struct Node*)malloc(sizeof(struct Node));

    // print(head);
    // head = sort(head);
    // print(head);
    // head = insertSort(head,7);
    // print(head);
    // head = reverse(head);
    // print(head);
    // search(head,3);

    struct Node* result;
    result = (struct Node*)malloc(sizeof(struct Node));

    head = create(head,4);
    print(head);
    tail = create(tail,3);
    print(tail);
    result = merge(head,tail);
    print(result);
    return 0;
}