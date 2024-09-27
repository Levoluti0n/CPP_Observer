#ifndef CONCRETE_H
#define CONCRETE_H

#include "events.h"
#include <typeinfo>

#define EVENT_TYPE(type) \
    std::string getEventName() const override {\
        return #type;\
    }\

class MouseClickEvent:public IEvent {
    public:
        MouseClickEvent() = default;
        EVENT_TYPE(MouseClickEvent);
};
class KeyPressEvent:public IEvent {
    public:
        EVENT_TYPE(KeyPressEvent);
};

#endif