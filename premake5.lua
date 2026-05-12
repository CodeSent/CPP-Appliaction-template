workspace "Application"
   configurations { "Debug", "Release" }

project "core"
   kind "ConsoleApp"
   language "C++"
   targetdir "bin/%{cfg.buildcfg}/%{cfg.projectname}"

   files { "src/core/**.h", "src/core/**.cpp" }

   filter "configurations:Debug"
      defines { "DEBUG" }
      symbols "On"

   filter "configurations:Release"
      defines { "NDEBUG" }
      optimize "On"