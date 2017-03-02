#ifndef __EVENTLOOP_HPP__
#define __EVENTLOOP_HPP__

class EventLoop;
class Poller;

class EventLoop
{
public:
    EventLoop();
    ~EventLoop();
    void loop();
    void updateChannel(Channel* channel);

private:
    typedef std::vector<Channel*> ChannelList;

    ChannelList activeChannels_;
    Channel* currentActiveChannel_;
};


#endif /* __EVENTLOOP_HPP__ */
