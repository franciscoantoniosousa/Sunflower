#pragma once

#ifdef SF_PLATFORM_WINDOWS

extern Sunflower::Application* Sunflower::CreaterApplication();

int main(int argc, char** argv) {

	Sunflower::Log::Init();
	SF_CORE_WARN("Initialized Core Log!");
	SF_CLIENT_INFO("Initialized Client Log!");

	auto app = Sunflower::CreaterApplication();
	app->Run();
	delete app;
}
#endif // SF_PLATFORM_WINDOWS
