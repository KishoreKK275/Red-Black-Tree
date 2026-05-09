/*=============================================================================
 * FILE        : findmax.c
 * DESCRIPTION : Finds the node with the maximum key in a subtree.
 *===========================================================================*/
#include "rbt.h"
/*---------------------------------------------------------------------------
 * rbMaximum – walks right until the rightmost (maximum) node is reached.
 *              Returns NIL if the subtree is empty.
 *-------------------------------------------------------------------------*/
Node *rbMaximum(Node *node)
{
    if (node == NIL)
        return NIL;
    while (node->right != NIL)
        node = node->right;
    return node;
}