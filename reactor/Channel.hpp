#ifndef __CHANNEL_HPP__
#define __CHANNEL_HPP__


class EventLoop;


class Channel
{
public:
    typedef function<void()> EventCallback;

    Channel(EventLoop* loop, int fd);
    ~Channel();
    void setReadCallback();
    void setWriteCallback();
    void setErrorCallback();
    void enableReading();
    void enableWriting();


private:
    void update();

private:
    EventLoop* loop_;
    const int fd_;
};

#endif /* __CHANNEL_HPP__ */
