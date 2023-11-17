# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/Users/mademir/Desktop/42cursus/push_swap/push_swap_viz/build/_deps/imgui-sfml-src"
  "/Users/mademir/Desktop/42cursus/push_swap/push_swap_viz/build/_deps/imgui-sfml-build"
  "/Users/mademir/Desktop/42cursus/push_swap/push_swap_viz/build/_deps/imgui-sfml-subbuild/imgui-sfml-populate-prefix"
  "/Users/mademir/Desktop/42cursus/push_swap/push_swap_viz/build/_deps/imgui-sfml-subbuild/imgui-sfml-populate-prefix/tmp"
  "/Users/mademir/Desktop/42cursus/push_swap/push_swap_viz/build/_deps/imgui-sfml-subbuild/imgui-sfml-populate-prefix/src/imgui-sfml-populate-stamp"
  "/Users/mademir/Desktop/42cursus/push_swap/push_swap_viz/build/_deps/imgui-sfml-subbuild/imgui-sfml-populate-prefix/src"
  "/Users/mademir/Desktop/42cursus/push_swap/push_swap_viz/build/_deps/imgui-sfml-subbuild/imgui-sfml-populate-prefix/src/imgui-sfml-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/Users/mademir/Desktop/42cursus/push_swap/push_swap_viz/build/_deps/imgui-sfml-subbuild/imgui-sfml-populate-prefix/src/imgui-sfml-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/Users/mademir/Desktop/42cursus/push_swap/push_swap_viz/build/_deps/imgui-sfml-subbuild/imgui-sfml-populate-prefix/src/imgui-sfml-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()
