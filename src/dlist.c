/*
   under:   trilobite stdlib
   author:  Michael Gene Ridge Brockus
   gmail:   <michaelbrockus@gmail.com>
   website: <https://trilobite.code.blog>
*/
#include "trilobite/dlist.h"
#include <stdlib.h>
#include <string.h>

enum
{
    failed,
    success
}; // end of local enums

//
// This is the official definition for the Trilobite Libraries
// 'DListNode' type.
//
// Members:
// > [_data] is the private data member that represents the
//           data in the structure
// > [_next_ptr] is the pointer to the next node
//
typedef struct DListNode
{
    char *_data;
    struct DListNode *_next_ptr;
    struct DListNode *_prev_ptr;
} DListNode; // end of struct

//
// This is the official definition for the Trilobite Libraries
// 'DListOf' type.
//
// Members:
// > _size is the number of nodes in the current list
// > _begin_ptr is the pointer to begining of the DList
// > _end_ptr is the pointer to ending of the DList
//
struct DListOf
{
    size_t _size;
    struct DListNode *_begin_ptr;
    struct DListNode *_end_ptr;
}; // end of struct

/*
  overview:
  > Allocate memory for a new container dlist structure
  > if structure is of a nullptr value we return a value
  > of nullptr else we return a ready structure with
  > data members set to default values.
  >
  args:
  -> ...: N/A
*/
DListOf *tril_container_dlist_create(void)
{
    DListOf *new_structure = malloc(sizeof(*new_structure));
    if (!new_structure)
    {
        return NULL;
    } // end if
    new_structure->_size = 0;
    new_structure->_begin_ptr = NULL;
    new_structure->_end_ptr = NULL;

    return new_structure;
} // end of func

/*
  overview:
  > takes a container structure and erases it from memory
  > back to the operating system for use in other programs.
  >
  args:
  -> structure_ref: Refrence object of type double linked list of
*/
void tril_container_dlist_erase(DListOf **structure_ref)
{
    if (!*structure_ref)
    {
        return;
    } // end if

    DListOf *temp_structure = *structure_ref;

    while (!tril_container_dlist_its_empty(temp_structure))
    {
        tril_container_dlist_pop(temp_structure);
    } // end while

    free(temp_structure);
    temp_structure = NULL;
    *structure_ref = NULL;
} // end of func

/*
  overview:
  > Tacks a string as input and should push the string onto
  > the double linked list structure.
  >
  > If structure is a nullptr value we get nothing else try
  > to allocate a new note and if that can't be allocated
  > nothing happens else we get a new node for are double
  > linked list.
  >
  args:
  -> structure_ptr: Pointer object of type double linked list of
  -> data: Input value of type string
*/
void tril_container_dlist_push(DListOf *structure_ptr, const char *data)
{
    if (!structure_ptr)
    {
        return;
    } // end if

    DListNode *temp = malloc(sizeof(*temp));
    if (!temp)
    {
        return;
    } // end if

    temp->_data = (char *)data;
    temp->_next_ptr = NULL;
    temp->_prev_ptr = NULL;

    if (!structure_ptr->_begin_ptr)
    {
        structure_ptr->_begin_ptr = temp;
        structure_ptr->_end_ptr = temp;
    } // end if
    else
    {
        temp->_prev_ptr = structure_ptr->_end_ptr;
        structure_ptr->_end_ptr->_next_ptr = temp;
        structure_ptr->_end_ptr = temp;
    } // end else
    ++structure_ptr->_size;
} // end of func

/*
  overview:
  > Should return the value stored in the removed node from
  > structure if the structure is both not nullptr and or
  > empty. If so where gonna return nullptr.
  >
  args:
  -> structure_ptr: Pointer object of type doubly linked list of
*/
char *tril_container_dlist_pop(DListOf *structure_ptr)
{
    if (!structure_ptr->_begin_ptr)
    {
        return NULL;
    } // end if

    DListNode *temp = structure_ptr->_end_ptr;
    char *popped = temp->_data;
    if (temp == structure_ptr->_begin_ptr && structure_ptr->_end_ptr)
    {
        structure_ptr->_begin_ptr = NULL;
        structure_ptr->_end_ptr = NULL;
    } // end if
    else if (temp == structure_ptr->_begin_ptr)
    {
        structure_ptr->_begin_ptr->_prev_ptr = NULL;
        structure_ptr->_begin_ptr = structure_ptr->_begin_ptr->_next_ptr;
    } // end else

    else if (temp == structure_ptr->_end_ptr)
    {
        structure_ptr->_end_ptr->_prev_ptr->_next_ptr = NULL;
        structure_ptr->_end_ptr = structure_ptr->_end_ptr->_prev_ptr;
        structure_ptr->_size--;
    } // end if else
    else
    {
        temp->_prev_ptr->_next_ptr = temp->_next_ptr;
        temp->_next_ptr->_prev_ptr = temp->_prev_ptr;
        structure_ptr->_size--;
    } // end else

    --structure_ptr->_size;

    free(temp);
    return popped;
} // end of func

/*
  overview:
  > Should return the value stored in start pointer of
  > the slist container if the structure is both not a
  > nullptr value and or empty, if so we should return
  > a nullptr value.
  >
  args:
  -> structure_ptr: Pointer object of type doubly linked list of
*/
char *tril_container_dlist_peek(DListOf *structure_ptr)
{
    if (structure_ptr->_end_ptr)
    {
        return structure_ptr->_end_ptr->_data;
    } // end if
    else if (structure_ptr->_begin_ptr)
    {
        return structure_ptr->_begin_ptr->_data;
    } // end else if
    return NULL;
} // end of func

/*
  overview:
  > Should return a success value if the structure is an
  > empty container.
  >
  args:
  -> structure_ptr: Pointer object of type doubly linked list of
*/
unsigned int tril_container_dlist_its_empty(DListOf *structure_ptr)
{
    return (!structure_ptr->_begin_ptr) ? success : failed;
} // end of func

/*
  overview:
  > Should return a success value if the structure is an
  > not empty container.
  >
  args:
  -> structure_ptr: Pointer object of type doubly linked list of
*/
unsigned int tril_container_dlist_not_empty(DListOf *structure_ptr)
{
    return (structure_ptr->_begin_ptr) ? success : failed;
} // end of func
