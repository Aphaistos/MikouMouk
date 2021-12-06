#include "Application.h"

#include "Events/Event.h"
#include "Events/ApplicationEvent.h"
#include "Log.h"

namespace MikouMouk {
	Application::Application() {

	}

	Application::~Application() {

	}

	void Application::run() {
		WindowResizeEvent e(1280, 720);
		if (e.isInCategory(EventCategoryApplication)) {
			MK_TRACE(e);
		}
		if (e.isInCategory(EventCategoryInput)) {
			MK_TRACE(e);
		}

		while (true);
	}
}