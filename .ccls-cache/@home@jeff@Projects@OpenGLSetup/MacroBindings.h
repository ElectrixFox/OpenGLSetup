#ifndef MACROBINDINGS_H
#define MACROBINDINGS_H

// Some macros to make it a little easier to start the main loop.
#define START_MAIN_LOOP while(!glfwWindowShouldClose(window)) {
#define END_MAIN_LOOP Render(window, mM, rM); }

#define addObject(obj) AddMesh(obj, &mM);
#endif
