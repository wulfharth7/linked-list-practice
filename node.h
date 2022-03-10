#ifndef NODE_H_INCLUDED
#define NODE_H_INCLUDED
enum choose_menu{ADD_HEAD = 1, ADD_MIDDLE = 2, ADD_LAST = 3, END_OPERATION = 0};
struct node{
    char value;
    struct node *nextPtr;
};

void print_list(struct node *firstNode){
    while(firstNode != NULL){
        printf("%c--->",firstNode->value);
        firstNode = firstNode->nextPtr;
    }
    printf("NULL");
}

void add_node_head(struct node **head){
    struct node *add = NULL;
    add = (struct node*)malloc(sizeof(struct node));
    add->value = 'a';
    add->nextPtr = *head;

    *head = add;
    //free(add);
}

void add_node_last(struct node **head){
    struct node *new_ = NULL;
    new_ = (struct node*)malloc(sizeof(struct node));
    new_->nextPtr=NULL;
    new_->value = 'b';

    struct node *temp;
    temp = (struct node*)malloc(sizeof(struct node));
    temp = *head;
    while(temp->nextPtr != NULL){
        temp = temp->nextPtr;
    }
    temp->nextPtr = new_;
   /* free(temp);
    free(new_);*/
}

void add_node_middle(struct node **head,int position){
    struct node *newNode;
    newNode = (struct node*)malloc(sizeof(struct node));
    newNode->value = 'c';

    struct node *temp = *head;
    for(int i=2; i<position; i++){
        if(temp->nextPtr != NULL){
        temp = temp->nextPtr;
        }
    }
    newNode->nextPtr = temp->nextPtr;
    temp->nextPtr = newNode;
    //free(newNode);
}

void concatenate_lists(struct node **adding,struct node **beginning){
    struct node *temp = NULL;
        temp = (struct node*)malloc(sizeof(struct node));
    struct node *head = NULL;
        head = (struct node*)malloc(sizeof(struct node));
        temp = *beginning;
        head = temp;
    while(temp->nextPtr != NULL){
        temp = temp->nextPtr;
    }
    temp->nextPtr = *adding;
    *beginning = head;
    /*free(temp);
    free(head);*/
}


#endif // NODE_H_INCLUDED
