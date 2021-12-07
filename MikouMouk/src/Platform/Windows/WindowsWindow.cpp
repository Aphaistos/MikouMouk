#include "mkpch.h"
#include "Platform/Windows/WindowsWindow.h"



namespace MikouMouk {

	static bool s_GLFWInitialzed = false;

	Window* Window::create(const WindowProperties& props) {
		return new WindowsWindow(props);
	}

	WindowsWindow::WindowsWindow(const WindowProperties& props) {
		init(props);
	}

	WindowsWindow::~WindowsWindow() {
		shutdown();
	}

	void WindowsWindow::init(const WindowProperties& props) {
		m_Data.title = props.title;
		m_Data.width = props.width;
		m_Data.height = props.height;

		MK_CORE_INFO("Creating Window {0} ({1}, {2})", props.title, props.width, props.height);

		if (!s_GLFWInitialzed) {
			int succes = glfwInit();
			MK_CORE_ASSERT("succes", "Could not initialize GLFW!");

			s_GLFWInitialzed = true;
		}

		m_Window = glfwCreateWindow((int)props.width, (int)props.height, m_Data.title.c_str(), nullptr, nullptr);
		glfwMakeContextCurrent(m_Window);
		glfwSetWindowUserPointer(m_Window, &m_Data);
		setVSync(true);
	}

	void WindowsWindow::shutdown() {
		glfwDestroyWindow(m_Window);
	}

	void WindowsWindow::onUpdate() {
		glfwPollEvents();
		glfwSwapBuffers(m_Window);
	}

	void WindowsWindow::setVSync(bool enabled) {
		if (enabled)
			glfwSwapInterval(1);
		else
			glfwSwapInterval(0);

		m_Data.vSync = enabled;
	}

	bool WindowsWindow::isVSync() const {
		return m_Data.vSync;
	}

}