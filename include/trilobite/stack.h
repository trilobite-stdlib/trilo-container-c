/*
   under:   trilobite stdlib
   author:  Michael Gene Ridge Brockus
   gmail:   <michaelbrockus@gmail.com>
   website: <https://trilobite.code.blog>
*/
#ifndef TRILOBITE_CONTAINER_STACK_H
#define TRILOBITE_CONTAINER_STACK_H

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

//
// DEF OF DATA TYPE
//
typedef struct StackOf StackOf;

//
// DEFS OF FUNCTIONS
//
StackOf *tril_container_stack_create(void);
void tril_container_stack_erase(StackOf **structure_ref);
void tril_container_stack_push(StackOf *structure_ptr, const char *data);
char *tril_container_stack_pop(StackOf *structure_ptr);
char *tril_container_stack_peek(StackOf *structure_ptr);
unsigned int tril_container_stack_its_empty(StackOf *structure_ptr);
unsigned int tril_container_stack_not_empty(StackOf *structure_ptr);

#ifdef __cplusplus
}
#endif

#endif
