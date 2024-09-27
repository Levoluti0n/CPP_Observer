#ifndef HANDLERS_H
#define HANDLERS_H

#include "events.h"
#include "memory"
#include "emanager.h"
class CameraEventHandler;
class Camera : public std::enable_shared_from_this<Camera>{
    private:
    std::weak_ptr<Camera> weakPtr_;
    public:
        // Camera();
        void onChlp(IEvent&);
        std::weak_ptr<Camera>  initWeakPtr();
        static std::shared_ptr<Camera> create();
};
extern EventManager m;

class CameraEventHandler : public IEventHandler {
    private:
        using Handler = void(Camera::*)(IEvent&);
        std::weak_ptr<Camera> obj;
        Handler handler;
    public:
        CameraEventHandler(std::weak_ptr<Camera>, Handler);
        void handleEvent(IEvent&) override;
};

class Player : public std::enable_shared_from_this<Player>{
    public:
        Player();
        void onChlp(IEvent&);
};

class PlayerEventHandler : public IEventHandler {
    private:
        using Handler = void(Player::*)(IEvent&);
        std::weak_ptr<Player> obj;
        Handler handler;
    public:
        PlayerEventHandler(std::weak_ptr<Player>, Handler);
        void handleEvent(IEvent& event) override;
};

#endif