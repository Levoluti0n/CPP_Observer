#include "handlers.h"

CameraEventHandler::CameraEventHandler(std::weak_ptr<Camera> c, Handler fptr) : obj{c}, handler{fptr}{
}
void CameraEventHandler::handleEvent(IEvent& event){
    auto ptr = obj.lock();
    if (ptr) {
        ((*ptr).*handler)(event);
    }
}

std::weak_ptr<Camera> Camera::initWeakPtr() {
        return weak_from_this(); 
    }

std::shared_ptr<Camera> Camera::create() {
    std::shared_ptr<Camera> instance(new Camera()); 
    m.subscribe("MouseClickEvent", 
         std::make_shared<CameraEventHandler>(instance->initWeakPtr(), &Camera::onChlp));
    m.subscribe("KeyPressEvent", 
         std::make_shared<CameraEventHandler>(instance->initWeakPtr(), &Camera::onChlp));
        return instance;
}

void Camera::onChlp(IEvent& event) {
    std::cout << "EVENT : " << event.getEventName() << "Handled From Camera!" << std::endl;
}

PlayerEventHandler::PlayerEventHandler(std::weak_ptr<Player> p, Handler fptr) : obj{p}, handler{fptr}{}
void PlayerEventHandler::handleEvent(IEvent& event){
    auto ptr = obj.lock();
    if (ptr) {
        ((*ptr).*handler)(event);
    }
}

Player::Player() {
    m.subscribe("KeyPressEvent", 
        std::make_shared<PlayerEventHandler>(weak_from_this(), &Player::onChlp));
}
void Player::onChlp(IEvent& event) {
    std::cout << "EVENT : " << event.getEventName() << "Handled From Player!" << std::endl;
}