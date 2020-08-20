//
// Created by hl4080 on 2020/8/20.
//
//main thread and child thread creats a eventloop object respectively, they are supposed to quit normally
//

#include "muduo/base/Thread.h"
#include "muduo/net/EventLoop.h"

using namespace muduo;
using namespace muduo::net;

void threadFunc() {
    printf("threadFunc(): pid = %d, tid = %d\n", getpid(), muduo::CurrentThread::tid());
    EventLoop loop;
    loop.loop();
}

int main() {
    printf("main(): pid = %d, tid = %d\n", getpid(), muduo::CurrentThread::tid());
    EventLoop loop;
    muduo::Thread thread(threadFunc);
    thread.start();

    loop.loop();
    pthread_exit(NULL);
}
