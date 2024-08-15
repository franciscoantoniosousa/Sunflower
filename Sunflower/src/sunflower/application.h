#pragma once

#include "core.h"

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

