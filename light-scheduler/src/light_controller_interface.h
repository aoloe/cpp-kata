#ifndef LIGHT_CONTROLLER_INTERFACE_INCLUDED
#define LIGHT_CONTROLLER_INTERFACE_INCLUDED

#include <cstdint>

class ILightController
{
public:
    virtual ~ILightController() = default;
    virtual void turn_on(uint32_t id) = 0;
    virtual void turn_off(uint32_t id) = 0;
};

#endif
