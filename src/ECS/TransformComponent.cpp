#include "TransformComponent.h"

static m4* matricies;

void initialise(int size)
{
    matricies = (m4*)malloc(sizeof(m4) * size);
    for (int i = 0; i < size; i++)
    {
        matricies[i] = {defmatr};
    }
}

void Transform_Update(TransformComponent* transformComponents, Entity* entities, int size)
{
    int nsize = size;

    for(int i = 0; i < nsize; i++)
    {
        TransformComponent trns = transformComponents[entities[i].ID];
        
        TransformMatrix(&matricies[i], trns.position);
        RotateMaxtrix(&matricies[i], trns.rotation);
        ScaleMatrix(&matricies[i], trns.scale);
        
        extern m4 VP;
        matricies[i] = LC_Mul(matricies[i], VP);
    }
}

m4* getMatricies()
{
    return matricies;
}