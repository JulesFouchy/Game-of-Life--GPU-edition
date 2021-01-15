#pragma once

#include <Cool/OpenGL/SSBO.h>
#include <Cool/OpenGL/ComputeShader.h>

using namespace Cool;

class GameOfLife {
public:
	GameOfLife(unsigned int width, unsigned int height);
	~GameOfLife() = default;

	void update();
	void render();
	void renderToConsole();

private:
	unsigned int m_width;
	unsigned int m_height;
	SSBO<int> m_ssbo0; // We use two SSBOs to write in one of them while we read the other
	SSBO<int> m_ssbo1;
	ComputeShader<16, 16, 1> m_computeShader;
	bool m_bFlipFlop = false;
};