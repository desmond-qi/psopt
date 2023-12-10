cmake_minimum_required (VERSION 3.10)
project(AirOpt)

include(cmake/AirOpt_Config.cmake)

add_executable(${PROJECT_NAME} $<$<BOOL:$<TARGET_EXISTS:PSOPT_SNOPT_interface>>:$<TARGET_OBJECTS:PSOPT_SNOPT_interface>> AirOpt.cxx ${CONTROL_FRAME_FILES})
add_dependencies(${PROJECT_NAME} PSOPT)

target_include_directories(AirOpt
	PUBLIC
		${CMAKE_CURRENT_LIST_DIR}/include
)

target_link_libraries(${PROJECT_NAME} 
	PUBLIC 
		PSOPT 
	PRIVATE 
		PkgConfig::ipopt adolc Eigen3::Eigen
)


if(${WITH_SNOPT_INTERFACE})
	enable_language(Fortran)
	target_link_libraries(${PROJECT_NAME} 
		PRIVATE 
			gfortran ${snopt7_LIBRARIES} PSOPT_SNOPT_interface)
endif()
