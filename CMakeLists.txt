cmake_minimum_required(VERSION 3.0)

project(HumanDynamicsEstimation CXX)

## Find packages
find_package(YARP REQUIRED)
find_package(YCM REQUIRED)

list(APPEND CMAKE_MODULE_PATH ${YARP_MODULE_PATH})

# To build shared libraries in Windows, we set CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS to TRUE
# See https://cmake.org/cmake/help/v3.4/variable/CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS.html
# See https://blog.kitware.com/create-dlls-on-windows-without-declspec-using-new-cmake-export-all-feature/
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

# Shared/Dynamic or Static library?
option(BUILD_SHARED_LIBS "Build libraries as shared as opposed to static" ON)

include(AddInstallRPATHSupport)
#check discussion in YARP
# add_install_rpath_support(BIN_DIRS "${CMAKE_INSTALL_PREFIX}/${CMAKE_INSTALL_BINDIR}"
#                           LIB_DIRS "${CMAKE_INSTALL_PREFIX}/${CMAKE_INSTALL_LIBDIR}"
#                           DEPENDS ENABLE_RPATH
#                           USE_LINK_PATH)

add_subdirectory(human-state-provider)
add_subdirectory(human-forces-provider)
# Adding the estimator as last module
# as it needs the interfaces exposed by the previous targets
add_subdirectory(human-dynamics-estimator)
