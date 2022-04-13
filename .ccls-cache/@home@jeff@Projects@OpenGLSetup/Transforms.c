#include "Transforms.h"

void TransformMatrix(m4* transform_matrix, vec3 newTransform)
{
	extern vec2 display;
	int x = display[0], y = display[1];

	newTransform[0] /= x;
	newTransform[1] /= y;

	Transform(transform_matrix, newTransform);

//	*transform_matrix = ;
}
