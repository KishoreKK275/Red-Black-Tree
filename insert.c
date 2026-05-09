/*=============================================================================
 * FILE        : insert.c
 * DESCRIPTION : RB-tree insertion and insertion fixup.
 *               Prints the tree BEFORE balancing and AFTER balancing,
 *               matching the required output format.
 *===========================================================================*/
#include "rbt.h"
/*---------------------------------------------------------------------------
 * rbInsertFixup – restores RB properties after a standard BST insert.
 *   Handles three cases (and their mirrors) as per CLRS:
 *     Case 1 – Uncle is RED        → recolour
 *     Case 2 – Uncle is BLACK, z is an inner grandchild → rotate
 *     Case 3 – Uncle is BLACK, z is an outer grandchild → rotate + recolour
 *-------------------------------------------------------------------------*/
void rbInsertFixup(Node *z)
{
    Node *y;    /* uncle */
    while (z->parent->color == RED) {
        if (z->parent == z->parent->parent->left) {
            /* --- Parent is a LEFT child ---------------------------------- */
            y = z->parent->parent->right;    /* uncle */
            if (y->color == RED) {
                /* Case 1: uncle is RED – recolour and move z up */
                z->parent->color         = BLACK;
                y->color                 = BLACK;
                z->parent->parent->color = RED;
                z = z->parent->parent;
            } else {
                if (z == z->parent->right) {
                    /* Case 2: z is a right child – left-rotate to reach case 3 */
                    z = z->parent;
                    leftRotate(z);
                }
                /* Case 3: z is a left child – recolour + right-rotate */
                z->parent->color         = BLACK;
                z->parent->parent->color = RED;
                rightRotate(z->parent->parent);
            }
        } else {
            /* --- Parent is a RIGHT child (mirror) ------------------------ */
            y = z->parent->parent->left;     /* uncle */
            if (y->color == RED) {
                /* Case 1 (mirror) */
                z->parent->color         = BLACK;
                y->color                 = BLACK;
                z->parent->parent->color = RED;
                z = z->parent->parent;
            } else {
                if (z == z->parent->left) {
                    /* Case 2 (mirror) */
                    z = z->parent;
                    rightRotate(z);
                }
                /* Case 3 (mirror) */
                z->parent->color         = BLACK;
                z->parent->parent->color = RED;
                leftRotate(z->parent->parent);
            }
        }
    }
    root->color = BLACK;   /* Rule 2: root must be BLACK */
}
/*---------------------------------------------------------------------------
 * rbInsert – inserts data into the tree using standard BST logic,
 *             then calls rbInsertFixup.
 *             Prints the state before and after balancing.
 *-------------------------------------------------------------------------*/
void rbInsert(int data)
{
    Node *z = newNode(data);
    Node *y = NIL;
    Node *x = root;
    /* --- BST walk to find insertion position --------------------------- */
    while (x != NIL) {
        y = x;
        if (z->data < x->data)
            x = x->left;
        else if (z->data > x->data)
            x = x->right;
        else if (z->data == x->data) {
            printf(RED_TEXT "Duplicate not allowed\n" RESET);
            return;
        }
    }
    z->parent = y;
    if (y == NIL)
        root = z;                  /* tree was empty */
    else if (z->data < y->data)
        y->left  = z;
    else
        y->right = z;
    z->left  = NIL;
    z->right = NIL;
    z->color = RED;
    /* --- Print tree BEFORE fixup (only when tree had nodes before) ----- */
    if (y != NIL) {
        printf(BLUE "\nBefore Balancing Red Black Tree is:\n" RESET);
        displayTree();
    }
    /* --- Restore RB properties ----------------------------------------- */
    rbInsertFixup(z);
    /* --- Print tree AFTER fixup (only when tree had nodes before) ------ */
    if (y != NIL) {
        printf(MAGENTA "Now Tree is balance\n" RESET);
        displayTree();
    }
}