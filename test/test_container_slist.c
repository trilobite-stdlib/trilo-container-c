/*
   under:   trilobite stdlib
   author:  Michael Gene Ridge Brockus
   gmail:   <michaelbrockus@gmail.com>
   website: <https://trilobite.code.blog>
*/
#include "test_cases.h"      // test case header
#include "trilobite/slist.h" // code under test

#include <trilobite/utest.h> // trilobite test framework
#include <stdlib.h> // needed for standard nullptr

SListOf *mockSList;

/*
 >
 >  project setup teardown functions if needed
 >
*/
static void setup()
{
    mockSList = tril_container_slist_create();
} // end of function setUp


static void teardown()
{
    tril_container_slist_erase(&mockSList);
} // end of function tearDown


/*
 >
 > list of all the test cases for this project
 >
*/
static void test_01_continaer_slist_push_data()
{
    //
    // we setup are test data here.
    const char *testData = "Some data";

    //
    // here we run the asserts
    tril_container_slist_push(mockSList, testData);
    tril_assert_equal_str("Some data", tril_container_slist_peek(mockSList));
} // end of test case

static void test_02_continaer_slist_push_multable_items()
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

static void test_03_continaer_slist_push_nullsafe()
{
    //
    // we setup are test data here.
    const char *testData = "Some data";

    //
    // here we run the asserts
    tril_container_slist_push(NULL, testData);
    tril_assert_equal_str(NULL, tril_container_slist_peek(mockSList));
} // end of test case

static void test_04_continaer_slist_pop_data()
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

static void test_05_continaer_slist_pop_nullsafe()
{
    //
    // we setup are test data here.
    const char *testData = "Some data";

    //
    // here we run the asserts
    tril_container_slist_push(NULL, testData);
    tril_assert_equal_str(NULL, tril_container_slist_peek(mockSList));
    tril_container_slist_pop(NULL);
    tril_assert_equal_str(NULL, tril_container_slist_peek(mockSList));
} // end of test case

static void test_06_continaer_slist_its_empty()
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

static void test_07_continaer_slist_its_empty_nullsafe()
{
    //
    // we setup are test data here.
    const char *testData = "Some data";

    //
    // here we run the asserts
    tril_assert_its_true(tril_container_slist_its_empty(mockSList));
    tril_container_slist_push(NULL, testData);
    tril_assert_equal_str(NULL, tril_container_slist_peek(mockSList));
    tril_assert_its_true(tril_container_slist_its_empty(mockSList));
} // end of test case

static void test_08_continaer_slist_not_empty()
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

static void test_09_continaer_slist_not_empty_nullsafe()
{
    //
    // we setup are test data here.
    const char *testData = "Some data";

    //
    // here we run the asserts
    tril_assert_its_false(tril_container_slist_not_empty(mockSList));
    tril_container_slist_push(NULL, testData);
    tril_assert_equal_str(NULL, tril_container_slist_peek(mockSList));
    tril_assert_its_false(tril_container_slist_not_empty(mockSList));
} // end of test case

/*
 >
 > test fixture for current code under the unit
 > testing process.
 >
*/
void fixture_container_slist(UTestRunner *runner)
{
    //
    // setup/teardown functions for the current
    // test fixture.
    //
    tril_utest_set_setup(runner, setup);
    tril_utest_set_teardown(runner, teardown);

    //
    // list of test cases being ran in this
    // project.
    tril_utest_run(runner, test_01_continaer_slist_push_data);
    tril_utest_run(runner, test_02_continaer_slist_push_multable_items);
    tril_utest_run(runner, test_03_continaer_slist_push_nullsafe);
    tril_utest_run(runner, test_04_continaer_slist_pop_data);
    tril_utest_run(runner, test_05_continaer_slist_pop_nullsafe);
    tril_utest_run(runner, test_06_continaer_slist_its_empty);
    tril_utest_run(runner, test_07_continaer_slist_its_empty_nullsafe);
    tril_utest_run(runner, test_08_continaer_slist_not_empty);
    tril_utest_run(runner, test_09_continaer_slist_not_empty_nullsafe);
} // end of fixture
