#ifndef TRANSFORMS_H
#define TRANSFORMS_H

#pragma once
#include "PlatformBindings.h"

// Need to take in an input for the currect transform matrix and output one.
void TransformMatrix(m4* transform_matrix, vec3 newTransform);

// Rotate the matrix.
void RotateMaxtrix(m4* rotation_matrix, vec3 Rotation);

// Scales the matrix
void ScaleMatrix(m4* scale_matrix, vec3 scale);

//View = Mul(Rotation(View, cr, (vec3){1.0f, 0.0f, 0.0f}), LookAt((vec3){1, 0, 0}, (vec3){0, 1, 0}, (vec3){0, 0, 1}, crt));
void ViewMatrix(m4* view_matrix, vec3 cam_Pos);

m4 InitialiseObjectTransforms(vec2 position, vec3 scale, vec3 rotation);

#endif
