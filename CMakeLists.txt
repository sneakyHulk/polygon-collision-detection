cmake_minimum_required(VERSION 3.12)
project(polygon_collision_detection)

set(CMAKE_CXX_STANDARD 23)

set(CPM_DOWNLOAD_VERSION 0.38.1)

if (CPM_SOURCE_CACHE)
    set(CPM_DOWNLOAD_LOCATION "${CPM_SOURCE_CACHE}/cpm/CPM_${CPM_DOWNLOAD_VERSION}.cmake")
elseif (DEFINED ENV{CPM_SOURCE_CACHE})
    set(CPM_DOWNLOAD_LOCATION "$ENV{CPM_SOURCE_CACHE}/cpm/CPM_${CPM_DOWNLOAD_VERSION}.cmake")
else ()
    set(CPM_DOWNLOAD_LOCATION "${CMAKE_BINARY_DIR}/cmake/CPM_${CPM_DOWNLOAD_VERSION}.cmake")
endif ()

# Expand relative path. This is important if the provided path contains a tilde (~)
get_filename_component(CPM_DOWNLOAD_LOCATION ${CPM_DOWNLOAD_LOCATION} ABSOLUTE)

function(download_cpm)
    message(STATUS "Downloading CPM.cmake to ${CPM_DOWNLOAD_LOCATION}")
    file(DOWNLOAD
            https://github.com/cpm-cmake/CPM.cmake/releases/download/v${CPM_DOWNLOAD_VERSION}/CPM.cmake
            ${CPM_DOWNLOAD_LOCATION}
            )
endfunction()

if (NOT (EXISTS ${CPM_DOWNLOAD_LOCATION}))
    download_cpm()
else ()
    # resume download if it previously failed
    file(READ ${CPM_DOWNLOAD_LOCATION} check)
    if ("${check}" STREQUAL "")
        download_cpm()
    endif ()
endif ()

include(${CPM_DOWNLOAD_LOCATION})

set(Boost_Version 1.82.0)

