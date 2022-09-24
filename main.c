#include "tests/linked_list.h"
#include "tests/linked_node.h"

int main() {
    test_linked_node_init();
    test_linked_node_init_with_item();
    test_linked_node_deinit();
    test_linked_node_connect();
    return 0;
}
