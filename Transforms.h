#ifndef TRANSFORMS_H
#define TRANSFORMS_H

#pragma once
#include "Include/LCMaths/LCMaths.h"

// Need to take in an input for the currect transform matrix and output one.
void TransformMatrix(m4* transform_matrix, vec3 newTransform);

#endif
