/*
   under:   trilobite stdlib
   author:  Michael Gene Ridge Brockus
   gmail:   <michaelbrockus@gmail.com>
   website: <https://trilobite.code.blog>
*/
#include "test_cases.h"      // unit test header
#include "trilobite/stack.h" // code under test

StackOf *mockStack;

/*
 >
 >  project setup teardown functions if needed
 >
*/
void setup_continaer_stack()
{
    mockStack = tril_container_stack_create();
} // end of function setUp

void teardown_continaer_stack()
{
    tril_container_stack_erase(&mockStack);
} // end of function tearDown

/*
 >
 > list of all the test cases for this project
 >
*/
void test_01_continaer_stack_push_data()
{
    //
    // we setup are test data here.
    const char *testData = "Some data";

    //
    // here we run the asserts
    tril_container_stack_push(mockStack, testData);
    tril_assert_equal_str("Some data", tril_container_stack_peek(mockStack));
} // end of test case

void test_02_continaer_stack_push_multable_items()
{
    //
    // we setup are test data here.
    const char *testData[] = {"Some data", "More data", "Cup of coffee"};

    //
    // here we run the asserts
    for (int iter = 0; iter < 3; iter++)
    {
        tril_container_stack_push(mockStack, testData[iter]);
    } // end for
    tril_assert_equal_str("Cup of coffee", tril_container_stack_peek(mockStack));
} // end of test case

void test_03_continaer_stack_push_nullsafe()
{
    //
    // we setup are test data here.
    const char *testData = "Some data";

    //
    // here we run the asserts
    tril_container_stack_push(NULL, testData);
    tril_assert_its_nullptr(tril_container_stack_peek(mockStack));
} // end of test case

void test_04_continaer_stack_pop_data()
{
    //
    // we setup are test data here.
    const char *testData[] = {"Some data", "More data", "Cup of coffee"};

    //
    // here we run the asserts
    for (int iter = 0; iter < 3; iter++)
    {
        tril_container_stack_push(mockStack, testData[iter]);
    } // end for
    tril_assert_equal_str("Cup of coffee", tril_container_stack_peek(mockStack));

    // then try to pop item of stack
    tril_container_stack_pop(mockStack);
    tril_assert_equal_str("More data", tril_container_stack_peek(mockStack));
} // end of test case

void test_05_continaer_stack_pop_nullsafe()
{
    //
    // we setup are test data here.
    const char *testData = "Some data";

    //
    // here we run the asserts
    tril_container_stack_push(NULL, testData);
    tril_assert_its_nullptr(tril_container_stack_peek(mockStack));
    tril_container_stack_pop(NULL);
    tril_assert_its_nullptr(tril_container_stack_peek(mockStack));
} // end of test case

void test_06_continaer_stack_its_empty()
{
    //
    // we setup are test data here.
    const char *testData = "Some data";

    //
    // here we run the asserts
    tril_assert_its_true(tril_container_stack_its_empty(mockStack));
    tril_container_stack_push(mockStack, testData);
    tril_assert_equal_str("Some data", tril_container_stack_peek(mockStack));
    tril_assert_its_false(tril_container_stack_its_empty(mockStack));
} // end of test case

void test_07_continaer_stack_its_empty_nullsafe()
{
    //
    // we setup are test data here.
    const char *testData = "Some data";

    //
    // here we run the asserts
    tril_assert_its_true(tril_container_stack_its_empty(mockStack));
    tril_container_stack_push(NULL, testData);
    tril_assert_its_nullptr(tril_container_stack_peek(mockStack));
    tril_assert_its_true(tril_container_stack_its_empty(mockStack));
} // end of test case

void test_08_continaer_stack_not_empty()
{
    //
    // we setup are test data here.
    const char *testData = "Some data";

    //
    // here we run the asserts
    tril_assert_its_false(tril_container_stack_not_empty(mockStack));
    tril_container_stack_push(mockStack, testData);
    tril_assert_equal_str("Some data", tril_container_stack_peek(mockStack));
    tril_assert_its_true(tril_container_stack_not_empty(mockStack));
} // end of test case

void test_09_continaer_stack_not_empty_nullsafe()
{
    //
    // we setup are test data here.
    const char *testData = "Some data";

    //
    // here we run the asserts
    tril_assert_its_false(tril_container_stack_not_empty(mockStack));
    tril_container_stack_push(NULL, testData);
    tril_assert_its_nullptr(tril_container_stack_peek(mockStack));
    tril_assert_its_false(tril_container_stack_not_empty(mockStack));
} // end of test case
