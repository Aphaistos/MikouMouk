workspace "MikouMouk"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}
IncludeDir["GLFW"] = "MikouMouk/vendor/GLFW/include"
IncludeDir["Glad"] = "MikouMouk/vendor/Glad/include"

include "MikouMouk/vendor/GLFW"
include "MikouMouk/vendor/Glad"

project "MikouMouk"
	location "MikouMouk"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "mkpch.h"
	pchsource "MikouMouk/src/mkpch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}"
	}

	links
	{
		"GLFW",
		"GLAD",
		"opengl32.lib"
	}

	filter = "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"MK_PLATFORM_WINDOWS",
			"MK_BUILD_DLL",
			"GLFW_INCLUDE_NONE"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}
	
	filter = "configurations:Debug"
		defines "MK_DEBUG"
		symbols "On"

	filter = "configurations:Release"
		defines "MK_RELEASE"
		optimize "On"

	filter = "configurations:Dist"
		defines "MK_DIST"
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
		"%{prj.name}/src/**.cpp",
	}

	includedirs
	{
		"MikouMouk/src",
		"MikouMouk/vendor/spdlog/include"
	}

	links
	{
		"MikouMouk"
	}

	filter = "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"MK_PLATFORM_WINDOWS"
		}

	filter = "configurations:Debug"
		defines "MK_DEBUG"
		symbols "On"

	filter = "configurations:Release"
		defines "MK_RELEASE"
		optimize "On"

	filter = "configurations:Dist"
		defines "MK_DIST"
		optimize "On"

