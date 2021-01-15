#include "GameOfLife.h"

#include <Cool/Random/Random.h>

#include <iostream>

GameOfLife::GameOfLife(unsigned int width, unsigned int height)
	: m_width(width), m_height(height), m_ssbo0(0), m_ssbo1(1), m_computeShader("shaders/GameOfLife.comp")
{
	std::vector<int> v;
	size_t N = width * height;
	v.reserve(N);
	for (size_t i = 0; i < N; ++i) {
		//v.push_back(Random::get0to1() < 0.5 ? 0 : 1);
		v.push_back(i % 3 == 1 ? 1 : 0);
	}
	m_ssbo0.uploadData(v);
	m_ssbo1.uploadData(v);
}

void GameOfLife::update() {
	m_bFlipFlop = !m_bFlipFlop;
	m_computeShader.get().bind();
	m_computeShader.get().setUniform1i("u_bFlipFlop", m_bFlipFlop);
	m_computeShader.compute(m_width, m_height);
}

void GameOfLife::renderToConsole() {
	std::cout << "----------------------------------------------" << std::endl;
	std::vector<int> v;
	size_t N = m_width * m_height;
	v.resize(N);
	if (m_bFlipFlop)
		m_ssbo0.downloadData(v);
	else
		m_ssbo1.downloadData(v);
	for (unsigned int y = 0; y < m_height; ++y) {
		for (unsigned int x = 0; x < m_width; ++x) {
			std::cout << v[x + y * m_width] << " ";
		}
		std::cout << std::endl;
	}
}

void GameOfLife::render() {

}