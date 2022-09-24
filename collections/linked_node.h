//
// Created by Cuong Nguyen on 24/9/22.
//

#ifndef RE_LINKED_NODE_H
#define RE_LINKED_NODE_H

struct linked_node {
    struct linked_node *next;
    struct linked_node *prev;
    void *item;
};

struct linked_node *linked_node_init();
struct linked_node *linked_node_init_with_item(void *);
void linked_node_deinit(struct linked_node **);

void linked_node_connect(struct linked_node *lhs, struct linked_node *rhs);

#endif //RE_LINKED_NODE_H
