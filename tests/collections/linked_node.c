//
// Created by Cuong Nguyen on 24/9/22.
//

#include <assert.h>
#include <stdlib.h>

#include "collections/linked_node.h"

void test_linked_node_init(void) {
    // given
    struct linked_node *node = linked_node_init();

    // when

    // then
    assert(node != NULL);
    assert(node->next == NULL);
    assert(node->prev == NULL);
    assert(node->item == NULL);
}

void test_linked_node_deinit(void) {
    // given
    struct linked_node *node = linked_node_init();

    // when
    linked_node_deinit(&node);

    // then
    assert(node == NULL);
}

void test_linked_node_deinit_null_param(void) {
    linked_node_deinit(NULL);
}

void test_linked_node_deinit_null_node(void) {
    // given
    struct linked_node *null_node = NULL;

    // when

    // then
    linked_node_deinit(&null_node);
}

void test_linked_node_deinit_null_item(void) {
    // given
    struct linked_node *node = linked_node_init();

    // when
    node->item = NULL;

    // then
    linked_node_deinit(&node);
}

void test_linked_node_init_with_item(void) {
    int *item;
    struct linked_node *node;

    // given
    item = malloc(sizeof(int));
    *item = 123456;
    node = linked_node_init_with_item(item);

    // when

    // then
    assert(node->item == item);
    assert(*(int*)node->item == 123456);

    linked_node_deinit(&node);
}

void test_linked_node_connect(void) {
    struct linked_node *left_node;
    struct linked_node *right_node;

    int *left_item;
    int *right_item;

    // given
    left_item = malloc(sizeof(int));
    right_item = malloc(sizeof(int));
    *left_item = 1;
    *right_item = 2;

    left_node = linked_node_init_with_item(left_item);
    right_node = linked_node_init_with_item(right_item);

    // when
    linked_node_connect(left_node, right_node);

    // then
    assert(left_node->next == right_node);
    assert(left_node == right_node->prev);
    assert(*(int *)right_node->prev->item == 1);
    assert(*(int *)left_node->next->item == 2);

    linked_node_deinit(&left_node);
    linked_node_deinit(&right_node);
}

void test_linked_node_connect_three_nodes(void) {
    struct linked_node *node_one;
    struct linked_node *node_two;
    struct linked_node *node_three;

    int *item_one;
    int *item_two;
    int *item_three;

    // given
    item_one = malloc(sizeof(int *));
    item_two = malloc(sizeof(int *));
    item_three = malloc(sizeof(int *));

    *(int *)item_one = 1;
    *(int *)item_two = 2;
    *(int *)item_three = 3;

    node_one = linked_node_init_with_item(item_one);
    node_two = linked_node_init_with_item(item_two);
    node_three = linked_node_init_with_item(item_three);

    // when
    linked_node_connect(node_one, node_two);
    linked_node_connect(node_two, node_three);

    // then
    assert(node_one->prev == NULL);
    assert(*(int *)node_one->item == 1);
    assert(node_one->next == node_two);

    assert(node_two->prev == node_one);
    assert(*(int *)node_two->item == 2);
    assert(node_two->next == node_three);

    assert(node_three->prev == node_two);
    assert(*(int *)node_three->item == 3);
    assert(node_three->next == NULL);

    linked_node_deinit(&node_one);
    linked_node_deinit(&node_two);
    linked_node_deinit(&node_three);
}

void test_linked_node_connect_left_null(void) {
    struct linked_node *left_node;
    struct linked_node *right_node;

    int *right_item;

    // given
    right_item = malloc(sizeof(int));
    *right_item = 2;

    left_node = NULL;
    right_node = linked_node_init_with_item(right_item);

    // when
    linked_node_connect(left_node, right_node);

    // then
    assert(NULL == right_node->prev);

    linked_node_deinit(&left_node);
    linked_node_deinit(&right_node);
}

void test_linked_node_connect_right_null(void) {
    struct linked_node *left_node;
    struct linked_node *right_node;

    int *left_item;

    // given
    left_item = malloc(sizeof(int));
    *left_item = 1;

    left_node = linked_node_init_with_item(left_item);
    right_node = NULL;

    // when
    linked_node_connect(left_node, right_node);

    // then
    assert(left_node->next == NULL);
    assert(*(int *)left_node->item == 1);

    linked_node_deinit(&left_node);
    linked_node_deinit(&right_node);
}

void test_linked_node_disconnect(void) {
    struct linked_node *node_one;
    struct linked_node *node_two;
    struct linked_node *node_three;

    int *item_one;
    int *item_two;
    int *item_three;

    // given
    item_one = malloc(sizeof(int *));
    item_two = malloc(sizeof(int *));
    item_three = malloc(sizeof(int *));

    *(int *)item_one = 1;
    *(int *)item_two = 2;
    *(int *)item_three = 3;

    node_one = linked_node_init_with_item(item_one);
    node_two = linked_node_init_with_item(item_two);
    node_three = linked_node_init_with_item(item_three);

    linked_node_connect(node_one, node_two);
    linked_node_connect(node_two, node_three);

    // when
    linked_node_disconnect(node_two);

    // then
    assert(node_one->prev == NULL);
    assert(*(int *)node_one->item == 1);
    assert(node_one->next == node_three);

    assert(node_two->prev == NULL);
    assert(*(int *)node_two->item == 2);
    assert(node_two->next == NULL);

    assert(node_three->prev == node_one);
    assert(*(int *)node_three->item == 3);
    assert(node_three->next == NULL);

    linked_node_deinit(&node_one);
    linked_node_deinit(&node_two);
    linked_node_deinit(&node_three);
}
