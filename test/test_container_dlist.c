/*
   under:   trilobite stdlib
   author:  Michael Gene Ridge Brockus
   gmail:   <michaelbrockus@gmail.com>
   website: <https://trilobite.code.blog>
*/
#include "test_cases.h"      // unit test header
#include "trilobite/dlist.h" // code under test

DListOf *mockDList;

/*
 >
 >  project setup teardown functions if needed
 >
*/
void setup_continaer_dlist()
{
    mockDList = tril_container_dlist_create();
} // end of function setUp

void teardown_continaer_dlist()
{
    tril_container_dlist_erase(&mockDList);
} // end of function tearDown

/*
 >
 > list of all the test cases for this project
 >
*/
void test_01_continaer_dlist_push_data()
{
    //
    // we setup are test data here.
    const char *testData = "Some data";

    //
    // here we run the asserts
    tril_container_dlist_push(mockDList, testData);
    tril_assert_equal_str("Some data", tril_container_dlist_peek(mockDList));
} // end of test case

void test_02_continaer_dlist_push_multable_items()
{
    //
    // we setup are test data here.
    const char *testData[] = {"Some data", "More data", "Cup of coffee"};

    //
    // here we run the asserts
    for (int iter = 0; iter < 3; iter++)
    {
        tril_container_dlist_push(mockDList, testData[iter]);
    } // end for
    tril_assert_equal_str("Cup of coffee", tril_container_dlist_peek(mockDList));
} // end of test case

void test_03_continaer_dlist_push_nullsafe()
{
    //
    // we setup are test data here.
    const char *testData = "Some data";

    //
    // here we run the asserts
    tril_container_dlist_push(NULL, testData);
    tril_assert_its_nullptr(tril_container_dlist_peek(mockDList));
} // end of test case

void test_04_continaer_dlist_pop_data()
{
    //
    // we setup are test data here.
    const char *testData[] = {"Some data", "More data", "Cup of coffee"};

    //
    // here we run the asserts
    for (int iter = 0; iter < 3; iter++)
    {
        tril_container_dlist_push(mockDList, testData[iter]);
    } // end for
    tril_assert_equal_str("Cup of coffee", tril_container_dlist_peek(mockDList));

    // then try to pop item of dlist
    tril_container_dlist_pop(mockDList);
    tril_assert_equal_str("More data", tril_container_dlist_peek(mockDList));
} // end of test case

void test_05_continaer_dlist_pop_nullsafe()
{
    //
    // we setup are test data here.
    const char *testData = "Some data";

    //
    // here we run the asserts
    tril_container_dlist_push(NULL, testData);
    tril_assert_its_nullptr(tril_container_dlist_peek(mockDList));
    tril_container_dlist_pop(NULL);
    tril_assert_its_nullptr(tril_container_dlist_peek(mockDList));
} // end of test case

void test_06_continaer_dlist_its_empty()
{
    //
    // we setup are test data here.
    const char *testData = "Some data";

    //
    // here we run the asserts
    tril_assert_its_true(tril_container_dlist_its_empty(mockDList));
    tril_container_dlist_push(mockDList, testData);
    tril_assert_equal_str("Some data", tril_container_dlist_peek(mockDList));
    tril_assert_its_false(tril_container_dlist_its_empty(mockDList));
} // end of test case

void test_07_continaer_dlist_its_empty_nullsafe()
{
    //
    // we setup are test data here.
    const char *testData = "Some data";

    //
    // here we run the asserts
    tril_assert_its_true(tril_container_dlist_its_empty(mockDList));
    tril_container_dlist_push(NULL, testData);
    tril_assert_its_nullptr(tril_container_dlist_peek(mockDList));
    tril_assert_its_true(tril_container_dlist_its_empty(mockDList));
} // end of test case

void test_08_continaer_dlist_not_empty()
{
    //
    // we setup are test data here.
    const char *testData = "Some data";

    //
    // here we run the asserts
    tril_assert_its_false(tril_container_dlist_not_empty(mockDList));
    tril_container_dlist_push(mockDList, testData);
    tril_assert_equal_str("Some data", tril_container_dlist_peek(mockDList));
    tril_assert_its_true(tril_container_dlist_not_empty(mockDList));
} // end of test case

void test_09_continaer_dlist_not_empty_nullsafe()
{
    //
    // we setup are test data here.
    const char *testData = "Some data";

    //
    // here we run the asserts
    tril_assert_its_false(tril_container_dlist_not_empty(mockDList));
    tril_container_dlist_push(NULL, testData);
    tril_assert_its_nullptr(tril_container_dlist_peek(mockDList));
    tril_assert_its_false(tril_container_dlist_not_empty(mockDList));
} // end of test case
