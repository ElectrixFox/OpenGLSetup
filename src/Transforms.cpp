#include "Transforms.h"

vec2* Transforms;

struct Queue
{
    int Head;
    int Tail;
    int size;
};

static struct Queue trns;

void InitTransforms()
{
    Transforms = (vec2*)malloc(sizeof(vec2) * 128);

    trns.Tail = 0;
    trns.Head = -1;
    trns.size = 0;
}

void PushBack(vec2 Transform)
{
    Transforms = (vec2*)realloc(Transforms, sizeof(vec3) * (trns.size + 1));
    trns.size++;

    if(trns.Tail == trns.size) trns.Head = 0; 

    memcpy(Transforms[trns.Tail], Transform, sizeof(vec2));
    trns.Tail = (trns.Tail + 1) % trns.size;
}

float* PopOff()
{
    if(trns.Head == trns.size) trns.Head = 0;

    float* transform = (float*)malloc(sizeof(float) * 3);
    memcpy(transform, Transforms[trns.Head], sizeof(vec2));
    trns.Head = (trns.Head + 1) % trns.size;

    transform[2] = 1.0f;

    return transform;
}

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

void ViewMatrix(m4* view_matrix, vec3 cam_Pos)
{
	m4 View = M4_Identity();

	TransformMatrix(&View, cam_Pos);
	SetMatrix(view_matrix, View.matrix);

	//View = Mul(Rotation(View, cr, (vec3){1.0f, 0.0f, 0.0f}), LookAt((vec3){1, 0, 0}, (vec3){0, 1, 0}, (vec3){0, 0, 1}, crt));
}

m4 InitialiseObjectTransforms(vec2 position, vec3 scale, vec3 rotation)
{
	m4 model = M4_Identity();

	vec3 v = {position[0], position[1], 0};
	TransformMatrix(&model, v);
	RotateMaxtrix(&model, rotation);
	ScaleMatrix(&model, scale);

	return model;
}
