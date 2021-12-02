#include <MikouMouk.h>

class Sandbox : public MikouMouk::Application {
public:
	Sandbox() {

	}

	~Sandbox() {

	}
};

MikouMouk::Application* MikouMouk::createApplication() {
	return new Sandbox();
}