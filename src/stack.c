/*
   under:   trilobite stdlib
   author:  Michael Gene Ridge Brockus
   gmail:   <michaelbrockus@gmail.com>
   website: <https://trilobite.code.blog>
*/
#include "trilobite/stack.h"
#include <stdlib.h>
#include <string.h>

enum
{
    failed,
    success
}; // end of local enums

//
// This is the official definition for the Trilobite Libraries
// 'StackNode' type.
//
// Members:
// > [_data] is the private data member that represents the
//           data in the structure
// > [_next_ptr] is the pointer to the next node
//
typedef struct StackNode
{
    char *_data;
    struct StackNode *_next_ptr;
} StackNode; // end struct

//
// This is the official definition for the Trilobite Libraries
// 'StackOf' type.
//
// Members:
// > _top_ptr is the pointer to top of stack
//
struct StackOf
{
    size_t _size;
    struct StackNode *_top_ptr;
}; // end struct

/*
  overview:
  > Allocate memory for a new container stack structure
  > if structure is of a nullptr value we return a value
  > of nullptr else we return a ready structure with
  > data members set to default values.
  >
  args:
  -> ...: N/A
*/
StackOf *tril_container_stack_create(void)
{
    StackOf *new_structure = malloc(sizeof(*new_structure));
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
  -> structure_ref: Refrence object of type stack of
*/
void tril_container_stack_erase(StackOf **structure_ref)
{
    if (!*structure_ref)
    {
        return;
    } // end if

    StackOf *temp_structure = *structure_ref;

    while (!tril_container_stack_its_empty(temp_structure))
    {
        tril_container_stack_pop(temp_structure);
    } // end while

    free(temp_structure);
    temp_structure = NULL;
    *structure_ref = NULL;
} // end of func

/*
  overview:
  > Tacks a string as input and should push the string onto
  > the stack structure.
  >
  > If structure is a nullptr value we get nothing else try
  > to allocate a new note and if that can't be allocated
  > nothing happens else we get a new node for are stack.
  >
  args:
  -> structure_ptr: Pointer object of type stack of
  -> data: Input value of type string
*/
void tril_container_stack_push(StackOf *structure_ptr, const char *data)
{
    if (!structure_ptr)
    {
        return;
    } // end if

    StackNode *temp = malloc(sizeof(*temp));
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
  -> structure_ptr: Pointer object of type stack of
*/
char *tril_container_stack_pop(StackOf *structure_ptr)
{
    if (!structure_ptr || !structure_ptr->_top_ptr)
    {
        return NULL;
    } // end if

    StackNode *temp = structure_ptr->_top_ptr;
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
  > the stack container if the structure is both not a
  > nullptr value and or empty, if so we should return
  > a nullptr value.
  >
  args:
  -> structure_ptr: Pointer object of type stack of
*/
char *tril_container_stack_peek(StackOf *structure_ptr)
{
    return (structure_ptr->_top_ptr) ? structure_ptr->_top_ptr->_data : NULL;
} // end of func

/*
  overview:
  > Should return a success value if the structure is an
  > empty container.
  >
  args:
  -> structure_ptr: Pointer object of type stack of
*/
unsigned int tril_container_stack_its_empty(StackOf *structure_ptr)
{
    return (!structure_ptr->_top_ptr) ? success : failed;
} // end of func

/*
  overview:
  > Should return a success value if the structure is an
  > not empty container.
  >
  args:
  -> structure_ptr: Pointer object of type stack of
*/
unsigned int tril_container_stack_not_empty(StackOf *structure_ptr)
{
    return (structure_ptr->_top_ptr) ? success : failed;
} // end of func
