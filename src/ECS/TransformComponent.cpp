#include "TransformComponent.h"

/* void TransformMatrix(m4& transform_matrix, const vec2 newTransform)
{
    // To-Do: Change this so that it is a constant parameter
	extern vec2 display;
	int x = display[0];
	int y = display[1];
	
	vec2 trns = newTransform;

	trns[0] /= x;
	trns[1] /= y;

	transform_matrix.matrix[0][3] = trns[0];
	transform_matrix.matrix[1][3] = trns[1];
}

m4 TransformMatrix(const vec2 newTransform)
{
	m4 transform_matrix = defmatr;

	extern vec2 display;
	int x = display[0];
	int y = display[1];
	
	vec2 trns = newTransform;

	trns[0] /= x;
	trns[1] /= y;

	transform_matrix.matrix[0][3] = trns[0];
	transform_matrix.matrix[1][3] = trns[1];

	return transform_matrix;
}

void RotateMaxtrix(m4* rotation_matrix, vec3 Rotation)
{
	LC_Rotate_X(rotation_matrix, Rotation[0]);
	LC_Rotate_Y(rotation_matrix, Rotation[1]);
	LC_Rotate_Z(rotation_matrix, Rotation[2]);
}

void ScaleMatrix(m4* scale_matrix, vec3 scale)
{
	LC_Scale(scale_matrix, scale);
}

void ViewMatrix(m4* view_matrix, vec3 cam_Pos)
{
	m4 View = defmatr;

	TransformMatrix(View, {cam_Pos[0], cam_Pos[1]});
	LC_SetMatrix(view_matrix, View.matrix);

	//View = Mul(Rotation(View, cr, (vec3){1.0f, 0.0f, 0.0f}), LookAt((vec3){1, 0, 0}, (vec3){0, 1, 0}, (vec3){0, 0, 1}, crt));
} */