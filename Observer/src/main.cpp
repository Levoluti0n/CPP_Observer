#include "main.h"

EventManager m;
int main() {
    std::shared_ptr<Camera> myObject = Camera::create();
    std::unique_ptr<IEvent> e = std::make_unique<MouseClickEvent>();
    std::unique_ptr<IEvent> k = std::make_unique<KeyPressEvent>();
    m.addEvent(std::move(e));
    m.addEvent(std::move(k));
    m.dispatchEvents();

    return 0;
}