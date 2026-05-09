/*=============================================================================
 * FILE        : rotate.c
 * DESCRIPTION : Left-rotate and right-rotate primitives for RB tree.
 *===========================================================================*/
#include "rbt.h"
/*---------------------------------------------------------------------------
 * leftRotate – rotates the subtree rooted at x to the left.
 *
 *       x                    y
 *      / \       -->        / \
 *     A   y               x   C
 *        / \             / \
 *       B   C           A   B
 *-------------------------------------------------------------------------*/
void leftRotate(Node *x)
{
    Node *y = x->right;       /* y is x's right child          */
    x->right = y->left;       /* turn y's left subtree into x's right subtree */
    if (y->left != NIL)
        y->left->parent = x;
    y->parent = x->parent;    /* link x's parent to y */
    if (x->parent == NIL)
        root = y;
    else if (x == x->parent->left)
        x->parent->left  = y;
    else
        x->parent->right = y;
    y->left   = x;            /* put x on y's left */
    x->parent = y;
}
/*---------------------------------------------------------------------------
 * rightRotate – rotates the subtree rooted at x to the right.
 *
 *       x                  y
 *      / \      -->       / \
 *     y   C             A   x
 *    / \                   / \
 *   A   B                 B   C
 *-------------------------------------------------------------------------*/
void rightRotate(Node *x)
{
    Node *y = x->left;        /* y is x's left child           */
    x->left = y->right;       /* turn y's right subtree into x's left subtree */
    if (y->right != NIL)
        y->right->parent = x;
    y->parent = x->parent;    /* link x's parent to y */
    if (x->parent == NIL)
        root = y;
    else if (x == x->parent->right)
        x->parent->right = y;
    else
        x->parent->left  = y;
    y->right  = x;            /* put x on y's right */
    x->parent = y;
}