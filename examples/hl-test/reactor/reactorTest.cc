//
// Created by hl4080 on 2020/8/26.
//
// single test for primary reactor
//

#include <sys/timerfd.h>
#include <muduo/net/Channel.h>
#include "muduo/net/EventLoop.h"

using namespace muduo;
using namespace muduo::net;

EventLoop* g_loop;

void timeout(Timestamp t) {
    printf("Timeout!\n");
    g_loop->quit();
}

int main() {
    EventLoop loop;
    g_loop = &loop;
    int timerfd = ::timerfd_create(CLOCK_MONOTONIC, TFD_NONBLOCK | TFD_CLOEXEC);
    Channel channel(&loop, timerfd);
    channel.setReadCallback(timeout);
    channel.enableReading();
    struct itimerspec howlong;
    bzero(&howlong, sizeof howlong);
    howlong.it_value.tv_sec = 5;
    ::timerfd_settime(timerfd, 0, &howlong, NULL);
    loop.loop();
    ::close(timerfd);
}
