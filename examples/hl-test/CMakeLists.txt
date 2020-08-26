add_executable(hl-eventlooptest1 eventlooptest/eventLoopTest1.cc)
target_link_libraries(hl-eventlooptest1 muduo_net)

add_executable(hl-eventlooptest2 eventlooptest/eventLoopTest2.cc)
target_link_libraries(hl-eventlooptest2 muduo_net)

add_executable(hl-eventlooptest3 eventlooptest/eventLoopTest3.cc)
target_link_libraries(hl-eventlooptest3 muduo_net)

add_executable(hl-reactorSimpleTest reactor/reactorTest.cc)
target_link_libraries(hl-reactorSimpleTest muduo_net)

add_executable(hl-acceptTest Accept/acceptTest.cc)
target_link_libraries(hl-acceptTest muduo_net)