#include "application.h"

#include "sunflower/events/application-event.h"
#include "sunflower/log.h"

Sunflower::Application::Application()
{
}

Sunflower::Application::~Application()
{
}

void Sunflower::Application::Run()
{
	WindowResizeEvent e(1280, 720);
	SF_TRACE(e.ToString());

	while (true);
}


