/*
   under:   trilobite stdlib
   author:  Michael Gene Ridge Brockus
   gmail:   <michaelbrockus@gmail.com>
   website: <https://trilobite.code.blog>
*/
#include "test_cases.h"       // unit test header
#include "trilobite/dqueue.h" // code under test

DeQueueOf *mockDQueue;

/*
 >
 >  project setup teardown functions if needed
 >
*/
void setup_continaer_dqueue()
{
    mockDQueue = tril_container_dqueue_create();
} // end of function setUp

void teardown_continaer_dqueue()
{
    tril_container_dqueue_erase(&mockDQueue);
} // end of function tearDown

/*
 >
 > list of all the test cases for this project
 >
*/
void test_01_continaer_dqueue_push_data()
{
    //
    // we setup are test data here.
    const char *testData = "Some data";

    //
    // here we run the asserts
    tril_container_dqueue_push(mockDQueue, testData);
    tril_assert_equal_str("Some data", tril_container_dqueue_peek(mockDQueue));
} // end of test case

void test_02_continaer_dqueue_push_multable_items()
{
    //
    // we setup are test data here.
    const char *testData[] = {"Some data", "More data", "Cup of coffee"};

    //
    // here we run the asserts
    for (int iter = 0; iter < 3; iter++)
    {
        tril_container_dqueue_push(mockDQueue, testData[iter]);
    } // end for
    tril_assert_equal_str("Cup of coffee", tril_container_dqueue_peek(mockDQueue));
} // end of test case

void test_03_continaer_dqueue_push_nullsafe()
{
    //
    // we setup are test data here.
    const char *testData = "Some data";

    //
    // here we run the asserts
    tril_container_dqueue_push(NULL, testData);
    tril_assert_its_nullptr(tril_container_dqueue_peek(mockDQueue));
} // end of test case

void test_04_continaer_dqueue_pop_data()
{
    //
    // we setup are test data here.
    const char *testData[] = {"Some data", "More data", "Cup of coffee"};

    //
    // here we run the asserts
    for (int iter = 0; iter < 3; iter++)
    {
        tril_container_dqueue_push(mockDQueue, testData[iter]);
    } // end for
    tril_assert_equal_str("Cup of coffee", tril_container_dqueue_peek(mockDQueue));

    // then try to pop item of queue
    tril_container_dqueue_pop(mockDQueue);
    tril_assert_equal_str("More data", tril_container_dqueue_peek(mockDQueue));
} // end of test case

void test_05_continaer_dqueue_pop_nullsafe()
{
    //
    // we setup are test data here.
    const char *testData = "Some data";

    //
    // here we run the asserts
    tril_container_dqueue_push(NULL, testData);
    tril_assert_its_nullptr(tril_container_dqueue_peek(mockDQueue));
    tril_container_dqueue_pop(NULL);
    tril_assert_its_nullptr(tril_container_dqueue_peek(mockDQueue));
} // end of test case

void test_06_continaer_dqueue_its_empty()
{
    //
    // we setup are test data here.
    const char *testData = "Some data";

    //
    // here we run the asserts
    tril_assert_its_true(tril_container_dqueue_its_empty(mockDQueue));
    tril_container_dqueue_push(mockDQueue, testData);
    tril_assert_equal_str("Some data", tril_container_dqueue_peek(mockDQueue));
    tril_assert_its_false(tril_container_dqueue_its_empty(mockDQueue));
} // end of test case

void test_07_continaer_dqueue_its_empty_nullsafe()
{
    //
    // we setup are test data here.
    const char *testData = "Some data";

    //
    // here we run the asserts
    tril_assert_its_true(tril_container_dqueue_its_empty(mockDQueue));
    tril_container_dqueue_push(NULL, testData);
    tril_assert_its_nullptr(tril_container_dqueue_peek(mockDQueue));
    tril_assert_its_true(tril_container_dqueue_its_empty(mockDQueue));
} // end of test case

void test_08_continaer_dqueue_not_empty()
{
    //
    // we setup are test data here.
    const char *testData = "Some data";

    //
    // here we run the asserts
    tril_assert_its_false(tril_container_dqueue_not_empty(mockDQueue));
    tril_container_dqueue_push(mockDQueue, testData);
    tril_assert_equal_str("Some data", tril_container_dqueue_peek(mockDQueue));
    tril_assert_its_true(tril_container_dqueue_not_empty(mockDQueue));
} // end of test case

void test_09_continaer_dqueue_not_empty_nullsafe()
{
    //
    // we setup are test data here.
    const char *testData = "Some data";

    //
    // here we run the asserts
    tril_assert_its_false(tril_container_dqueue_not_empty(mockDQueue));
    tril_container_dqueue_push(NULL, testData);
    tril_assert_its_nullptr(tril_container_dqueue_peek(mockDQueue));
    tril_assert_its_false(tril_container_dqueue_not_empty(mockDQueue));
} // end of test case
