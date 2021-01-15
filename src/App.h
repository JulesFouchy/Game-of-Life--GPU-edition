#pragma once

#include <Cool/App/IApp.h>
#include <Cool/Renderer_Fullscreen/Renderer_Fullscreen.h>

#include "GameOfLife.h"

using namespace Cool;

class App : public Cool::IApp {
public:
	App();
	~App() = default;

	void update() override;
	void ImGuiWindows() override;
	void ImGuiMenus() override;
	void onEvent(const SDL_Event & e) override;

private:
	Renderer_Fullscreen m_renderer;
	GameOfLife m_gameOfLife;

private:
#ifndef NDEBUG
	bool m_bShow_Debug = true;
	bool m_bShow_ImGuiDemo = false;
#endif
};