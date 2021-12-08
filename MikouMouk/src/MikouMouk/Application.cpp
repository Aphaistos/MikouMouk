#include "mkpch.h"
#include "Application.h"
 
#include <glad/glad.h>

#include "MikouMouk/Input.h"

namespace MikouMouk {

#define BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1)

	Application* Application::s_Instance = nullptr;

	Application::Application() {
		MK_CORE_ASSERT(!s_Instance, "Application already exists!");
		s_Instance = this;

		m_Window = std::unique_ptr<Window>(Window::create());
		m_Window->setEventCallback(BIND_EVENT_FN(onEvent));
	}

	Application::~Application() {

	}

	void Application::onEvent(Event& event) {
		EventDispatcher dispatcher(event);
		dispatcher.dispatch<WindowCloseEvent>(BIND_EVENT_FN(onWindowClosed));

		MK_CORE_TRACE("{0}", event);
	}


	void Application::run() {

		while (m_Running) {
			glClearColor(0, 1, 0, 1);
			glClear(GL_COLOR_BUFFER_BIT);

			auto[x, y] = Input::getMousePos();
			MK_CORE_TRACE("{0}, {1}", x, y);

			m_Window->onUpdate();
		}
	}

	bool Application::onWindowClosed(WindowCloseEvent& event) {
		m_Running = false;
		return true;
	}
}