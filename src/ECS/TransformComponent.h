#ifndef TRANSFORMCOMPONENT_H
#define TRANSFORMCOMPONENT_H

#pragma once
#include "PlatformBindings.h"
#include "LCMaths.h"

#include "ecs.h"
#include "src/Transforms.h"

#define defmatr \
    { \
        { 1.0f, 0.0f, 0.0f, 0.0f }, \
        { 0.0f, 1.0f, 0.0f, 0.0f }, \
        { 0.0f, 0.0f, 1.0f, 0.0f }, \
        { 0.0f, 0.0f, 0.0f, 1.0f } \
    }

struct TransformComponent
{
    vec2 position;
    vec2 scale;
    vec3 rotation;
};
typedef struct TransformComponent TransformComponent;

inline void Transform(World* world, Entity entity, vec2 position) 
{ 
    get<TransformComponent>(world, entity, Types::T_Transform)->position = position; 
};

inline void Scale(World* world, Entity entity, vec2 scale) 
{ 
    get<TransformComponent>(world, entity, Types::T_Transform)->scale = scale; 
};

inline void Rotate(World* world, Entity entity, vec3 rotation) 
{ 
    get<TransformComponent>(world, entity, Types::T_Transform)->rotation = rotation; 
};

void initialise(int size = 128);
void Transform_Update(TransformComponent* transformComponents, Entity* entities, int size = 128);
m4* getMatricies();

#endif