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

		inline Window& getWindow() { return *m_Window; }

		inline static Application& get() { return *s_Instance; }
	private:
		bool onWindowClosed(WindowCloseEvent& event);

		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
		static Application* s_Instance;
	};

	Application* createApplication();
}