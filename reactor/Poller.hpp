#ifndef __POLLER_HPP__
#define __POLLER_HPP__

#include "EventLoop.hpp"

class Channel;


class Poller
{
public:
    Poller();
    virtual ~Poller();
    void updateChannel(Channel* channel);

private:
    typedef std::map<int, Channel*> ChannelMap;

    ChannelMap channels_;
};

#endif /* __POLLER_HPP__ */
