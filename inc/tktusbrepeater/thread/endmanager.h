#ifndef TKTUSBREPEATER_THREAD_ENDMANAGER_H
#define TKTUSBREPEATER_THREAD_ENDMANAGER_H

#include <mutex>

class EndManager
{
    bool        ended;
    std::mutex  mutex;

public:
    EndManager(
    );

    bool isEnd(
    );

    void end(
    );
};

#endif  // TKTUSBREPEATER_THREAD_ENDMANAGER_H
