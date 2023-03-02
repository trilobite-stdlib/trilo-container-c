if get_option('with_tests').enabled()
    trilo_utest_dep = dependency('trilo-utest-c')

    test_exe = executable('dummy',
        'test_cases.c', 'test_container_dlist.c',
        'test_container_slist.c', 'test_container_dqueue.c',
        'test_container_queue.c', 'test_container_stack.c',
        dependencies : [trilo_utest_dep, trilo_container_dep])

    test('Execute project tests', test_exe)
endif
