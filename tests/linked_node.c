//
// Created by Cuong Nguyen on 24/9/22.
//

#include <assert.h>
#include <stdlib.h>

#include "collections/linked_node.h"

void test_linked_node_init(void) {
    struct linked_node *node = linked_node_init();
    assert(node != NULL);
    assert(node->next == NULL);
    assert(node->prev == NULL);
    assert(node->item == NULL);
}

void test_linked_node_deinit(void) {
    struct linked_node *node = linked_node_init();
    linked_node_deinit(&node);
    assert(node == NULL);
}

void test_linked_node_init_with_item(void) {
    int *item;
    struct linked_node *node;

    item = malloc(sizeof(int));
    *item = 123456;
    node = linked_node_init_with_item(item);

    assert(node->item == item);
    assert(*(int*)node->item == 123456);

    linked_node_deinit(&node);
}

void test_linked_node_connect(void) {
    struct linked_node *left_node;
    struct linked_node *right_node;

    int *left_item;
    int *right_item;

    left_item = malloc(sizeof(int));
    right_item = malloc(sizeof(int));
    *left_item = 1;
    *right_item = 2;

    left_node = linked_node_init_with_item(left_item);
    right_node = linked_node_init_with_item(right_item);

    linked_node_connect(left_node, right_node);
    assert(left_node->next == right_node);
    assert(left_node == right_node->prev);

    linked_node_deinit(&left_node);
    linked_node_deinit(&right_node);
}
