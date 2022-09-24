//
// Created by Cuong Nguyen on 24/9/22.
//

#include <stdlib.h>

#include "linked_node.h"

struct linked_node *linked_node_init() {
    struct linked_node *node = calloc(1, sizeof(struct linked_node));
    return node;
}

void linked_node_deinit(struct linked_node **node) {
    free((*node)->item);
    free(*node);
    *node = NULL;
}

struct linked_node *linked_node_init_with_item(void *item) {
    struct linked_node *node = linked_node_init();
    node->item = item;
    return node;
}

void linked_node_connect(struct linked_node *lhs, struct linked_node *rhs) {
    lhs->next = rhs;
    rhs->prev = lhs;
}
