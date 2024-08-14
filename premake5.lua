workspace "CraftEngine"
	architecture "x64"
	startproject "Sandbox"

	configurations{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "CraftEngine"
	location "CraftEngine"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs{
		"%{prj.name}/src"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines{
			"CRAFT_PLATFORM_WINDOWS",
			"CRAFT_BUILD_DLL"
		}

		postbuildcommands{
			("{COPY} %{cfg.buildtarget.relpath} .. /bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "CRAFT_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "CRAFT_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "CRAFT_DIST"
		optimize "On"


project "Sandbox"
	location "Sandbox"
	kind "SharedLib"
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
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines{
			"CRAFT_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "CRAFT_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "CRAFT_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "CRAFT_DIST"
		optimize "On"