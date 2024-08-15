#pragma once

#ifdef SF_PLATFORM_WINDOWS

extern Sunflower::Application* Sunflower::CreaterApplication();

int main(int argc, char** argv) {

	printf("Welcome to Sunflower Engine!");

	auto app = Sunflower::CreaterApplication();
	app->Run();
	delete app;
}
#endif // SF_PLATFORM_WINDOWS
