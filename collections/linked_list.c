//
// Created by Cuong Nguyen on 24/9/22.
//

#include <stdlib.h>

#include "collections/linked_list.h"
#include "collections/linked_node.h"

struct linked_list *linked_list_init(void) {
    struct linked_list *list;
    struct linked_node *leading;
    struct linked_node *trailing;

    list = calloc(1, sizeof(struct linked_list));
    leading = linked_node_init();
    trailing = linked_node_init();

    linked_node_connect(leading, trailing);

    list->leading = leading;
    list->trailing = trailing;
    list->node_count = 0;

    return list;
}

void linked_list_deinit(struct linked_list **list_ptr) {
    struct linked_node *curr;
    struct linked_node *next;

    if (list_ptr == NULL || *list_ptr == NULL) {
        return;
    }

    curr = (*list_ptr)->leading;
    while (curr != NULL) {
        next = curr->next;
        linked_node_deinit(&curr);
        curr = next;
    }

    free(*list_ptr);
    *list_ptr = NULL;
}

struct linked_node *linked_list_prepend(struct linked_list *list, void *item) {
    struct linked_node *new_node;
    struct linked_node *after_leading;
    struct linked_node *leading;

    leading = list->leading;
    after_leading = leading->next;
    new_node = linked_node_init_with_item(item);

    linked_node_connect(leading, new_node);
    linked_node_connect(new_node, after_leading);
    list->node_count++;

    return new_node;
}








