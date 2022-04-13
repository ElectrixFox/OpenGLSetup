#include "Transforms.h"

// To-Do: Change all of these so that they come straight from here and not the maths library.
void TransformMatrix(m4* transform_matrix, vec3 newTransform)
{
	// Gets the vec2 from the main.c file which has the display size on it.
	extern vec2 display;
	int x = display[0], y = display[1];

	newTransform[0] /= x;
	newTransform[1] /= y;

	transform_matrix->matrix[0][3] = newTransform[0];
	transform_matrix->matrix[1][3] = newTransform[1];
}

void RotateMaxtrix(m4* rotation_matrix, vec3 Rotation)
{
	Rotate_X(rotation_matrix, Rotation[0]);
	Rotate_Y(rotation_matrix, Rotation[1]);
	Rotate_Z(rotation_matrix, Rotation[2]);
}

void ScaleMatrix(m4* scale_matrix, vec3 scale)
{
	Scale(scale_matrix, scale);
}
