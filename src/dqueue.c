/*
   under:   trilobite stdlib
   author:  Michael Gene Ridge Brockus
   gmail:   <michaelbrockus@gmail.com>
   website: <https://trilobite.code.blog>
*/
#include "trilobite/dqueue.h"
#include <stdlib.h>

enum
{
    failed,
    success
}; // end of local enums

//
// This is the official definition for the Chicken Libraries
// 'DeQueueNode' type.
//
// Members:
// > [_data] is the private data member that represents the
//           data in the structure
// > [_next_ptr] is the pointer to the next node
// > [_prev_ptr] is the pointer to the prev node
//
typedef struct DeQueueNode
{
    char *_data;
    struct DeQueueNode *_prev_ptr;
    struct DeQueueNode *_next_ptr;
} DeQueueNode; // end of struct

//
// This is the official definition for the Chicken Libraries
// 'DeQueueOf' type.
//
// Members:
// > _begin_ptr is the pointer to queue begin
// > _end_ptr is the pointer to queue end
//
struct DeQueueOf
{
    size_t _size;
    struct DeQueueNode *_end_ptr;
    struct DeQueueNode *_begin_ptr;
}; // end of struct


/*
  overview:
  > Allocate memory for a new container dqueue structure
  > if structure is of a nullptr value we return a value
  > of nullptr else we return a ready structure with
  > data members set to default values.
  >
  args:
  -> ...: N/A
*/
DeQueueOf *tril_container_dqueue_create(void)
{
    DeQueueOf *new_structure = malloc(sizeof(*new_structure));
    if (!new_structure)
    {
        return NULL;
    } // end if
    new_structure->_begin_ptr = NULL;
    new_structure->_end_ptr = NULL;
    new_structure->_size = 0;
    return new_structure;
} // end of func

/*
  overview:
  > takes a container structure and erases it from memory
  > back to the operating system for use in other programs.
  >
  args:
  -> structure_ref: Refrence object of type dqueue of
*/
void tril_container_dqueue_erase(DeQueueOf **structure_ref)
{
    if (!structure_ref || !*structure_ref)
    {
        return;
    } // end if

    while (tril_container_dqueue_not_empty(*structure_ref))
    {
        tril_container_dqueue_pop_end(*structure_ref);
    } // end while

    free(*structure_ref);
    *structure_ref = NULL;
} // end of func

/*
  overview:
  > Tacks a string as input and should push the string onto
  > the dqueue structure.
  >
  > If structure is a nullptr value we get nothing else try
  > to allocate a new note and if that can't be allocated
  > nothing happens else we get a new node for are dqueue.
  >
  args:
  -> structure_ptr: Pointer object of type dqueue of
  -> data: Input value of type string
*/
void tril_container_dqueue_push(DeQueueOf *structure_ptr, const char *data)
{
    return tril_container_dqueue_push_start(structure_ptr, data);
} // end of func

/*
  overview:
  > Tacks a string as input and should push the string onto
  > the dqueue structure from start.
  >
  > If structure is a nullptr value we get nothing else try
  > to allocate a new note and if that can't be allocated
  > nothing happens else we get a new node for are dqueue.
  >
  args:
  -> structure_ptr: Pointer object of type dqueue of
  -> data: Input value of type string
*/
void tril_container_dqueue_push_start(DeQueueOf *structure_ptr, const char *data)
{
    if (!structure_ptr)
    {
        return;
    } // end if
    DeQueueNode *temp = malloc(sizeof(*temp));
    if (!temp)
    {
        return;
    } // end if

    temp->_next_ptr = structure_ptr->_begin_ptr;
    temp->_prev_ptr = NULL;
    temp->_data = (char *)data;

    if (tril_container_dqueue_its_empty(structure_ptr))
    {
        structure_ptr->_end_ptr = temp;
    } // end if
    else
    {
        structure_ptr->_begin_ptr->_prev_ptr = temp;
    } // end else
    
    structure_ptr->_begin_ptr = temp;
    ++structure_ptr->_size;
} // end of func

/*
  overview:
  > Tacks a string as input and should push the string onto
  > the dqueue structure from end.
  >
  > If structure is a nullptr value we get nothing else try
  > to allocate a new note and if that can't be allocated
  > nothing happens else we get a new node for are dqueue.
  >
  args:
  -> structure_ptr: Pointer object of type dqueue of
  -> data: Input value of type string
*/
void tril_container_dqueue_push_end(DeQueueOf *structure_ptr, const char *data)
{
    if (!structure_ptr)
    {
        return;
    } // end if
    DeQueueNode *temp = malloc(sizeof(*temp));
    if (!temp)
    {
        return;
    } // end if

    temp->_next_ptr = NULL;
    temp->_prev_ptr = structure_ptr->_end_ptr;
    temp->_data = (char *)data;

    if (tril_container_dqueue_its_empty(structure_ptr))
    {
        structure_ptr->_begin_ptr = temp;
    } // end if
    else
    {
        structure_ptr->_end_ptr->_next_ptr = temp;
    } // end else
    
    structure_ptr->_end_ptr = temp;
    ++structure_ptr->_size;
}

