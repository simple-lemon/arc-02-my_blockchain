#include "my_blockchain.h"

int main(int argc, char **argv) {
    
    int sync = 0;
    int numberOfNodes = 0;
    t_list *blocks = NULL;
    t_node *nodes = NULL;

    if (argc > 1)
        readBackup(argv[1], &sync, &numberOfNodes, &blocks, &nodes);
    readInput(&sync, &numberOfNodes, &blocks, &nodes);
    if (argc > 1)
        updateBackup(nodes, sync, numberOfNodes, argv[1]);
    else 
        updateBackup(nodes, sync, numberOfNodes, "blockchain_backup.txt");
    my_lstdel(&blocks, my_del);
    removeAllNodes(&nodes);
    return 0;
}
