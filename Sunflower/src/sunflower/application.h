#pragma once

#include "core.h"
#include "events/event.h"

namespace Sunflower {

	class SUNFLOWER_API Application
	{
	public:

		Application();
		virtual ~Application();

		void Run();
	};

	Application* CreaterApplication();
	
}

