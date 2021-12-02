#pragma once

#include "Core.h"

namespace MikouMouk {
	class MIKOUMOUK_API Application {
	public:
		Application();
		virtual ~Application();

		void run();
	};

	Application* createApplication();
}