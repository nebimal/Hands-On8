#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_NODES 10

typedef struct {
    int data[MAX_NODES];  
    int next[MAX_NODES];  
    int head;            
    int free;             
} LinkedList;

void initList(LinkedList *list) {
    list->head = -1;
    list->free = 0;
    for (int i = 0; i < MAX_NODES - 1; i++) {
        list->next[i] = i + 1;
    }
    list->next[MAX_NODES - 1] = -1;
}

bool List_Full(LinkedList *list) {
    return list->free == -1;
}

bool List_Insert(LinkedList *list, int value) {
    if (List_Full(list)) {
        return false;  
    }
    int newIndex = list->free;
    list->free = list->next[newIndex]; 
    
    list->data[newIndex] = value;
    list->next[newIndex] = list->head;
    list->head = newIndex;
    return true;
}

bool List_Delete(LinkedList *list, int value) {
    int current = list->head;
    int prev = -1;
    while (current != -1) {
        if (list->data[current] == value) {
            if (prev == -1) {  
                list->head = list->next[current];
            } else {
                list->next[prev] = list->next[current];
            }
            list->next[current] = list->free;
            list->free = current;
            return true;
        }
        prev = current;
        current = list->next[current];
    }
    return false;  // Value not found.
}

int List_Search(LinkedList *list, int value) {
    int current = list->head;
    while (current != -1) {
        if (list->data[current] == value) {
            return current;
        }
        current = list->next[current];
    }
    return -1;
}

void Print_List(LinkedList *list) {
    int current = list->head;
    while (current != -1) {
        printf("%d -> ", list->data[current]);
        current = list->next[current];
    }
    printf("NULL\n");
}

int main(void) {
    LinkedList list;
    initList(&list);
    
    printf("Inserting elements 15, 30, 45, 60 at the head of the list:\n");
    if (List_Insert(&list, 15))
        printf("Inserted 15.\n");
    if (List_Insert(&list, 30))
        printf("Inserted 30.\n");
    if (List_Insert(&list, 45))
        printf("Inserted 45.\n");
    if (List_Insert(&list, 60))
        printf("Inserted 60.\n");
    
    printf("\nLinked List after insertion:\n");
    Print_List(&list);
    
    int searchVal = 45;
    int index = List_Search(&list, searchVal);
    if (index != -1)
        printf("\nValue %d found at index %d in the list.\n", searchVal, index);
    else
        printf("\nValue %d not found in the list.\n", searchVal);
    
    printf("\nDeleting value %d from the list.\n", searchVal);
    if (List_Delete(&list, searchVal))
        printf("Value %d deleted successfully.\n", searchVal);
    else
        printf("Value %d not found; deletion failed.\n", searchVal);
    
    printf("\nLinked List after deletion:\n");
    Print_List(&list);
    
    return 0;
}
