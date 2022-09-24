//
// Created by Cuong Nguyen on 24/9/22.
//

#include <stdlib.h>
#include <string.h>

#include "check/check.h"
#include "tests/collections/linked_list.h"
#include "collections/linked_list.h"

void check_node_in_seq(
        struct linked_node **nodes,
        struct linked_list *list,
        const int node_count
) {
    int i;
    struct linked_node *curr;

    curr = list->leading;
    for (i = 0; i < node_count; i++) {
        check_eq(curr, nodes[i]);
        curr = curr->next;
    }
}

void check_node_item_in_seq(
        void **items,
        struct linked_list *list,
        const int node_count,
        const int item_size
) {
    int i;
    struct linked_node *curr;

    curr = list->leading;
    for (i = 0; i < node_count; i++) {
        curr = curr->next;
        const int diff = memcmp(items[node_count - i - 1], curr->item, item_size);
        check_eq(diff, 0);
    }
}

void test_linked_list_init() {
    // given
    struct linked_list *list;

    // when
    list = linked_list_init();

    // then
    check_not_null(list);

    check_not_null(list->leading);
    check_not_null(list->trailing);

    check_eq(list->leading->next, list->trailing);
    check_eq(list->leading, list->trailing->prev);

    check_null(list->leading->prev);
    check_null(list->trailing->next);

    check_eq(list->node_count, 0);

    linked_list_deinit(&list);
}

void test_linked_list_deinit() {
    // given
    struct linked_list *list;

    // when
    list = linked_list_init();
    linked_list_deinit(&list);

    check_null(list);
}

void test_linked_list_prepend(void) {
    // given
    struct linked_list *list;
    struct linked_node *new_node;
    int *item;

    list = linked_list_init();
    item = malloc(sizeof(int));
    *item = 40;

    // when
    new_node = linked_list_prepend(list, item);
    struct linked_node *nodes[] = {
            list->leading,
            new_node,
            list->trailing
    };

    // then
    check_node_in_seq(nodes, list, 3);

    check_eq(list->node_count, 1);

    check_not_null(list->leading->next);
    check_eq(list->leading->next->item, item);
    check_eq(*(int *)list->leading->next->item, 40);
    check_null(list->leading->prev);

    check_not_null(list->trailing->prev);
    check_eq(list->trailing->prev->item, item);
    check_eq(*(int *)list->trailing->prev->item, 40);
    check_null(list->trailing->next);

    linked_list_deinit(&list);
}

void test_linked_list_prepend_5_items(void) {
    // given
    struct linked_list *list;
    const int ITEM_COUNT = 5;
    void *items[ITEM_COUNT];
    int i;

    for (i = 0; i < ITEM_COUNT; i++) {
        items[i] = malloc(sizeof(int));
        *(int *)items[i] = i + 1;
    }

    list = linked_list_init();

    // when
    for (i = 0; i < ITEM_COUNT; i++) {
        linked_list_prepend(list, items[i]);
    }

    // then
    check_node_item_in_seq(items, list, ITEM_COUNT, sizeof(int));

    linked_list_deinit(&list);
}
