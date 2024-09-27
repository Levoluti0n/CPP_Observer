#ifndef EVENTS_H
#define EVENTS_H

#include <iostream>
#include <string>

class IEvent {
    public:
        virtual std::string getEventName() const = 0;
        virtual ~IEvent() = default;
};

class IEventHandler {
    public:
        virtual void handleEvent(IEvent& event) = 0;
        virtual ~IEventHandler() = default;
};

#endif