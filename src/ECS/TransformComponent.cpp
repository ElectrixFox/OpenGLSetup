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
        ScaleMatrix(&matricies[i], trns.scale);
        RotateMaxtrix(&matricies[i], trns.rotation);
        
        extern m4 VP;
        matricies[i] = LC_Mul(matricies[i], VP);


    }

    static int x = 0;

    if(x < 10)
    {
        for(int i = 0; i < nsize; i++)
        {
            std::cout << '\n';
            LC_LogM4(matricies[i]);

        }

        std::cout << '\n' << "================================================" << '\n';
    }
    x++;
}

m4* getMatricies()
{
    return matricies;
}