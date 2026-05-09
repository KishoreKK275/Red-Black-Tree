/*=============================================================================
 * FILE        : findmin.c
 * DESCRIPTION : Finds the node with the minimum key in a subtree.
 *===========================================================================*/
#include "rbt.h"
/*---------------------------------------------------------------------------
 * rbMinimum – walks left until the leftmost (minimum) node is reached.
 *              Returns NIL if the subtree is empty.
 *-------------------------------------------------------------------------*/
Node *rbMinimum(Node *node)
{
    if (node == NIL)
        return NIL;
    while (node->left != NIL)
        node = node->left;
    return node;
}