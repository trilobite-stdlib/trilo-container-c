/*
   under:   trilobite stdlib
   author:  Michael Gene Ridge Brockus
   gmail:   <michaelbrockus@gmail.com>
   website: <https://trilobite.code.blog>
*/
#ifndef TRILOBITE_CONTAINER_SLIST_H
#define TRILOBITE_CONTAINER_SLIST_H

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
typedef struct SListOf SListOf;

SListOf *tril_container_slist_create(void);
void tril_container_slist_erase(SListOf **structure_ref);
void tril_container_slist_push(SListOf *structure_ptr, const char *data);
char *tril_container_slist_pop(SListOf *structure_ptr);
char *tril_container_slist_peek(SListOf *structure_ptr);
unsigned int tril_container_slist_its_empty(SListOf *structure_ptr);
unsigned int tril_container_slist_not_empty(SListOf *structure_ptr);

#ifdef __cplusplus
}
#endif

#endif
