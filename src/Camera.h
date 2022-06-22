#ifndef CAMERA_H
#define CAMERA_H

#pragma once
#include "PlatformBindings.h"
#include "Transforms.h"

void Camera(m4* cam, vec3 position);
void UpdateCamera();

void TransformCamera(vec3 position);
void TranslateCamera(vec3 translation);

void initMatricies();
#endif


#ifndef FRAME_BUFFER_OBJECT
#define FRAME_BUFFER_OBJECT

#pragma once
#include "Rendering/Shader.h"
#include "Rendering/Texture.h"
#include "Rendering/VertexBuffer.h"
#include "Rendering/VertexArray.h"
#include "Rendering/IndexBuffer.h"

#include "Rendering/Framebuffer.h"

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
