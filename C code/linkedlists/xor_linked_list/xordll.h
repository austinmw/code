#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

/** @XORItem Generic Type **
 *
 *  Change as needed!
 *  N.B. Only store pointers since @XORList does not
 *  store local copies.
 */
typedef void XORItem;

typedef struct _xornode_ XORNode;
typedef struct _xorlist_ XORList;
typedef struct _xorlist_iterator_ {
	XORNode * prev;
	XORNode * curr;
	XORNode * next;
} XORListIterator;

/** XORLIST **
 *
 *  @brief: An @XORList, commonly referred to as a 'XOR Doubly Linked List'
 *          or 'Memory Efficient Doubly Linked List', stores interconnecting
 *          nodes that have a 'next' and 'previous' address reference
 *          stored together in a single memory address. The purpose of this
 *          is to reduce the memory requirement from 2n to n for each @XORNode.
 *
 *          @XORList also stores a @head and @tail reference so improve the
 *          insert/removal and traversal efficiency when wanting to traverse
 *          from either end of the @XORList. Therefere the total memory
 *          requirement is n + 2.
 */

XORList *       xorlist_create(void);
XORItem         xorlist_destroy(XORList * list);

XORItem *       xorlist_push_back(XORList * list, XORItem * e);
XORItem *       xorlist_pop_back(XORList * list);

bool            xorlist_is_empty(XORList * list);
int             xorlist_size(XORList * list);

/** XORLIST ITERATOR **
 *
 *  @brief: Iterators are bi-directional but initialised
 *          with directionality starting from the start
 *          or finish of the @XORList moving to the opposing end.
 *
 *          Iterators cannot extend beyond the last @XORItem at
 *          either end of the @XORList. This is done by blocking
 *          increments once the iterator has been pushed past
 *          the last @XORItem.
 *
 *          An @XORListIterator keeps a reference to @next, @curr, and
 *          @prev since 3 points of contact are necessary to change
 *          direction in an inconsecutive traversal.
 */

/** Forward Iterator **
 *
 *  @brief: Initialises a concrete @XORListIterator that moves from
 *          @head to @tail of the @XORList.
 */
XORListIterator xorlist_iterator_forward(XORList * list);
/** Reverse Iterator **
 *
 *  @brief: Initialises a concrete @XORListIterator that moves from
 *          @tail to @head of the @XORList.
 */
XORListIterator xorlist_iterator_reverse(XORList * list);

/** Iterator Tests **
 *
 *  @brief: Tests if the @XORListIterator has an @XORItem before or after
 *          its current position without moving the @XORListIterator.
 *
 *          'Next' is defined by a @XORItem that proceeds the current position
 *          based on the direction of the @XORListIterator when initialised.
 *          Likewise, 'Prev' is the @XORItem that preceeded the current position.
 */
bool            xorlist_iterator_at_begin(XORListIterator * itr);
bool            xorlist_iterator_at_end(XORListIterator * itr);
bool            xorlist_iterator_has_next(XORListIterator * itr);
bool            xorlist_iterator_has_prev(XORListIterator * itr);
bool            xorlist_iterator_has_curr(XORListIterator * itr);

/** Iterator Accessors **
 *
 *  @brief: Moves the position of the @XORListIterator forward or reverse
 *          based on the directionality at initialisation.
 *
 *          Foward Iterator:
 *              'Next' moves as @head --> @tail
 *              'Prev' moves as @head <-- @tail
 *
 *          Reverse Iterator:
 *              'Next' moves as @tail --> @head
 *              'Prev' moves as @tail <-- @head
 *
 *          The 'curr' (current) position can be accessed at any time so that
 *          the @return from the 'next' and 'prev' methods are optional.
 */
XORItem *       xorlist_iterator_next(XORListIterator * itr);
XORItem *       xorlist_iterator_prev(XORListIterator * itr);
XORItem *       xorlist_iterator_curr(XORListIterator * itr);