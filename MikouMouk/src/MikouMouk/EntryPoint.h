#pragma once

#ifdef MK_PLATFORM_WINDOWS

extern MikouMouk::Application* MikouMouk::createApplication();

int main(int argc, char** argv) {
	MikouMouk::Log::init();

	auto app = MikouMouk::createApplication();
	app->run();
	delete app;
}

#endif