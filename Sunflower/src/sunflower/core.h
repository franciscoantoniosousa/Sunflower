#pragma once



#ifdef SF_PLATFORM_WINDOWS
	#ifdef SF_BUILD_DLL
		#define SUNFLOWER_API __declspec(dllexport)
	#else
		#define SUNFLOWER_API __declspec(dllimport)	
	#endif // SF_BUILD_DLL
#else
	#error Sunflower only supports windows!
#endif // SF_PLATFORM_WINDOWS
