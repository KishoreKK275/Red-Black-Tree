/*=============================================================================
 * FILE        : deletemin.c
 * DESCRIPTION : Deletes the minimum node from the Red-Black Tree.
 *               Prints the tree before and after deletion.
 *===========================================================================*/
#include "rbt.h"
/*---------------------------------------------------------------------------
 * deleteMinNode – finds the leftmost (minimum) node, prints the tree
 *                 before and after removing it via rbDelete().
 *-------------------------------------------------------------------------*/
void deleteMinNode(void)
{
    Node *minNode;
    if (root == NIL) {
        printf("Tree is empty. Nothing to delete.\n");
        return;
    }
    minNode = rbMinimum(root);
    printf("Tree Before deleting the minimum node:\n");
    displayTree();
    rbDelete(minNode);
    printf("Tree After deleting the minimum node:\n");
    displayTree();
}