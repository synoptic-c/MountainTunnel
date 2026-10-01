add_subdirectory(Util)
add_subdirectory(Platform)
add_subdirectory(Render)
add_subdirectory(Framework)
add_subdirectory(Entry)
target_include_directories(${PROJECT_NAME} PRIVATE
	${CMAKE_CURRENT_SOURCE_DIR}
)