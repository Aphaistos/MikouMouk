#pragma once

#include "MikouMouk/Window.h"

#include "GLFW/glfw3.h"

namespace MikouMouk {
	class WindowsWindow : public Window {
	public:
		WindowsWindow(const WindowProperties& props);
		virtual ~WindowsWindow();

		void onUpdate() override;

		unsigned int getWidth() const override { return m_Data.width; }
		unsigned int getHeight() const override { return m_Data.height; }

		// Window Attributes
		void setEventCallback(const EventCallbackFn& callback) override { m_Data.eventCallback = callback; }
		void setVSync(bool enabled) override;
		bool isVSync() const override;
	private:
		virtual void init(const WindowProperties& props);
		virtual void shutdown();
	private:
		GLFWwindow* m_Window;

		struct WindowData {
			std::string title;
			unsigned int width, height;
			bool vSync;

			EventCallbackFn eventCallback;
		};

		WindowData m_Data;
	};
}