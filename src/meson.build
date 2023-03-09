trilo_src = files(
    'stack.c', 'slist.c', 'dlist.c',
    'queue.c', 'dqueue.c')

trilo_lib = static_library('trilo-container-c',
    trilo_src,
    include_directories: inc_dir)

trilo_container_dep = declare_dependency(link_with: trilo_lib,
    include_directories: inc_dir)
