/*
   under:   trilobite stdlib
   author:  Michael Gene Ridge Brockus
   gmail:   <michaelbrockus@gmail.com>
   website: <https://trilobite.code.blog>
*/
#include "test_cases.h"      // unit test header
#include "trilobite/queue.h" // code under test

QueueOf *mockQueue;

/*
 >
 >  project setup teardown functions if needed
 >
*/
void setup_continaer_queue()
{
    mockQueue = tril_container_queue_create();
} // end of function setUp

void teardown_continaer_queue()
{
    tril_container_queue_erase(&mockQueue);
} // end of function tearDown

/*
 >
 > list of all the test cases for this project
 >
*/
void test_01_continaer_queue_push_data()
{
    //
    // we setup are test data here.
    const char *testData = "Some data";

    //
    // here we run the asserts
    tril_container_queue_push(mockQueue, testData);
    tril_assert_equal_str("Some data", tril_container_queue_peek(mockQueue));
} // end of test case

void test_02_continaer_queue_push_multable_items()
{
    //
    // we setup are test data here.
    const char *testData[] = {"Some data", "More data", "Cup of coffee"};

    //
    // here we run the asserts
    for (int iter = 0; iter < 3; iter++)
    {
        tril_container_queue_push(mockQueue, testData[iter]);
    } // end for
    tril_assert_equal_str("Some data", tril_container_queue_peek(mockQueue));
} // end of test case

void test_03_continaer_queue_push_nullsafe()
{
    //
    // we setup are test data here.
    const char *testData = "Some data";

    //
    // here we run the asserts
    tril_container_queue_push(NULL, testData);
    tril_assert_its_nullptr(tril_container_queue_peek(mockQueue));
} // end of test case

void test_04_continaer_queue_pop_data()
{
    //
    // we setup are test data here.
    const char *testData[] = {"Some data", "More data", "Cup of coffee"};

    //
    // here we run the asserts
    for (int iter = 0; iter < 3; iter++)
    {
        tril_container_queue_push(mockQueue, testData[iter]);
    } // end for
    tril_assert_equal_str("Some data", tril_container_queue_peek(mockQueue));

    // then try to pop item of queue
    tril_container_queue_pop(mockQueue);
    tril_assert_equal_str("More data", tril_container_queue_peek(mockQueue));
} // end of test case

void test_05_continaer_queue_pop_nullsafe()
{
    //
    // we setup are test data here.
    const char *testData = "Some data";

    //
    // here we run the asserts
    tril_container_queue_push(NULL, testData);
    tril_assert_its_nullptr(tril_container_queue_peek(mockQueue));
    tril_container_queue_pop(NULL);
    tril_assert_its_nullptr(tril_container_queue_peek(mockQueue));
} // end of test case

void test_06_continaer_queue_its_empty()
{
    //
    // we setup are test data here.
    const char *testData = "Some data";

    //
    // here we run the asserts
    tril_assert_its_true(tril_container_queue_its_empty(mockQueue));
    tril_container_queue_push(mockQueue, testData);
    tril_assert_equal_str("Some data", tril_container_queue_peek(mockQueue));
    tril_assert_its_false(tril_container_queue_its_empty(mockQueue));
} // end of test case

void test_07_continaer_queue_its_empty_nullsafe()
{
    //
    // we setup are test data here.
    const char *testData = "Some data";

    //
    // here we run the asserts
    tril_assert_its_true(tril_container_queue_its_empty(mockQueue));
    tril_container_queue_push(NULL, testData);
    tril_assert_its_nullptr(tril_container_queue_peek(mockQueue));
    tril_assert_its_true(tril_container_queue_its_empty(mockQueue));
} // end of test case

void test_08_continaer_queue_not_empty()
{
    //
    // we setup are test data here.
    const char *testData = "Some data";

    //
    // here we run the asserts
    tril_assert_its_false(tril_container_queue_not_empty(mockQueue));
    tril_container_queue_push(mockQueue, testData);
    tril_assert_equal_str("Some data", tril_container_queue_peek(mockQueue));
    tril_assert_its_true(tril_container_queue_not_empty(mockQueue));
} // end of test case

void test_09_continaer_queue_not_empty_nullsafe()
{
    //
    // we setup are test data here.
    const char *testData = "Some data";

    //
    // here we run the asserts
    tril_assert_its_false(tril_container_queue_not_empty(mockQueue));
    tril_container_queue_push(NULL, testData);
    tril_assert_its_nullptr(tril_container_queue_peek(mockQueue));
    tril_assert_its_false(tril_container_queue_not_empty(mockQueue));
} // end of test case
