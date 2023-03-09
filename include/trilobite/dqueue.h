/*
   under:   trilobite stdlib
   author:  Michael Gene Ridge Brockus
   gmail:   <michaelbrockus@gmail.com>
   website: <https://trilobite.code.blog>
*/
#ifndef TRILOBITE_CONTAINER_DQUEUE_H
#define TRILOBITE_CONTAINER_DQUEUE_H

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
typedef struct DeQueueOf DeQueueOf;

//
// Constructor and destructor functions
//

DeQueueOf *tril_container_dqueue_create(void);
void tril_container_dqueue_erase(DeQueueOf **structure_ref);
void tril_container_dqueue_push(DeQueueOf *structure_ptr, const char *data);
void tril_container_dqueue_push_start(DeQueueOf *structure_ptr, const char *data);
void tril_container_dqueue_push_end(DeQueueOf *structure_ptr, const char *data);
char *tril_container_dqueue_pop(DeQueueOf *structure_ptr);
char *tril_container_dqueue_pop_start(DeQueueOf *structure_ptr);
char *tril_container_dqueue_pop_end(DeQueueOf *structure_ptr);
char *tril_container_dqueue_peek(DeQueueOf *structure_ptr);
char *tril_container_dqueue_peek_start(DeQueueOf *structure_ptr);
char *tril_container_dqueue_peek_end(DeQueueOf *structure_ptr);
unsigned int tril_container_dqueue_its_empty(DeQueueOf *structure_ptr);
unsigned int tril_container_dqueue_not_empty(DeQueueOf *structure_ptr);
unsigned int tril_container_dqueue_get_size(DeQueueOf *structure_ptr);

#ifdef __cplusplus
}
#endif

#endif
