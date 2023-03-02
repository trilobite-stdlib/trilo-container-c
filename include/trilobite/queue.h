/*
   under:   trilobite stdlib
   author:  Michael Gene Ridge Brockus
   gmail:   <michaelbrockus@gmail.com>
   website: <https://trilobite.code.blog>
*/
#ifndef TRILOBITE_CONTAINER_QUEUE_H
#define TRILOBITE_CONTAINER_QUEUE_H

#ifdef __cplusplus
extern "C"
{
#endif

//
//   PUBLIC APPLICATION INTERFACE
// --------------------------------
//
// Published library with provided public application interface for
// use in the users application. Please note that we are internationally
// targeting both c11 and c23 standards.
//

typedef struct QueueOf QueueOf;


QueueOf *tril_container_queue_create(void);
void tril_container_queue_erase(QueueOf **structure_ref);
void tril_container_queue_push(QueueOf *structure_ptr, const char *data);
const char *tril_container_queue_pop(QueueOf *structure_ptr);
const char *tril_container_queue_peek(QueueOf *structure_ptr);
unsigned int tril_container_queue_its_empty(QueueOf *structure_ptr);
unsigned int tril_container_queue_not_empty(QueueOf *structure_ptr);

#ifdef __cplusplus
}
#endif

#endif
