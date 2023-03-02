/*
   under:   trilobite stdlib
   author:  Michael Gene Ridge Brockus
   gmail:   <michaelbrockus@gmail.com>
   website: <https://trilobite.code.blog>
*/
#ifndef TRILOBITE_CONTAINER_DLIST_H
#define TRILOBITE_CONTAINER_DLIST_H

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

typedef struct DListOf DListOf;


DListOf *tril_container_dlist_create(void);
void tril_container_dlist_erase(DListOf **structure_ref);
void tril_container_dlist_push(DListOf *structure_ptr, const char *data);
char *tril_container_dlist_pop(DListOf *structure_ptr);
char *tril_container_dlist_peek(DListOf *structure_ptr);
unsigned int tril_container_dlist_its_empty(DListOf *structure_ptr);
unsigned int tril_container_dlist_not_empty(DListOf *structure_ptr);

#ifdef __cplusplus
}
#endif

#endif
