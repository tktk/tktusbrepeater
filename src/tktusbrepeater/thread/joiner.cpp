#include "tktusbrepeater/thread/joiner.h"
#include <thread>

void JoinThread::operator()(
    std::thread *   _threadPtr
) const
{
    _threadPtr->join();
}
