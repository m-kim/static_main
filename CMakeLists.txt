cmake_minimum_required(VERSION 3.8)

project(PathTracing VERSION 0.1 LANGUAGES CXX)

find_package(VTKm REQUIRED
  OPTIONAL_COMPONENTS CUDA)

set (PathTracingSrc
  main.cxx)


if(TARGET vtkm::cuda)
  set_source_files_properties(${PathTracingSrc} PROPERTIES LANGUAGE "CUDA")
  add_executable(CornellBox_CUDA ${PathTracingSrc} )

  target_compile_options(CornellBox_CUDA PRIVATE $<$<COMPILE_LANGUAGE:CUDA>:-gencode arch=compute_50,code=sm_50>)
  set_target_properties(CornellBox_CUDA PROPERTIES CUDA_RESOLVE_DEVICE_SYMBOLS ON)
target_include_directories(CornellBox_CUDA
    PUBLIC $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}>
    )
  set_target_properties(CornellBox_CUDA PROPERTIES
    CUDA_STANDARD 14)
  target_link_libraries(CornellBox_CUDA PRIVATE  vtkm_rendering)

endif()
