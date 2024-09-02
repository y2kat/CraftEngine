workspace "CraftEngine"
	architecture "x64"
	startproject "Sandbox"

	configurations{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}
IncludeDir["GLFW"] = "CraftEngine/vendor/GLFW/include"

project "CraftEngine"
	location "CraftEngine"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "craftpch.h"
	pchsource "CraftEngine/src/craftpch.cpp"

	files{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs{
		"%{prj.name}/src",
		"%{IncludeDir.GLFW}"
	}

	links{
		"GLFW",
		"opengl32.lib"
	}

	filter "system:windows"
		cppdialect "C++20"
		staticruntime "off"
		runtime "Release"
		systemversion "latest"

		defines{
			"CRAFT_PLATFORM_WINDOWS",
			"CRAFT_BUILD_DLL"
		}

		postbuildcommands{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "CRAFT_DEBUG"
		buildoptions "/MDd"
		symbols "On"

	filter "configurations:Release"
		defines "CRAFT_RELEASE"
		buildoptions "/MD"
		optimize "On"

	filter "configurations:Dist"
		defines "CRAFT_DIST"
		buildoptions "/MD"
		optimize "On"


project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs{
		"CraftEngine/src"
	}

	links {
		"CraftEngine"
	}

	filter "system:windows"
		cppdialect "C++20"
		staticruntime "off"
		runtime "Release"
		systemversion "latest"

		defines{
			"CRAFT_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "CRAFT_DEBUG"
		buildoptions "/MDd"
		symbols "On"

	filter "configurations:Release"
		defines "CRAFT_RELEASE"
		buildoptions "/MD"
		optimize "On"

	filter "configurations:Dist"
		defines "CRAFT_DIST"
		buildoptions "/MD"
		optimize "On"