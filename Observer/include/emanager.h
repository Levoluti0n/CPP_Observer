#ifndef EMANAGER_H
#define EMANAGER_H
#include <string>
#include <vector>
#include <memory>
#include "events.h"
#include <unordered_map>

class EventManager {
    private:
        std::unordered_map<std::string, std::vector<std::shared_ptr<IEventHandler>>> _subscribers;
        std::vector<std::unique_ptr<IEvent>> _eventQueue;
    public:
        void subscribe(std::string, std::shared_ptr<IEventHandler>); 
        void addEvent(std::unique_ptr<IEvent>);
        void dispatchEvents();      
};

#endif