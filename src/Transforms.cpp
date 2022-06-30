#include "Transforms.h"

// To-Do: Change all of these so that they come straight from here and not the maths library.
void TransformMatrix(m4& transform_matrix, const vec2 newTransform)
{
	// Gets the vec2 from the main.c file which has the display size on it.
	extern vec2 display;
	int x = display[0];
	int y = display[1];
	
	vec2 trns = newTransform;

	trns[0] /= x;
	trns[1] /= y;

	transform_matrix.matrix[0][3] = trns[0];
	transform_matrix.matrix[1][3] = trns[1];
}

void TransformMatrix(m4* transform_matrix, const vec2 newTransform)
{
	// Gets the vec2 from the main.c file which has the display size on it.
	extern vec2 display;
	int x = display[0];
	int y = display[1];
	
	vec2 trns = newTransform;

	trns[0] /= x;
	trns[1] /= y;

	transform_matrix->matrix[0][3] = trns[0];
	transform_matrix->matrix[1][3] = trns[1];
}

m4 TransformMatrix(const vec2 newTransform)
{
	m4 transform_matrix = LC_M4_Identity();

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

m4 RotateMaxtrix(vec3 Rotation)
{
	m4 rotation_matrix = LC_M4_Identity();

	LC_Rotate_X(&rotation_matrix, Rotation[0]);
	LC_Rotate_Y(&rotation_matrix, Rotation[1]);
	LC_Rotate_Z(&rotation_matrix, Rotation[2]);

	return rotation_matrix;
}

void ScaleMatrix(m4* scale_matrix, vec3 scale)
{
	LC_Scale(scale_matrix, scale);
}

void ScaleMatrix(m4* scale_matrix, vec2 scale)
{
	vec3 v = { scale.x, scale.y, 1 };
	LC_Scale(scale_matrix, v);
}

m4 ScaleMatrix(vec2 scale)
{	
	m4 transform_matrix = LC_M4_Identity();
	vec3 v = { scale.x, scale.y, 1 };
	LC_Scale(&transform_matrix, v);

	return transform_matrix;
}

void ViewMatrix(m4* view_matrix, vec3 cam_Pos)
{
	m4 View = LC_M4_Identity();

	TransformMatrix(View, {cam_Pos[0], cam_Pos[1]});
	LC_SetMatrix(view_matrix, View.matrix);

	//View = Mul(Rotation(View, cr, (vec3){1.0f, 0.0f, 0.0f}), LookAt((vec3){1, 0, 0}, (vec3){0, 1, 0}, (vec3){0, 0, 1}, crt));
}