#version 430 core

in vec2 vTexCoords;

uniform bool u_bFlipFlop;

uniform vec2 u_resolution;
uniform int u_resolutionX;

layout(std430, binding=0) buffer myBuffer0 {
   int data0[];
};

layout(std430, binding=1) buffer myBuffer1 {
   int data1[];
};

void main() {
    ivec2 gid = ivec2(floor(vTexCoords * u_resolution));
    int isAlive = u_bFlipFlop ? data0[gid.x + gid.y * u_resolutionX] : data1[gid.x + gid.y * u_resolutionX];
    if (isAlive == 1) {
        gl_FragColor = vec4(1., 1., 1., 1.);
    }
    else {
        gl_FragColor = vec4(0., 0., 0., 1.);
    }
}