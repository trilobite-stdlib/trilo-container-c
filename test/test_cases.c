/*
   under:   trilobite stdlib
   author:  Michael Gene Ridge Brockus
   gmail:   <michaelbrockus@gmail.com>
   website: <https://trilobite.code.blog>
*/
#include "test_cases.h"


/*
 >
 > here main is used as the test runner
 >
*/
int main(void)
{
    //
    // setup and teardown can be set to nullptr.
    UTestRunner *runner = tril_utest_create_runner();

    //
    // TEST CASES FOR DOUBLY LINKED LIST
    tril_utest_set_setup(runner, setup_continaer_dlist);
    tril_utest_set_teardown(runner, teardown_continaer_dlist);

    tril_utest_run(runner, test_01_continaer_dlist_push_data);
    tril_utest_run(runner, test_02_continaer_dlist_push_multable_items);
    tril_utest_run(runner, test_03_continaer_dlist_push_nullsafe);
    tril_utest_run(runner, test_04_continaer_dlist_pop_data);
    tril_utest_run(runner, test_05_continaer_dlist_pop_nullsafe);
    tril_utest_run(runner, test_06_continaer_dlist_its_empty);
    tril_utest_run(runner, test_07_continaer_dlist_its_empty_nullsafe);
    tril_utest_run(runner, test_08_continaer_dlist_not_empty);
    tril_utest_run(runner, test_09_continaer_dlist_not_empty_nullsafe);

    //
    // TEST CASES FOR SINGLY LINKED LIST
    tril_utest_set_setup(runner, setup_continaer_slist);
    tril_utest_set_teardown(runner, teardown_continaer_slist);

    tril_utest_run(runner, test_01_continaer_slist_push_data);
    tril_utest_run(runner, test_02_continaer_slist_push_multable_items);
    tril_utest_run(runner, test_03_continaer_slist_push_nullsafe);
    tril_utest_run(runner, test_04_continaer_slist_pop_data);
    tril_utest_run(runner, test_05_continaer_slist_pop_nullsafe);
    tril_utest_run(runner, test_06_continaer_slist_its_empty);
    tril_utest_run(runner, test_07_continaer_slist_its_empty_nullsafe);
    tril_utest_run(runner, test_08_continaer_slist_not_empty);
    tril_utest_run(runner, test_09_continaer_slist_not_empty_nullsafe);

    //
    // TEST CASES FOR QUEUE
    tril_utest_set_setup(runner, setup_continaer_queue);
    tril_utest_set_teardown(runner, teardown_continaer_queue);

    tril_utest_run(runner, test_01_continaer_queue_push_data);
    tril_utest_run(runner, test_02_continaer_queue_push_multable_items);
    tril_utest_run(runner, test_03_continaer_queue_push_nullsafe);
    tril_utest_run(runner, test_04_continaer_queue_pop_data);
    tril_utest_run(runner, test_05_continaer_queue_pop_nullsafe);
    tril_utest_run(runner, test_06_continaer_queue_its_empty);
    tril_utest_run(runner, test_07_continaer_queue_its_empty_nullsafe);
    tril_utest_run(runner, test_08_continaer_queue_not_empty);
    tril_utest_run(runner, test_09_continaer_queue_not_empty_nullsafe);

    //
    // TEST CASES FOR DOUBLE ENDED QUEUE
    tril_utest_set_setup(runner, setup_continaer_dqueue);
    tril_utest_set_teardown(runner, teardown_continaer_dqueue);

    tril_utest_run(runner, test_01_continaer_dqueue_push_data);
    tril_utest_run(runner, test_02_continaer_dqueue_push_multable_items);
    tril_utest_run(runner, test_03_continaer_dqueue_push_nullsafe);
    tril_utest_run(runner, test_04_continaer_dqueue_pop_data);
    tril_utest_run(runner, test_05_continaer_dqueue_pop_nullsafe);
    tril_utest_run(runner, test_06_continaer_dqueue_its_empty);
    tril_utest_run(runner, test_07_continaer_dqueue_its_empty_nullsafe);
    tril_utest_run(runner, test_08_continaer_dqueue_not_empty);
    tril_utest_run(runner, test_09_continaer_dqueue_not_empty_nullsafe);

    //
    // TEST CASES FOR STACK
    tril_utest_set_setup(runner, setup_continaer_stack);
    tril_utest_set_teardown(runner, teardown_continaer_stack);

    tril_utest_run(runner, test_01_continaer_stack_push_data);
    tril_utest_run(runner, test_02_continaer_stack_push_multable_items);
    tril_utest_run(runner, test_03_continaer_stack_push_nullsafe);
    tril_utest_run(runner, test_04_continaer_stack_pop_data);
    tril_utest_run(runner, test_05_continaer_stack_pop_nullsafe);
    tril_utest_run(runner, test_06_continaer_stack_its_empty);
    tril_utest_run(runner, test_07_continaer_stack_its_empty_nullsafe);
    tril_utest_run(runner, test_08_continaer_stack_not_empty);
    tril_utest_run(runner, test_09_continaer_stack_not_empty_nullsafe);

    return tril_utest_end(runner);
} // end of function main
