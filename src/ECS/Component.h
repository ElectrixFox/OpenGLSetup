#ifndef COMPONENT_H
#define COMPONENT_H

#pragma once
#include "PlatformBindings.h"
#include "RenderComponent.h"

#define SIZE 10

enum C_Type
{
    C_Render = sizeof(RenderComponent),

};

union size
{
    int size; 
    enum C_Type type; 
};

struct Component
{
    void* data;
    union { int size; enum C_Type type; } size;
};

template<typename T>
inline T convert(struct Component comp)
{
    T n_t;
    memcpy(&n_t, comp.data, comp.size.type);

    return n_t;
};

struct ComponentList
{
    struct Component* components[SIZE];
};

#undef SIZE



#endif