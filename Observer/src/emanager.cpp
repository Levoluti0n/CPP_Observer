#include "emanager.h"

void EventManager::subscribe(std::string event_name, std::shared_ptr<IEventHandler> handler) {

    std::cout<< event_name << " Added" << std::endl;
    if (_subscribers.find(event_name) == _subscribers.end()) {
        _subscribers[event_name] = std::vector<std::shared_ptr<IEventHandler>> {handler};
        return;
    }
    _subscribers[event_name].push_back(handler);
}

void EventManager::addEvent(std::unique_ptr<IEvent> event) {
    if(!event) 
        return;
    _eventQueue.push_back(std::move(event));
}

void EventManager::dispatchEvents(){
    for(auto &e : _eventQueue) {
        for(auto &f : _subscribers[e->getEventName()]) {
            f->handleEvent(*e);
        }
    }
    _eventQueue.clear();
}