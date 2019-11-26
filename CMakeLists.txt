cmake_minimum_required(VERSION 3.13)

project(RexrnGenericUI VERSION 0.1)

# Library target headers and sources
file(GLOB_RECURSE GenericUIHeaders
		include/*.hpp
	)
file(GLOB_RECURSE GenericUISources
		src/*.cpp
	)

# Library target
add_library(GenericUI
		${GenericUIHeaders}
		${GenericUISources}
	)

# Include
target_include_directories(GenericUI
		PUBLIC
			include/
	)