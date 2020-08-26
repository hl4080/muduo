//
// Created by hl4080 on 2020/8/26.
//
//test eventLoopThread and multithread call for runInLoop and runAfter
//

#include "muduo/net/EventLoop.h"
#include "muduo/net/EventLoopThread.h"

void runInThread()
{
    printf("runInThread(): pid = %d, tid = %d\n",
           getpid(), muduo::CurrentThread::tid());
}

int main()
{
    printf("main(): pid = %d, tid = %d\n",
           getpid(), muduo::CurrentThread::tid());

    muduo::net::EventLoopThread loopThread;
    muduo::net::EventLoop* loop = loopThread.startLoop();
    loop->runInLoop(runInThread);
    sleep(1);
    loop->runAfter(2, runInThread);
    sleep(3);
    loop->quit();

    printf("exit main().\n");
}