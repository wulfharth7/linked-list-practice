#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "node.h"

void modify_nodes(struct node *list,struct node **head);
void create_nodes(struct node **head);

int main(){
    struct node *head = NULL;
        create_nodes(&head);
        puts("You're modifying the First one");
        modify_nodes(head,&head);

    struct node *head2 = NULL;
        create_nodes(&head2);
        puts("You're modifying the Second one");
        modify_nodes(head2,&head2);

    concatenate_lists(&head2,&head);
    print_list(head);
}

void modify_nodes(struct node *list,struct node **head){
    enum choose_menu menu;
    int input_value;

    printf("To Add a Node to the Head, Press 1\n"
           "To Add a Node to the Middle, Press 2\n"
           "To Add a Node to the End, Press 3\n"
           "To Finish the process, Press 0\n\n"
           );
    scanf("%d",&input_value);
    while(input_value != END_OPERATION){
        scanf("%d",&input_value);
        if(input_value == ADD_HEAD){
            add_node_head(&list);
        }else if(input_value == ADD_MIDDLE){
            puts("Please enter at which place you want your node to be...");
            scanf("%d",&input_value);
            add_node_middle(&list,input_value);
        }else if(input_value == ADD_LAST){
            add_node_last(&list);
        }
    }
    *head = list;
}

void create_nodes(struct node **head){
    (*head) = (struct node*)malloc(sizeof(struct node));
        (*head)->value = 'x';
        (*head)->nextPtr = NULL;
}
