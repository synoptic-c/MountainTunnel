add_custom_target(Assets ALL
	COMMAND ${CMAKE_COMMAND} -E copy_directory
	${CMAKE_CURRENT_SOURCE_DIR}
	${CMAKE_BINARY_DIR}/Assets
)