CPMAddPackage(
        NAME boost_geometry_lib
        VERSION ${Boost_Version}
        GITHUB_REPOSITORY "boostorg/geometry"
        GIT_TAG "boost-${Boost_Version}"
        DOWNLOAD_ONLY True
)
CPMAddPackage(
        NAME boost_range_lib
        VERSION ${Boost_Version}
        GITHUB_REPOSITORY "boostorg/range"
        GIT_TAG "boost-${Boost_Version}"
        DOWNLOAD_ONLY True
)
CPMAddPackage(
        NAME boost_config_lib
        VERSION ${Boost_Version}
        GITHUB_REPOSITORY "boostorg/config"
        GIT_TAG "boost-${Boost_Version}"
        DOWNLOAD_ONLY True
)
CPMAddPackage(
        NAME boost_preprocessor_lib
        VERSION ${Boost_Version}
        GITHUB_REPOSITORY "boostorg/preprocessor"
        GIT_TAG "boost-${Boost_Version}"
        DOWNLOAD_ONLY True
)
CPMAddPackage(
        NAME boost_mpl_lib
        VERSION ${Boost_Version}
        GITHUB_REPOSITORY "boostorg/mpl"
        GIT_TAG "boost-${Boost_Version}"
        DOWNLOAD_ONLY True
)
CPMAddPackage(
        NAME boost_type_traits_lib
        VERSION ${Boost_Version}
        GITHUB_REPOSITORY "boostorg/type_traits"
        GIT_TAG "boost-${Boost_Version}"
        DOWNLOAD_ONLY True
)
CPMAddPackage(
        NAME boost_iterator_lib
        VERSION ${Boost_Version}
        GITHUB_REPOSITORY "boostorg/iterator"
        GIT_TAG "boost-${Boost_Version}"
        DOWNLOAD_ONLY True
)
CPMAddPackage(
        NAME boost_static_assert_lib
        VERSION ${Boost_Version}
        GITHUB_REPOSITORY "boostorg/static_assert"
        GIT_TAG "boost-${Boost_Version}"
        DOWNLOAD_ONLY True
)
CPMAddPackage(
        NAME boost_concept_check_lib
        VERSION ${Boost_Version}
        GITHUB_REPOSITORY "boostorg/concept_check"
        GIT_TAG "boost-${Boost_Version}"
        DOWNLOAD_ONLY True
)
CPMAddPackage(
        NAME boost_variant_lib
        VERSION ${Boost_Version}
        GITHUB_REPOSITORY "boostorg/variant"
        GIT_TAG "boost-${Boost_Version}"
        DOWNLOAD_ONLY True
)
CPMAddPackage(
        NAME boost_move_lib
        VERSION ${Boost_Version}
        GITHUB_REPOSITORY "boostorg/move"
        GIT_TAG "boost-${Boost_Version}"
        DOWNLOAD_ONLY True
)
CPMAddPackage(
        NAME boost_core_lib
        VERSION ${Boost_Version}
        GITHUB_REPOSITORY "boostorg/core"
        GIT_TAG "boost-${Boost_Version}"
        DOWNLOAD_ONLY True
)
CPMAddPackage(
        NAME boost_numeric_conversion_lib
        VERSION ${Boost_Version}
        GITHUB_REPOSITORY "boostorg/numeric_conversion"
        GIT_TAG "boost-${Boost_Version}"
        DOWNLOAD_ONLY True
)
CPMAddPackage(
        NAME boost_throw_exception_lib
        VERSION ${Boost_Version}
        GITHUB_REPOSITORY "boostorg/throw_exception"
        GIT_TAG "boost-${Boost_Version}"
        DOWNLOAD_ONLY True
)
CPMAddPackage(
        NAME boost_assert_lib
        VERSION ${Boost_Version}
        GITHUB_REPOSITORY "boostorg/assert"
        GIT_TAG "boost-${Boost_Version}"
        DOWNLOAD_ONLY True
)
CPMAddPackage(
        NAME boost_rational_lib
        VERSION ${Boost_Version}
        GITHUB_REPOSITORY "boostorg/rational"
        GIT_TAG "boost-${Boost_Version}"
        DOWNLOAD_ONLY True
)
CPMAddPackage(
        NAME boost_utility_lib
        VERSION ${Boost_Version}
        GITHUB_REPOSITORY "boostorg/utility"
        GIT_TAG "boost-${Boost_Version}"
        DOWNLOAD_ONLY True
)
CPMAddPackage(
        NAME boost_integer_lib
        VERSION ${Boost_Version}
        GITHUB_REPOSITORY "boostorg/integer"
        GIT_TAG "boost-${Boost_Version}"
        DOWNLOAD_ONLY True
)
CPMAddPackage(
        NAME boost_multiprecision_lib
        VERSION ${Boost_Version}
        GITHUB_REPOSITORY "boostorg/multiprecision"
        GIT_TAG "boost-${Boost_Version}"
        DOWNLOAD_ONLY True
)
CPMAddPackage(
        NAME boost_math_lib
        VERSION ${Boost_Version}
        GITHUB_REPOSITORY "boostorg/math"
        GIT_TAG "boost-${Boost_Version}"
        DOWNLOAD_ONLY True
)
CPMAddPackage(
        NAME boost_detail_lib
        VERSION ${Boost_Version}
        GITHUB_REPOSITORY "boostorg/detail"
        GIT_TAG "boost-${Boost_Version}"
        DOWNLOAD_ONLY True
)
CPMAddPackage(
        NAME boost_type_index_lib
        VERSION ${Boost_Version}
        GITHUB_REPOSITORY "boostorg/type_index"
        GIT_TAG "boost-${Boost_Version}"
        DOWNLOAD_ONLY True
)
CPMAddPackage(
        NAME boost_type_index_lib
        VERSION ${Boost_Version}
        GITHUB_REPOSITORY "boostorg/type_index"
        GIT_TAG "boost-${Boost_Version}"
        DOWNLOAD_ONLY True
)
CPMAddPackage(
        NAME boost_container_hash_lib
        VERSION ${Boost_Version}
        GITHUB_REPOSITORY "boostorg/container_hash"
        GIT_TAG "boost-${Boost_Version}"
        DOWNLOAD_ONLY True
)
CPMAddPackage(
        NAME boost_array_lib
        VERSION ${Boost_Version}
        GITHUB_REPOSITORY "boostorg/array"
        GIT_TAG "boost-${Boost_Version}"
        DOWNLOAD_ONLY True
)
CPMAddPackage(
        NAME boost_function_types_lib
        VERSION ${Boost_Version}
        GITHUB_REPOSITORY "boostorg/function_types"
        GIT_TAG "boost-${Boost_Version}"
        DOWNLOAD_ONLY True
)
CPMAddPackage(
        NAME boost_algorithm_lib
        VERSION ${Boost_Version}
        GITHUB_REPOSITORY "boostorg/algorithm"
        GIT_TAG "boost-${Boost_Version}"
        DOWNLOAD_ONLY True
)
CPMAddPackage(
        NAME boost_tuple_lib
        VERSION ${Boost_Version}
        GITHUB_REPOSITORY "boostorg/tuple"
        GIT_TAG "boost-${Boost_Version}"
        DOWNLOAD_ONLY True
)
CPMAddPackage(
        NAME boost_qvm_lib
        VERSION ${Boost_Version}
        GITHUB_REPOSITORY "boostorg/qvm"
        GIT_TAG "boost-${Boost_Version}"
        DOWNLOAD_ONLY True
)
CPMAddPackage(
        NAME boost_container_lib
        VERSION ${Boost_Version}
        GITHUB_REPOSITORY "boostorg/container"
        GIT_TAG "boost-${Boost_Version}"
        DOWNLOAD_ONLY True
)
CPMAddPackage(
        NAME boost_intrusive_lib
        VERSION ${Boost_Version}
        GITHUB_REPOSITORY "boostorg/intrusive"
        GIT_TAG "boost-${Boost_Version}"
        DOWNLOAD_ONLY True
)
CPMAddPackage(
        NAME boost_smart_ptr_lib
        VERSION ${Boost_Version}
        GITHUB_REPOSITORY "boostorg/smart_ptr"
        GIT_TAG "boost-${Boost_Version}"
        DOWNLOAD_ONLY True
)
CPMAddPackage(
        NAME boost_lexical_cast_lib
        VERSION ${Boost_Version}
        GITHUB_REPOSITORY "boostorg/lexical_cast"
        GIT_TAG "boost-${Boost_Version}"
        DOWNLOAD_ONLY True
)
CPMAddPackage(
        NAME boost_tokenizer_lib
        VERSION ${Boost_Version}
        GITHUB_REPOSITORY "boostorg/tokenizer"
        GIT_TAG "boost-${Boost_Version}"
        DOWNLOAD_ONLY True
)
CPMAddPackage(
        NAME boost_function_lib
        VERSION ${Boost_Version}
        GITHUB_REPOSITORY "boostorg/function"
        GIT_TAG "boost-${Boost_Version}"
        DOWNLOAD_ONLY True
)
CPMAddPackage(
        NAME boost_bind_lib
        VERSION ${Boost_Version}
        GITHUB_REPOSITORY "boostorg/bind"
        GIT_TAG "boost-${Boost_Version}"
        DOWNLOAD_ONLY True
)

