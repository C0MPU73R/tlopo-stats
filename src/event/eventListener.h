#ifndef EVENT_LISTENER_H
#define EVENT_LISTENER_H

#include "eventManager.h"

class EventListener 
{
    protected:
        void listen(const std::string& event_type, const event_callback_t& callback);
        void disconnect();
};
#endif // !EVENT_LISTENER_H

