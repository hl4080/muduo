//
// Created by hl4080 on 2020/8/26.
//
// simple tests testing functionality of acceptor
//

#include "muduo/net/Acceptor.h"
#include "muduo/net/EventLoop.h"
#include "muduo/net/InetAddress.h"
#include "muduo/net/SocketsOps.h"
#include "muduo/base/Logging.h"
#include <ctime>

void simpleCharConnection(int socketfd, const muduo::net::InetAddress& peerAddr) {
    printf("simple char connection(): accepted a new connection from %s\n", peerAddr.toIpPort().c_str());
    ssize_t sz = ::write(socketfd, "How are you?\n", 13);
    if(sz == -1) LOG_FATAL << "No data writen into the socket ";
    muduo::net::sockets::close(socketfd);
}

void dayTimeConnection(int socketfd, const muduo::net::InetAddress& peerAddr) {
    printf("daytime server connection(): accepted a new connection from %s\n", peerAddr.toIpPort().c_str());
    const time_t now = time(0);
    const char* dt = ctime(&now);
    ssize_t sz = ::write(socketfd, dt, 64);
    if(sz == -1) LOG_FATAL << "No data writen into the socket ";
    muduo::net::sockets::close(socketfd);
}

void simpleCharConnection2(int socketfd, const muduo::net::InetAddress& peerAddr) {
    printf("simple char connection2(): accepted a new connection from %s\n", peerAddr.toIpPort().c_str());
    ssize_t sz = ::write(socketfd, "Another connection: How are you, too?\n", 64);
    if(sz == 1) LOG_FATAL << "No data writen into the socket ";
    muduo::net::sockets::close(socketfd);
}

int main() {
    printf("main(): pid = %d\n", getpid());
    muduo::net::InetAddress listenAddr(9981);
    muduo::net::InetAddress listenAddr2(9982);
    muduo::net::EventLoop loop;
    muduo::net::Acceptor acceptor(&loop, listenAddr, false);
    muduo::net::Acceptor acceptor2(&loop, listenAddr2, false);
    acceptor.setNewConnectionCallback(simpleCharConnection);
    //acceptor.setNewConnectionCallback(dayTimeConnection);
    acceptor2.setNewConnectionCallback(simpleCharConnection2);
    acceptor.listen();
    acceptor2.listen();
    loop.loop();
}
