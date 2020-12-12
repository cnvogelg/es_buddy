#include <Arduino.h>
#include "stage.h"

void Stage::handle() 
{
    Event e;
    if(_eventSource.pollEvent(e)) {
        _active_scene->handleEvent(e);
    }

    _renderer.renderScene(_active_scene);
}
