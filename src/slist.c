/*
   under:   trilobite stdlib
   author:  Michael Gene Ridge Brockus
   gmail:   <michaelbrockus@gmail.com>
   website: <https://trilobite.code.blog>
*/
#include "trilobite/slist.h"

#include <stdlib.h>
#include <string.h>

enum
{
    failed,
    success
}; // end of local enums

//
// This is the official definition for the Trilobite Libraries
// 'SListNode' type.
//
// Members:
// > [_data] is the private data member that represents the
//           data in the structure
// > [_next_ptr] is the pointer to the next node
//
typedef struct SListNode
{
    char *_data;
    struct SListNode *_next_ptr;
} SListNode; // end of struct

//
// This is the official definition for the Trilobite Libraries
// 'SListOf' type.
//
// Members:
// > _top_ptr is the pointer to top of SList
//
struct SListOf
{
    size_t _size;
    struct SListNode *_top_ptr;
}; // end of struct

/*
  overview:
  > Allocate memory for a new container slist structure
  > if structure is of a nullptr value we return a value
  > of nullptr else we return a ready structure with
  > data members set to default values.
  >
  args:
  -> ...: N/A
*/
SListOf *tril_container_slist_create(void)
{
    SListOf *new_structure = malloc(sizeof(*new_structure));
    if (!new_structure)
    {
        return NULL;
    } // end if
    new_structure->_size = 0;
    new_structure->_top_ptr = NULL;

    return new_structure;
} // end of func

/*
  overview:
  > takes a container structure and erases it from memory
  > back to the operating system for use in other programs.
  >
  args:
  -> structure_ref: Refrence object of type single linked list of
*/
void tril_container_slist_erase(SListOf **structure_ref)
{
    if (!*structure_ref)
    {
        return;
    } // end if

    SListOf *temp_structure = *structure_ref;

    while (!tril_container_slist_its_empty(temp_structure))
    {
        tril_container_slist_pop(temp_structure);
    } // end while

    free(temp_structure);
    temp_structure = NULL;
    *structure_ref = NULL;
} // end of func

/*
  overview:
  > Tacks a string as input and should push the string onto
  > the single linked list structure.
  >
  > If structure is a nullptr value we get nothing else try
  > to allocate a new note and if that can't be allocated
  > nothing happens else we get a new node for are single
  > linked list.
  >
  args:
  -> structure_ptr: Pointer object of type single linked list of
  -> data: Input value of type string
*/
void tril_container_slist_push(SListOf *structure_ptr, const char *data)
{
    if (!structure_ptr)
    {
        return;
    } // end if

    SListNode *temp = malloc(sizeof(*temp));
    if (!temp)
    {
        return;
    } // end if

    temp->_data = (char *)data;
    temp->_next_ptr = structure_ptr->_top_ptr;
    structure_ptr->_top_ptr = temp;
    ++structure_ptr->_size;
} // end of func

/*
  overview:
  > Should return the value stored in the removed node from
  > structure if the structure is both not nullptr and or
  > empty. If so where gonna return nullptr.
  >
  args:
  -> structure_ptr: Pointer object of type single linked list of
*/
char *tril_container_slist_pop(SListOf *structure_ptr)
{
    if (!structure_ptr || !structure_ptr->_top_ptr)
    {
        return NULL;
    } // end if

    SListNode *temp = structure_ptr->_top_ptr;
    char *popped = structure_ptr->_top_ptr->_data;
    structure_ptr->_top_ptr = structure_ptr->_top_ptr->_next_ptr;

    temp->_data = 0;
    temp->_next_ptr = NULL;
    --structure_ptr->_size;

    free(temp);
    temp = NULL;

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
  -> structure_ptr: Pointer object of type single linked list of
*/
char *tril_container_slist_peek(SListOf *structure_ptr)
{
    return (structure_ptr->_top_ptr) ? structure_ptr->_top_ptr->_data : NULL;
} // end of func

/*
  overview:
  > Should return a success value if the structure is an
  > empty container.
  >
  args:
  -> structure_ptr: Pointer object of type single linked list of
*/
unsigned int tril_container_slist_its_empty(SListOf *structure_ptr)
{
    return (!structure_ptr->_top_ptr) ? success : failed;
} // end of func

/*
  overview:
  > Should return a success value if the structure is an
  > not empty container.
  >
  args:
  -> structure_ptr: Pointer object of type single linked list of
*/
unsigned int tril_container_slist_not_empty(SListOf *structure_ptr)
{
    return (structure_ptr->_top_ptr) ? success : failed;
} // end of func
