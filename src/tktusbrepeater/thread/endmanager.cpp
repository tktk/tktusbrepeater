#include "tktusbrepeater/thread/endmanager.h"
#include <mutex>

EndManager::EndManager(
)
    : ended( false )
{
}

bool EndManager::isEnd(
)
{
    auto    lock = std::unique_lock( this->mutex );

    return this->ended;
}

void EndManager::end(
)
{
    auto    lock = std::unique_lock( this->mutex );

    this->ended = true;
}