/*
  overview:
  > Should return the value stored in the removed node from
  > structure if the structure is both not nullptr and or
  > empty. If so where gonna return nullptr.
  >
  args:
  -> structure_ptr: Pointer object of type dqueue of
*/
char *tril_container_dqueue_pop(DeQueueOf *structure_ptr)
{
    return tril_container_dqueue_pop_start(structure_ptr);
} // end of func

/*
  overview:
  > Should return the value stored in the removed node from
  > the start if the structure is both not nullptr and or
  > empty. If so where gonna return nullptr.
  >
  args:
  -> structure_ptr: Pointer object of type dqueue of
*/
char *tril_container_dqueue_pop_start(DeQueueOf *structure_ptr)
{
    if (!structure_ptr)
    {
        return NULL;
    } // end if

    DeQueueNode *temp = structure_ptr->_begin_ptr;
    char *value;
    structure_ptr->_begin_ptr = temp->_next_ptr;

    if (!structure_ptr->_begin_ptr)
    {
        structure_ptr->_end_ptr = NULL;
    } // end if
    else
    {
        structure_ptr->_begin_ptr->_prev_ptr = NULL;
    } // end else
    --structure_ptr->_size;
    value = temp->_data;
    free(temp);
    return value;
} // end of func

/*
  overview:
  > Should return the value stored in the removed node from
  > the end if the structure is both not nullptr and or
  > empty. If so where gonna return nullptr .
  >
  args:
  -> structure_ptr: Pointer object of type dqueue of
*/
char *tril_container_dqueue_pop_end(DeQueueOf *structure_ptr)
{
    if (!structure_ptr)
    {
        return NULL;
    } // end if

    DeQueueNode *temp = structure_ptr->_end_ptr;
    char *value;
    structure_ptr->_end_ptr = temp->_prev_ptr;

    if (!structure_ptr->_end_ptr)
    {
        structure_ptr->_begin_ptr = NULL;
    } // end if
    else
    {
        structure_ptr->_end_ptr->_next_ptr = NULL;
    } // end else
    --structure_ptr->_size;
    value = temp->_data;
    free(temp);
    return value;
} // end of func

/*
  overview:
  > Should return the value stored in start pointer of
  > the dqueue container if the structure is both not a
  > nullptr value and or empty, if so we should return
  > a nullptr value.
  >
  args:
  -> structure_ptr: Pointer object of type dqueue of
*/
char *tril_container_dqueue_peek(DeQueueOf *structure_ptr)
{
    return tril_container_dqueue_peek_start(structure_ptr);
} // end of func

/*
  overview:
  > Should return the value stored in start pointer of
  > the dqueue container if the structure is both not a
  > nullptr value and or empty, if so we should return
  > a nullptr value.
  >
  args:
  -> structure_ptr: Pointer object of type dqueue of
*/
char *tril_container_dqueue_peek_start(DeQueueOf *structure_ptr)
{
    return (tril_container_dqueue_not_empty(structure_ptr)) ? structure_ptr->_begin_ptr->_data : NULL;
} // end of func

/*
  overview:
  > Should return the value stored in start pointer of
  > the dqueue container if the structure is both not a
  > nullptr value and or empty, if so we should return
  > a nullptr value.
  >
  args:
  -> structure_ptr: Pointer object of type dqueue of
*/
char *tril_container_dqueue_peek_end(DeQueueOf *structure_ptr)
{
    return (tril_container_dqueue_not_empty(structure_ptr)) ? structure_ptr->_end_ptr->_data : NULL;
} // end of func

/*
  overview:
  > Should return a success value if the structure if an
  > empty container.
  >
  args:
  -> structure_ptr: Pointer object of type dqueue of
*/
unsigned int tril_container_dqueue_its_empty(DeQueueOf *structure_ptr)
{
    return (!structure_ptr->_begin_ptr || !structure_ptr->_end_ptr) ? success : failed;
} // end of func

/*
  overview:
  > Should return a success value if the structure if an
  > not empty container.
  >
  args:
  -> structure_ptr: Pointer object of type dqueue of
*/
unsigned int tril_container_dqueue_not_empty(DeQueueOf *structure_ptr)
{
    return (structure_ptr->_begin_ptr || structure_ptr->_end_ptr) ? success : failed;
} // end of func

/*
  overview:
  > Should return a success value if the structure if an
  > not empty container.
  >
  args:
  -> structure_ptr: Pointer object of type dqueue of
*/
unsigned int tril_container_dqueue_get_size(DeQueueOf *structure_ptr)
{
    return (tril_container_dqueue_not_empty(structure_ptr)) ? structure_ptr->_size : failed;
} // end of func