CPMAddPackage(
        NAME SFML
        VERSION 2.5.1
        GITHUB_REPOSITORY "SFML/SFML"
        GIT_TAG "2.5.1"
        OPTIONS "SFML_BUILD_AUDIO Off" "SFML_BUILD_NETWORK Off" "SFML_BUILD_EXAMPLES Off" "SFML_BUILD_DOC Off" "BUILD_SHARED_LIBS On" "SFML_USE_STATIC_STD_LIBS Off"
)

CPMAddPackage(
        NAME benchmark
        GITHUB_REPOSITORY google/benchmark
        VERSION 1.8.0
        OPTIONS "BENCHMARK_ENABLE_TESTING Off"
)

if (benchmark_ADDED)
    # enable c++11 to avoid compilation errors
    set_target_properties(benchmark PROPERTIES CXX_STANDARD 11)
endif ()

if (SFML_ADDED)
    # enable c++17 to avoid compilation errors
    set_target_properties(sfml-graphics PROPERTIES CXX_STANDARD 17)
endif ()

#include_directories(${boost_lib_SOURCE_DIR}/libs/geometry/include)
#include_directories(${boost_lib_SOURCE_DIR}/libs/range/include)
#include_directories(${boost_lib_SOURCE_DIR}/libs/config/include)
#include_directories(${boost_lib_SOURCE_DIR}/libs/preprocessor/include)
#include_directories(${boost_lib_SOURCE_DIR}/libs/mpl/include)
#include_directories(${boost_lib_SOURCE_DIR}/libs/type_traits/include)
#include_directories(${boost_lib_SOURCE_DIR}/libs/iterator/include)
#include_directories(${boost_lib_SOURCE_DIR}/libs/static_assert/include)
#include_directories(${boost_lib_SOURCE_DIR}/libs/concept_check/include)
#include_directories(${boost_lib_SOURCE_DIR}/libs/variant/include)
#include_directories(${boost_lib_SOURCE_DIR}/libs/move/include)
#include_directories(${boost_lib_SOURCE_DIR}/libs/core/include)
#include_directories(${boost_lib_SOURCE_DIR}/libs/detail/include)
#include_directories(${boost_lib_SOURCE_DIR}/libs/type_index/include)
#include_directories(${boost_lib_SOURCE_DIR}/libs/container_hash/include)
#include_directories(${boost_lib_SOURCE_DIR}/libs/throw_exception/include)
#include_directories(${boost_lib_SOURCE_DIR}/libs/assert/include)
#include_directories(${boost_lib_SOURCE_DIR}/libs/utility/include)
#include_directories(${boost_lib_SOURCE_DIR}/libs/integer/include)
#include_directories(${boost_lib_SOURCE_DIR}/libs/math/include)
#include_directories(${boost_lib_SOURCE_DIR}/libs/math/include_private)
#include_directories(${boost_lib_SOURCE_DIR}/libs/numeric/conversion/include)
#include_directories(${boost_lib_SOURCE_DIR}/libs/numeric/interval/include)
#include_directories(${boost_lib_SOURCE_DIR}/libs/numeric/odeint/include)
#include_directories(${boost_lib_SOURCE_DIR}/libs/numeric/ublas/include)
#include_directories(${boost_lib_SOURCE_DIR}/libs/array/include)
#include_directories(${boost_lib_SOURCE_DIR}/libs/function_types/include)
#include_directories(${boost_lib_SOURCE_DIR}/libs/rational/include)
#include_directories(${boost_lib_SOURCE_DIR}/libs/multiprecision/include)
#include_directories(${boost_lib_SOURCE_DIR}/libs/algorithm/include)
#include_directories(${boost_lib_SOURCE_DIR}/libs/container/include)
#include_directories(${boost_lib_SOURCE_DIR}/libs/tuple/include)
#include_directories(${boost_lib_SOURCE_DIR}/libs/intrusive/include)
#include_directories(${boost_lib_SOURCE_DIR}/libs/smart_ptr/include)
#include_directories(${boost_lib_SOURCE_DIR}/libs/variant2/include)
#include_directories(${boost_lib_SOURCE_DIR}/libs/tokenizer/include)
#include_directories(${boost_lib_SOURCE_DIR}/libs/qvm/include)
#include_directories(${boost_lib_SOURCE_DIR}/libs/fusion/include)
#include_directories(${boost_lib_SOURCE_DIR}/libs/any/include)
#include_directories(${boost_lib_SOURCE_DIR}/libs/assert/include)
#include_directories(${boost_lib_SOURCE_DIR}/libs/endian/include)
#include_directories(${boost_lib_SOURCE_DIR}/libs/function_types/include)
#include_directories(${boost_lib_SOURCE_DIR}/libs/mpl/include)
#include_directories(${boost_lib_SOURCE_DIR}/libs/polygon/include)
#include_directories(${boost_lib_SOURCE_DIR}/libs/predef/include)
#include_directories(${boost_lib_SOURCE_DIR}/libs/serialization/include)
#include_directories(${boost_lib_SOURCE_DIR}/libs/thread/include)

