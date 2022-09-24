//
// Created by Cuong Nguyen on 24/9/22.
//

#ifndef RE_LINKED_LIST_H
#define RE_LINKED_LIST_H

#include <stddef.h>

#include "linked_node.h"

struct linked_list {
    struct linked_node *leading;
    struct linked_node *trailing;
    size_t node_count;
};

typedef _Bool (* linked_node_comparator)(const void *, const void *);

struct linked_list *linked_list_init(void);

void linked_list_deinit(struct linked_list **list_ptr);

struct linked_node *linked_list_prepend(struct linked_list *list, void *item);
struct linked_node *linked_list_append(struct linked_list *list, void *item);
struct linked_node *linked_list_insert_after(struct linked_list *list, void *item, struct linked_node *node);
struct linked_node *linked_list_insert_before(struct linked_list *list, void *item, struct linked_node *node);

struct linked_node *linked_list_pop_first(struct linked_list *list);
struct linked_node *linked_list_pop_last(struct linked_list *list);
struct linked_node *linked_list_remove_node(struct linked_list *list, struct linked_node *node);
struct linked_node *linked_list_remove_if(struct linked_list *list, linked_node_comparator cmp);

void linked_list_clear(struct linked_list *list);

struct linked_list *linked_list_clone(struct linked_list *other_list);

_Bool linked_list_contains(struct linked_list *list, void *item, linked_node_comparator cmp);
size_t linked_list_index_of(struct linked_list *list, void *item, linked_node_comparator cmp);

size_t linked_list_size(struct  linked_list *list);

#endif //RE_LINKED_LIST_H
