/*=============================================================================
 * FILE        : deletemax.c
 * DESCRIPTION : Deletes the maximum node from the Red-Black Tree.
 *               Prints the tree before and after deletion.
 *===========================================================================*/
#include "rbt.h"
/*---------------------------------------------------------------------------
 * deleteMaxNode – finds the rightmost (maximum) node, prints the tree
 *                 before and after removing it via rbDelete().
 *-------------------------------------------------------------------------*/
void deleteMaxNode(void)
{
    Node *maxNode;
    if (root == NIL) {
        printf("Tree is empty. Nothing to delete.\n");
        return;
    }
    maxNode = rbMaximum(root);
    printf("Tree Before deleting the maximum node:\n");
    displayTree();
    rbDelete(maxNode);
    printf("Tree After deleting the maximum node:\n");
    displayTree();
}