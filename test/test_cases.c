/*
   under:   trilobite stdlib
   author:  Michael Gene Ridge Brockus
   gmail:   <michaelbrockus@gmail.com>
   website: <https://trilobite.code.blog>
*/
#include "test_cases.h"
#include <trilobite/utest.h>

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
    // test fixture group for the current project.
    fixture_container_dqueue(runner);
    fixture_container_queue(runner);
    fixture_container_dlist(runner);
    fixture_container_slist(runner);
    fixture_container_stack(runner);

    return tril_utest_end(runner);
} // end of function main
