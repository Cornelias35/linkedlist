#include <stdio.h>
#include <stdlib.h>

// we are defining linkedlist node with data and pointer to point next node.
typedef struct LINKED_LIST_NODE_s *LINKED_LIST_NODE;
typedef struct LINKED_LIST_NODE_s{
    int data;
    void *next;
}LINKED_LIST_NODE_t[1];

// because our linkedlist must have head to reach linked nodes, we defining head node.
typedef struct LINKED_LIST_s *LINKED_LIST;
typedef struct LINKED_LIST_s {
    void *head;
}LINKED_LIST_t[1];

// initialize linked_list with malloc and assigning head to null
LINKED_LIST linked_list_init() {
    LINKED_LIST t1 = (LINKED_LIST)malloc(sizeof(LINKED_LIST_t));
    t1->head = NULL;
    return t1;
}

void insert(LINKED_LIST t1, int data) {
    // we are defining curr node and another node to assign data.
    LINKED_LIST_NODE curr;
    LINKED_LIST_NODE node = (LINKED_LIST_NODE)malloc(sizeof(LINKED_LIST_NODE_t));
    node->data = data;
    node->next = NULL;
    // checking whether is null or not
    if (node != NULL) {
        // assigning curr to head to reach end of linkedlist in while loop
        curr = t1->head;
        if (curr != NULL) {
            while (curr->next != NULL) {
                curr = curr->next;
            }
            // after reaching end of linkedlist, then insert function add the node.
            curr->next = node;
        }
        // if cur is null, then we need to assign the node as first node.
        else {
            t1->head = node;
        }
    }

}

// printing linkedlist
void print_list(LINKED_LIST_NODE t1) {
    LINKED_LIST_NODE n = t1;
    while (n != NULL) {
        printf("%d ", n->data);
        n = n->next;
    }
}

int main() {
    LINKED_LIST linkedList = linked_list_init();
    insert(linkedList, 15);
    insert(linkedList, 20);
    insert(linkedList, 25);
    insert(linkedList, 35);
    insert(linkedList, 45);
    insert(linkedList, 55);
    insert(linkedList, 65);
    insert(linkedList, 75);

    print_list(linkedList->head);
    return 0;
}
