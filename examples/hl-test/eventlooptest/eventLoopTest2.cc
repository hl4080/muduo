//
// Created by hl4080 on 2020/8/20.
//
//main thread creates two eventloop objects, the progra will quit abnormally
//

#include "muduo/base/Thread.h"
#include "muduo/net/EventLoop.h"

using namespace muduo;
using namespace muduo::net;

EventLoop* g_loop;

void threadFunc() {
    printf("threadFunc(): pid=%d, tid=%d\n", getpid(), muduo::CurrentThread::tid());
    g_loop->loop();
}

int main() {
    printf("main(): pid = %d, tid = %d\n", getpid(), muduo::CurrentThread::tid());
    EventLoop loop;
    g_loop = &loop;
    muduo::Thread thread(threadFunc);
    thread.start();
    thread.join();
}