if (boost_geometry_lib_ADDED)

    include_directories(${boost_geometry_lib_SOURCE_DIR}/include)
    include_directories(${boost_range_lib_SOURCE_DIR}/include)
    include_directories(${boost_config_lib_SOURCE_DIR}/include)
    include_directories(${boost_preprocessor_lib_SOURCE_DIR}/include)
    include_directories(${boost_mpl_lib_SOURCE_DIR}/include)
    include_directories(${boost_type_traits_lib_SOURCE_DIR}/include)
    include_directories(${boost_iterator_lib_SOURCE_DIR}/include)
    include_directories(${boost_static_assert_lib_SOURCE_DIR}/include)
    include_directories(${boost_concept_check_lib_SOURCE_DIR}/include)
    include_directories(${boost_variant_lib_SOURCE_DIR}/include)
    include_directories(${boost_move_lib_SOURCE_DIR}/include)
    include_directories(${boost_core_lib_SOURCE_DIR}/include)
    include_directories(${boost_numeric_conversion_lib_SOURCE_DIR}/include)
    include_directories(${boost_throw_exception_lib_SOURCE_DIR}/include)
    include_directories(${boost_assert_lib_SOURCE_DIR}/include)
    include_directories(${boost_rational_lib_SOURCE_DIR}/include)
    include_directories(${boost_utility_lib_SOURCE_DIR}/include)
    include_directories(${boost_integer_lib_SOURCE_DIR}/include)
    include_directories(${boost_multiprecision_lib_SOURCE_DIR}/include)
    include_directories(${boost_math_lib_SOURCE_DIR}/include)
    include_directories(${boost_math_lib_SOURCE_DIR}/include_private)
    include_directories(${boost_detail_lib_SOURCE_DIR}/include)
    include_directories(${boost_type_index_lib_SOURCE_DIR}/include)
    include_directories(${boost_container_hash_lib_SOURCE_DIR}/include)
    include_directories(${boost_array_lib_SOURCE_DIR}/include)
    include_directories(${boost_function_types_lib_SOURCE_DIR}/include)
    include_directories(${boost_algorithm_lib_SOURCE_DIR}/include)
    include_directories(${boost_tuple_lib_SOURCE_DIR}/include)
    include_directories(${boost_qvm_lib_SOURCE_DIR}/include)
    include_directories(${boost_container_lib_SOURCE_DIR}/include)
    include_directories(${boost_intrusive_lib_SOURCE_DIR}/include)
    include_directories(${boost_smart_ptr_lib_SOURCE_DIR}/include)
    include_directories(${boost_lexical_cast_lib_SOURCE_DIR}/include)
    include_directories(${boost_tokenizer_lib_SOURCE_DIR}/include)
    include_directories(${boost_function_lib_SOURCE_DIR}/include)
    include_directories(${boost_bind_lib_SOURCE_DIR}/include)

    add_library(boost_math INTERFACE)
    target_include_directories(boost_math
            INTERFACE $<BUILD_INTERFACE:${boost_math_lib_SOURCE_DIR}/include>
            $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
            )
    target_compile_definitions(boost_math INTERFACE BOOST_MATH_STANDALONE=1)

    add_library(boost_extension INTERFACE)
    target_include_directories(boost_extension
            INTERFACE $<BUILD_INTERFACE:${boost_geometry_lib_SOURCE_DIR}/include>
            $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
            )
    target_link_libraries(boost_extension INTERFACE boost_math)
endif ()

# find_package(SFML COMPONENTS system window graphics network audio REQUIRED)
add_executable(polygon_collision_detection src/main.cpp)
target_link_libraries(polygon_collision_detection sfml-graphics)

add_executable(benchmark_ src/benchmark.cpp)
target_link_libraries(benchmark_ benchmark::benchmark)

add_executable(line_strip_collision_detection src/line_strip.cpp)
target_link_libraries(line_strip_collision_detection sfml-graphics boost_extension)


add_executable(boost_closest_point_extension src/boost_closest_point_extension.cpp)
target_link_libraries(boost_closest_point_extension sfml-graphics boost_extension)