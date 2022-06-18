#ifndef TRANSFORM_COMPONENT_H
#define TRANSFORM_COMPONENT_H

#pragma once
#include "Component.h"

// Change the transform of the component
void Transform_Object(Entity& entity, vec2 position);

// Need to take in an input for the currect transform matrix and output 
void TransformMatrix(m4& transform_matrix, const vec2 newTransform);

// Rotate the matrix.
void RotateMaxtrix(m4* rotation_matrix, vec3 Rotation);

// Scales the matrix
void ScaleMatrix(m4* scale_matrix, vec3 scale);

//View = Mul(Rotation(View, cr, (vec3){1.0f, 0.0f, 0.0f}), LookAt((vec3)
void ViewMatrix(m4* view_matrix, vec3 cam_Pos);

#endif