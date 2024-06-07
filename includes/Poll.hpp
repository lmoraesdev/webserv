#ifndef Poll_HPP
#define Poll_HPP

#include "./Libs.hpp"

class Poll
{
    private:
        std::vector<int>           _sockets;
        std::vector<struct pollfd> _pollFds;
        std::vector<int>           _fdToClose;

    public:
        Poll(void);
        ~Poll(void);

        void    init(int fd);
        int     execute(void);
        bool    waitMatch(size_t i);
        int     getPollFd(size_t i) const;
        bool    isRead(size_t i) const;
        size_t  getSize(void) const;
        void    addPoll(int socketFd, short events);
        bool    isSocketServer(size_t i);

        void    addFdToClose(int fd);
        void    removeMarkedElements(void);

        //void closePoll(void);

        void    removeListeningSocket(int fd);
        void    removePollFd(int fd);

        //int    getListeningSocket(size_t i) const;
};

#endif
