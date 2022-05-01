#ifndef CAMERA_H
#define CAMERA_H

#pragma once
#include "PlatformBindings.h"

void Camera(m4* cam, vec3 position);
void UpdateCamera();

void TransformCamera(vec3 position);
void TranslateCamera(vec3 translation);

void initMatricies();
#endif


#ifndef FRAME_BUFFER_OBJECT
#define FRAME_BUFFER_OBJECT

#pragma once
#include "Shader.h"
#include "Texture.h"
#include "VertexBuffer.h"
#include "VertexArray.h"
#include "IndexBuffer.h"

#include "Framebuffer.h"

typedef struct
{
    unsigned char fbo;
    unsigned char vao;
    unsigned char shader;
    unsigned char screen_texture;

} FrameBufferObject;

FrameBufferObject initFrameBuffer();
void DrawFBO(unsigned char vao, unsigned char shader, unsigned char screen_texture);

#endif
