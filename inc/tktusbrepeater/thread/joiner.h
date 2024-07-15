#ifndef TKTUSBREPEATER_THREAD_JOINER_H
#define TKTUSBREPEATER_THREAD_JOINER_H

#include <thread>
#include <memory>

struct JoinThread
{
    void operator()(
        std::thread *
    ) const;
};

using ThreadJoiner = std::unique_ptr<
    std::thread
    , JoinThread
>;

#endif  // TKTUSBREPEATER_THREAD_JOINER_H
