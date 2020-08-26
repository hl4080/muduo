add_executable(hl-eventlooptest1 eventlooptest/eventLoopTest1.cc)
target_link_libraries(hl-eventlooptest1 muduo_net)

add_executable(hl-eventlooptest2 eventlooptest/eventLoopTest2.cc)
target_link_libraries(hl-eventlooptest2 muduo_net)

add_executable(hl-reactorSimpleTest reactor/reactorTest.cc)
target_link_libraries(hl-reactorSimpleTest muduo_net)