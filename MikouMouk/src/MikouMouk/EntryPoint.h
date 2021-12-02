#pragma once

#ifdef MK_PLATFORM_WINDOWS

extern MikouMouk::Application* MikouMouk::createApplication();

int main(int argc, char** argv) {
	MikouMouk::Log::init();
	MK_CORE_WARN("Initialized Log!");
	MK_INFO("Hello!");

	auto app = MikouMouk::createApplication();
	app->run();
	delete app;
}

#endif