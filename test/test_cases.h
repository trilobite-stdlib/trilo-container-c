/*
   under:   trilobite stdlib
   author:  Michael Gene Ridge Brockus
   gmail:   <michaelbrockus@gmail.com>
   website: <https://trilobite.code.blog>
*/
#ifndef TRILOBITE_CONTAINER_TESTS_H
#define TRILOBITE_CONTAINER_TESTS_H

#include <trilobite/utest.h> // trilobite testing framework
#include <stdlib.h>          // needed for standard nullptr

#ifdef __cplusplus
extern "C"
{
#endif

//
// Test fixtures for the current project
//

//
//
//
void setup_continaer_dlist();
void teardown_continaer_dlist();

//
//
void test_01_continaer_dlist_push_data();
void test_02_continaer_dlist_push_multable_items();
void test_03_continaer_dlist_push_nullsafe();
void test_04_continaer_dlist_pop_data();
void test_05_continaer_dlist_pop_nullsafe();
void test_06_continaer_dlist_its_empty();
void test_07_continaer_dlist_its_empty_nullsafe();
void test_08_continaer_dlist_not_empty();
void test_09_continaer_dlist_not_empty_nullsafe();

//
//
//
void setup_continaer_slist();
void teardown_continaer_slist();

//
//
void test_01_continaer_slist_push_data();
void test_02_continaer_slist_push_multable_items();
void test_03_continaer_slist_push_nullsafe();
void test_04_continaer_slist_pop_data();
void test_05_continaer_slist_pop_nullsafe();
void test_06_continaer_slist_its_empty();
void test_07_continaer_slist_its_empty_nullsafe();
void test_08_continaer_slist_not_empty();
void test_09_continaer_slist_not_empty_nullsafe();

//
//
//
void setup_continaer_queue();
void teardown_continaer_queue();

//
//
void test_01_continaer_queue_push_data();
void test_02_continaer_queue_push_multable_items();
void test_03_continaer_queue_push_nullsafe();
void test_04_continaer_queue_pop_data();
void test_05_continaer_queue_pop_nullsafe();
void test_06_continaer_queue_its_empty();
void test_07_continaer_queue_its_empty_nullsafe();
void test_08_continaer_queue_not_empty();
void test_09_continaer_queue_not_empty_nullsafe();

//
//
//
void setup_continaer_dqueue();
void teardown_continaer_dqueue();

//
//
void test_01_continaer_dqueue_push_data();
void test_02_continaer_dqueue_push_multable_items();
void test_03_continaer_dqueue_push_nullsafe();
void test_04_continaer_dqueue_pop_data();
void test_05_continaer_dqueue_pop_nullsafe();
void test_06_continaer_dqueue_its_empty();
void test_07_continaer_dqueue_its_empty_nullsafe();
void test_08_continaer_dqueue_not_empty();
void test_09_continaer_dqueue_not_empty_nullsafe();

//
//
//
void setup_continaer_stack();
void teardown_continaer_stack();

//
//
void test_01_continaer_stack_push_data();
void test_02_continaer_stack_push_multable_items();
void test_03_continaer_stack_push_nullsafe();
void test_04_continaer_stack_pop_data();
void test_05_continaer_stack_pop_nullsafe();
void test_06_continaer_stack_its_empty();
void test_07_continaer_stack_its_empty_nullsafe();
void test_08_continaer_stack_not_empty();
void test_09_continaer_stack_not_empty_nullsafe();

#ifdef __cplusplus
}
#endif

#endif
