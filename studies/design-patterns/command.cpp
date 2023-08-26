
#include <iostream>
#include <vector>
/* Command example */

class Command
{
public:
    virtual ~Command() {}
    virtual void execute(GameActor &actor) = 0;
};

class JumpCommand : public Command
{
public:
    virtual void execute(GameActor &actor)
    {
        actor.jump();
    }
};
Command *InputHandler::handleInput()
{
    if (isPressed(BUTTON_X))
        return buttonX_;
    if (isPressed(BUTTON_Y))
        return buttonY_;
    if (isPressed(BUTTON_A))
        return buttonA_;
    if (isPressed(BUTTON_B))
        return buttonB_;
    // Nothing pressed, so do nothing.
    return NULL;
};