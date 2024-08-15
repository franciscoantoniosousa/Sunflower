#include <Sunflower.h>

class Sandbox : public Sunflower::Application {
public:
	Sandbox() {

	}

	~Sandbox() {

	}

};

Sunflower::Application* Sunflower::CreaterApplication()
{
	return new Sandbox();
}