/*
   under:   trilobite stdlib
   author:  Michael Gene Ridge Brockus
   gmail:   <michaelbrockus@gmail.com>
   website: <https://trilobite.code.blog>
*/
#include "test_cases.h"      // unit test header
#include "trilobite/slist.h" // code under test

SListOf *mockSList;

/*
 >
 >  project setup teardown functions if needed
 >
*/
void setup_continaer_slist()
{
    mockSList = tril_container_slist_create();
} // end of function setUp

void teardown_continaer_slist()
{
    tril_container_slist_erase(&mockSList);
} // end of function tearDown

/*
 >
 > list of all the test cases for this project
 >
*/
void test_01_continaer_slist_push_data()
{
    //
    // we setup are test data here.
    const char *testData = "Some data";

    //
    // here we run the asserts
    tril_container_slist_push(mockSList, testData);
    tril_assert_equal_str("Some data", tril_container_slist_peek(mockSList));
} // end of test case

void test_02_continaer_slist_push_multable_items()
{
    //
    // we setup are test data here.
    const char *testData[] = {"Some data", "More data", "Cup of coffee"};

    //
    // here we run the asserts
    for (int iter = 0; iter < 3; iter++)
    {
        tril_container_slist_push(mockSList, testData[iter]);
    } // end for
    tril_assert_equal_str("Cup of coffee", tril_container_slist_peek(mockSList));
} // end of test case

void test_03_continaer_slist_push_nullsafe()
{
    //
    // we setup are test data here.
    const char *testData = "Some data";

    //
    // here we run the asserts
    tril_container_slist_push(NULL, testData);
    tril_assert_its_nullptr(tril_container_slist_peek(mockSList));
} // end of test case

void test_04_continaer_slist_pop_data()
{
    //
    // we setup are test data here.
    const char *testData[] = {"Some data", "More data", "Cup of coffee"};

    //
    // here we run the asserts
    for (int iter = 0; iter < 3; iter++)
    {
        tril_container_slist_push(mockSList, testData[iter]);
    } // end for
    tril_assert_equal_str("Cup of coffee", tril_container_slist_peek(mockSList));

    // then try to pop item of slist
    tril_container_slist_pop(mockSList);
    tril_assert_equal_str("More data", tril_container_slist_peek(mockSList));
} // end of test case

void test_05_continaer_slist_pop_nullsafe()
{
    //
    // we setup are test data here.
    const char *testData = "Some data";

    //
    // here we run the asserts
    tril_container_slist_push(NULL, testData);
    tril_assert_its_nullptr(tril_container_slist_peek(mockSList));
    tril_container_slist_pop(NULL);
    tril_assert_its_nullptr(tril_container_slist_peek(mockSList));
} // end of test case

void test_06_continaer_slist_its_empty()
{
    //
    // we setup are test data here.
    const char *testData = "Some data";

    //
    // here we run the asserts
    tril_assert_its_true(tril_container_slist_its_empty(mockSList));
    tril_container_slist_push(mockSList, testData);
    tril_assert_equal_str("Some data", tril_container_slist_peek(mockSList));
    tril_assert_its_false(tril_container_slist_its_empty(mockSList));
} // end of test case

void test_07_continaer_slist_its_empty_nullsafe()
{
    //
    // we setup are test data here.
    const char *testData = "Some data";

    //
    // here we run the asserts
    tril_assert_its_true(tril_container_slist_its_empty(mockSList));
    tril_container_slist_push(NULL, testData);
    tril_assert_its_nullptr(tril_container_slist_peek(mockSList));
    tril_assert_its_true(tril_container_slist_its_empty(mockSList));
} // end of test case

void test_08_continaer_slist_not_empty()
{
    //
    // we setup are test data here.
    const char *testData = "Some data";

    //
    // here we run the asserts
    tril_assert_its_false(tril_container_slist_not_empty(mockSList));
    tril_container_slist_push(mockSList, testData);
    tril_assert_equal_str("Some data", tril_container_slist_peek(mockSList));
    tril_assert_its_true(tril_container_slist_not_empty(mockSList));
} // end of test case

void test_09_continaer_slist_not_empty_nullsafe()
{
    //
    // we setup are test data here.
    const char *testData = "Some data";

    //
    // here we run the asserts
    tril_assert_its_false(tril_container_slist_not_empty(mockSList));
    tril_container_slist_push(NULL, testData);
    tril_assert_its_nullptr(tril_container_slist_peek(mockSList));
    tril_assert_its_false(tril_container_slist_not_empty(mockSList));
} // end of test case
