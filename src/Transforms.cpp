#include "Transforms.h"

vec2* Transforms;

struct Queue
{
	int bottom;
    int current;
    int size;
};

static struct Queue trns;

void InitTransforms()
{
    Transforms = (vec2*)malloc(sizeof(vec2) * 128);

	trns.current = 0;
    trns.size = 0;
	trns.bottom = 0;
}

void PushBack(vec2 Transform)
{
    trns.size++;
    Transforms = (vec2*)realloc(Transforms, sizeof(vec2) * (trns.size + 1));

    Transforms[trns.current++] = Transform;
}

vec2& PopOff()
{
    vec2& transform = Transforms[trns.bottom];
	trns.bottom = (trns.bottom + 1) % trns.size;

    return transform;
}

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

void ViewMatrix(m4* view_matrix, vec3 cam_Pos)
{
	m4 View = M4_Identity();

	TransformMatrix(View, {cam_Pos[0], cam_Pos[1]});
	SetMatrix(view_matrix, View.matrix);

	//View = Mul(Rotation(View, cr, (vec3){1.0f, 0.0f, 0.0f}), LookAt((vec3){1, 0, 0}, (vec3){0, 1, 0}, (vec3){0, 0, 1}, crt));
}

m4 InitialiseObjectTransforms(vec2 position, vec3 scale, vec3 rotation)
{
	m4 model = M4_Identity();

	TransformMatrix(model, position);
	RotateMaxtrix(&model, rotation);
	ScaleMatrix(&model, scale);

	return model;
}
