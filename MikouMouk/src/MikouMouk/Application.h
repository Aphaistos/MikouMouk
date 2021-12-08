#pragma once

#include "Core.h"
#include "MikouMouk/Events/Event.h"
#include "MikouMouk/Events/ApplicationEvent.h"

#include "Window.h"

namespace MikouMouk {
	class MIKOUMOUK_API Application {
	public:
		Application();
		virtual ~Application();

		void run();

		void onEvent(Event& e);
	private:
		bool onWindowClosed(WindowCloseEvent& event);

		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
	};

	Application* createApplication();
}