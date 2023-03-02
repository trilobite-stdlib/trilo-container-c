/*
   under:   trilobite stdlib
   author:  Michael Gene Ridge Brockus
   gmail:   <michaelbrockus@gmail.com>
   website: <https://trilobite.code.blog>
*/
#include "trilobite/queue.h"

#include <stdlib.h>

enum
{
    failed,
    success
}; // end of local enums

//
// This is the official definition for the Trilobite Libraries
// 'QueueNode' type.
//
// Members:
// > [_data] is the private data member that represents the
//           data in the structure
// > [_next_ptr] is the pointer to the next node in the stack
//
typedef struct QueueNode
{
    char *_data;
    struct QueueNode *_next_ptr;
} QueueNode; // end of struct

//
// This is the official definition for the Trilobite Libraries
// 'QueueOf' type.
//
// Members:
// > _begin_ptr is the pointer to queue begin
// > _end_ptr is the pointer to queue end
//
struct QueueOf
{
    size_t _size;
    struct QueueNode *_end_ptr;
    struct QueueNode *_begin_ptr;
}; // end of struct

/*
  overview:
  > Allocate memory for a new container queue structure
  > if structure is of a nullptr value we return a value
  > of nullptr else we return a ready structure with
  > data members set to default values.
  >
  args:
  -> ...: N/A
*/
QueueOf *tril_container_queue_create(void)
{
    QueueOf *new_structure = malloc(sizeof(*new_structure));
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
  -> structure_ref: Refrence object of type queue of
*/
void tril_container_queue_erase(QueueOf **structure_ref)
{
    if (!structure_ref || !*structure_ref)
    {
        return;
    } // end if

    while (tril_container_queue_not_empty(*structure_ref))
    {
        tril_container_queue_pop(*structure_ref);
    } // end while

    free(*structure_ref);
    *structure_ref = NULL;
} // end of func

/*
  overview:
  > Tacks a string as input and should push the string onto
  > the queue structure.
  >
  > If structure is a nullptr value we get nothing else try
  > to allocate a new note and if that can't be allocated
  > nothing happens else we get a new node for are queue.
  >
  args:
  -> structure_ptr: Pointer object of type queue of
  -> data: Input value of type string
*/
void tril_container_queue_push(QueueOf *structure_ptr, const char *data)
{
    if (!structure_ptr)
    {
        return;
    } // end if

    QueueNode *temp = malloc(sizeof(*temp));
    if (!temp)
    {
        return;
    } // end if

    temp->_data = (char *)data;
    temp->_next_ptr = NULL;

    //
    // If queue is empty, then set the new node to both begin and end
    if (!structure_ptr->_end_ptr)
    {
        structure_ptr->_begin_ptr = structure_ptr->_end_ptr = temp;
    } // end if
    else
    {
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
  -> structure_ptr: Pointer object of type queue of
*/
const char *tril_container_queue_pop(QueueOf *structure_ptr)
{
    if (!structure_ptr || !structure_ptr->_begin_ptr)
    {
        return NULL;
    } // end if

    //
    // Here we store previous node to begin and move it close to end
    QueueNode *temp = structure_ptr->_begin_ptr;
    structure_ptr->_begin_ptr = structure_ptr->_begin_ptr->_next_ptr;

    if (!structure_ptr->_begin_ptr)
    {
        structure_ptr->_end_ptr = NULL;
        return NULL;
    } // end if
    else
    {
        return temp->_data;
    } // end else
} // end of func

/*
  overview:
  > Should return the value stored in start pointer of
  > the queue container if the structure is both not a
  > nullptr value and or empty, if so we should return
  > a nullptr value.
  >
  args:
  -> structure_ptr: Pointer object of type queue of
*/
const char *tril_container_queue_peek(QueueOf *structure_ptr)
{
    if (!structure_ptr || !structure_ptr->_begin_ptr)
    {
        return NULL;
    } // end if
    return structure_ptr->_begin_ptr->_data;
} // end of func

/*
  overview:
  > Should return a success value if the structure if an
  > empty container.
  >
  args:
  -> structure_ptr: Pointer object of type queue of
*/
unsigned int tril_container_queue_its_empty(QueueOf *structure_ptr)
{
    return (!structure_ptr->_begin_ptr) ? success : failed;
} // end of func

/*
  overview:
  > Should return a success value if the structure if an
  > not empty container.
  >
  args:
  -> structure_ptr: Pointer object of type queue of
*/
unsigned int tril_container_queue_not_empty(QueueOf *structure_ptr)
{
    return (structure_ptr->_begin_ptr) ? success : failed;
} // end of func
