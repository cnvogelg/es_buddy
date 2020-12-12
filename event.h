#ifndef EVENT_H
#define EVENT_H

#include <Encoder.h>
#include <Bounce.h>

enum class EventType {
    INC_VALUE,
    DEC_VALUE,
    BUTTON_DOWN,
    BUTTON_UP,
    BUTTON_LONG_PRESS
};

struct Event {
    EventType  type;
    int        value;
};

class EventSource {
public:
    virtual bool pollEvent(Event &e) = 0;
};

#endif
