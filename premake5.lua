workspace "Sunflower"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Sunflower"
	location "Sunflower"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/vendor/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++20"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"SF_BUILD_DLL",
			"SF_PLATFORM_WINDOWS"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}
	
	filter "configurations:Debug"
		defines "SF_DEBUG"
		symbols "On"
		
	filter "configurations:Release"
		defines "SF_RELEASE"
		optimize "On"
		
	filter "configurations:Dist"
		defines "SF_DIST"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Sunflower/vendor/spdlog/include",
		"Sunflower/src"
	}

	links
	{
		"Sunflower"
	}

	filter "system:windows"
		cppdialect "C++20"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"SF_PLATFORM_WINDOWS"
		}

		filter "configurations:Debug"
			defines "SF_DEBUG"
			symbols "On"
			
		filter "configurations:Release"
			defines "SF_RELEASE"
			optimize "On"
			
		filter "configurations:Dist"
			defines "SF_DIST"
			optimize "On"