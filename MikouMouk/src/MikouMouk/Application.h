#pragma once

#include "Core.h"
#include "Window.h"

namespace MikouMouk {
	class MIKOUMOUK_API Application {
	public:
		Application();
		virtual ~Application();

		void run();
	private:
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
	};

	Application* createApplication();
}