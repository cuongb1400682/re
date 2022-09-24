#include <stdio.h>

#include "tests/collections/linked_list.h"
#include "tests/collections/linked_node.h"

void test_linked_list(void);
void test_linked_node(void);

int main() {
    test_linked_list();
    test_linked_node();
    puts("All test cases passed!");
    return 0;
}

void test_linked_list(void) {
    test_linked_list_init();
    test_linked_list_deinit();

    test_linked_list_prepend();
    test_linked_list_prepend_5_items();
}

void test_linked_node(void) {
    test_linked_node_init();
    test_linked_node_init_with_item();

    test_linked_node_connect();
    test_linked_node_connect_left_null();
    test_linked_node_connect_right_null();
    test_linked_node_connect_three_nodes();

    test_linked_node_disconnect();

    test_linked_node_deinit();
    test_linked_node_deinit_null_param();
    test_linked_node_deinit_null_node();
    test_linked_node_deinit_null_item();
}
