/*
   under:   trilobite stdlib
   author:  Michael Gene Ridge Brockus
   gmail:   <michaelbrockus@gmail.com>
   website: <https://trilobite.code.blog>
*/
#ifndef TRILOBITE_CONTAINER_TESTS_H
#define TRILOBITE_CONTAINER_TESTS_H

#include <trilobite/utest.h>

#ifdef __cplusplus
extern "C"
{
#endif

//
// Test fixtures for the current project
//
void fixture_container_stack(UTestRunner *runner);
void fixture_container_slist(UTestRunner *runner);
void fixture_container_dlist(UTestRunner *runner);
void fixture_container_queue(UTestRunner *runner);
void fixture_container_dqueue(UTestRunner *runner);

#ifdef __cplusplus
}
#endif

#endif
