cmake_minimum_required(VERSION 3.21)

project(open_close_example
        VERSION 0.0.1
        DESCRIPTION ""
        LANGUAGES C)

set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

set(STANDARD_FLAGS
        -D_POSIX_C_SOURCE=200809L
        -D_XOPEN_SOURCE=700
        #        -D_GNU_SOURCE
        -D_DARWIN_C_SOURCE
        -D__BSD_VISIBLE
        -Werror
)

set(SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/main.c
)

# Build the shared library
add_executable(open_close_example ${SOURCES})
target_include_directories(open_close_example PRIVATE /usr/local/include)

# Extract the compiler name without the path
get_filename_component(COMPILER_NAME "${CMAKE_C_COMPILER}" NAME)

function(split_string_into_list _input_string _output_list)
    string(REGEX REPLACE "[ ]+" ";" _split_list "${_input_string}")
    set(${_output_list} ${_split_list} PARENT_SCOPE)
endfunction()

# Import analyzer_flags.txt
file(STRINGS "${CMAKE_SOURCE_DIR}/.flags/${COMPILER_NAME}/analyzer_flags.txt" ANALYZER_FLAGS_STRING)
split_string_into_list("${ANALYZER_FLAGS_STRING}" ANALYZER_FLAGS_LIST)

# Import debug_flags.txt
file(STRINGS "${CMAKE_SOURCE_DIR}/.flags/${COMPILER_NAME}/code_generation_flags.txt" CODE_GENERATION_FLAGS_STRING)
split_string_into_list("${CODE_GENERATION_FLAGS_STRING}" DEBUG_FLAGS_LIST)

# Import debug_flags.txt
file(STRINGS "${CMAKE_SOURCE_DIR}/.flags/${COMPILER_NAME}/debug_flags.txt" DEBUG_FLAGS_STRING)
split_string_into_list("${DEBUG_FLAGS_STRING}" DEBUG_FLAGS_LIST)

# Import instrumentation_flags.txt
file(STRINGS "${CMAKE_SOURCE_DIR}/.flags/${COMPILER_NAME}/instrumentation_flags.txt" INSTRUMENTATION_FLAGS_STRING)
split_string_into_list("${INSTRUMENTATION_FLAGS_STRING}" INSTRUMENTATION_FLAGS_LIST)

# Import optimization_flags.txt
file(STRINGS "${CMAKE_SOURCE_DIR}/.flags/${COMPILER_NAME}/optimization_flags.txt" OPTIMIZATION_FLAGS_STRING)
split_string_into_list("${OPTIMIZATION_FLAGS_STRING}" OPTIMIZATION_FLAGS_LIST)

# Import warning_flags.txt
file(STRINGS "${CMAKE_SOURCE_DIR}/.flags/${COMPILER_NAME}/warning_flags.txt" WARNING_FLAGS_STRING)
split_string_into_list("${WARNING_FLAGS_STRING}" WARNING_FLAGS_LIST)

if(SANITIZER_address STREQUAL "ON")
    file(STRINGS "${CMAKE_SOURCE_DIR}/.flags/${COMPILER_NAME}/address_sanitizer_flags.txt" ADDRESS_SANITIZER_FLAGS_STRING)
    string(REPLACE " " ";" ADDRESS_SANITIZER_FLAGS_LIST "${ADDRESS_SANITIZER_FLAGS_STRING}")
    target_compile_options(open_close_example PRIVATE ${ADDRESS_SANITIZER_FLAGS_LIST} PRIVATE ${STANDARD_FLAGS})
    target_link_options(open_close_example PRIVATE ${ADDRESS_SANITIZER_FLAGS_LIST})
endif()

if(SANITIZER_cfi STREQUAL "ON")
    file(STRINGS "${CMAKE_SOURCE_DIR}/.flags/${COMPILER_NAME}/cfi_sanitizer_flags.txt" CFI_SANITIZER_FLAGS_STRING)
    string(REPLACE " " ";" CFI_SANITIZER_FLAGS_LIST "${CFI_SANITIZER_FLAGS_STRING}")
    target_compile_options(open_close_example PRIVATE ${CFI_SANITIZER_FLAGS_LIST} PRIVATE ${STANDARD_FLAGS})
    target_link_options(open_close_example PRIVATE ${CFI_SANITIZER_FLAGS_LIST})
endif()

if(SANITIZER_dataflow STREQUAL "ON")
    file(STRINGS "${CMAKE_SOURCE_DIR}/.flags/${COMPILER_NAME}/dataflow_sanitizer_flags.txt" DATAFLOW_SANITIZER_FLAGS_STRING)
    string(REPLACE " " ";" DATAFLOW_SANITIZER_FLAGS_LIST "${DATAFLOW_SANITIZER_FLAGS_STRING}")
    target_compile_options(open_close_example PRIVATE ${DATAFLOW_SANITIZER_FLAGS_LIST} PRIVATE ${STANDARD_FLAGS})
    target_link_options(open_close_example PRIVATE ${DATAFLOW_SANITIZER_FLAGS_LIST})
endif()

if(SANITIZER_hwaddress STREQUAL "ON")
    file(STRINGS "${CMAKE_SOURCE_DIR}/.flags/${COMPILER_NAME}/hwaddress_sanitizer_flags.txt" HWADDRESS_SANITIZER_FLAGS_STRING)
    string(REPLACE " " ";" HWADDRESS_SANITIZER_FLAGS_LIST "${HWADDRESS_SANITIZER_FLAGS_STRING}")
    target_compile_options(open_close_example PRIVATE ${HWADDRESS_SANITIZER_FLAGS_LIST} PRIVATE ${STANDARD_FLAGS})
    target_link_options(open_close_example PRIVATE ${HWADDRESS_SANITIZER_FLAGS_LIST})
endif()

if(SANITIZER_leak STREQUAL "ON")
    file(STRINGS "${CMAKE_SOURCE_DIR}/.flags/${COMPILER_NAME}/leak_sanitizer_flags.txt" LEAK_SANITIZER_FLAGS_STRING)
    string(REPLACE " " ";" LEAK_SANITIZER_FLAGS_LIST "${LEAK_SANITIZER_FLAGS_STRING}")
    target_compile_options(open_close_example PRIVATE ${LEAK_SANITIZER_FLAGS_LIST} PRIVATE ${STANDARD_FLAGS})
    target_link_options(open_close_example PRIVATE ${LEAK_SANITIZER_FLAGS_LIST})
endif()

if(SANITIZER_memory STREQUAL "ON")
    file(STRINGS "${CMAKE_SOURCE_DIR}/.flags/${COMPILER_NAME}/memory_sanitizer_flags.txt" MEMORY_SANITIZER_FLAGS_STRING)
    string(REPLACE " " ";" MEMORY_SANITIZER_FLAGS_LIST "${MEMORY_SANITIZER_FLAGS_STRING}")
    target_compile_options(open_close_example PRIVATE ${MEMORY_SANITIZER_FLAGS_LIST} PRIVATE ${STANDARD_FLAGS})
    target_link_options(open_close_example PRIVATE ${MEMORY_SANITIZER_FLAGS_LIST})
endif()

if(SANITIZER_pointer_overflow STREQUAL "ON")
    file(STRINGS "${CMAKE_SOURCE_DIR}/.flags/${COMPILER_NAME}/pointer_overflow_sanitizer_flags.txt" POINTER_OVERFLOW_SANITIZER_FLAGS_STRING)
    string(REPLACE " " ";" POINTER_OVERFLOW_SANITIZER_FLAGS_LIST "${POINTER_OVERFLOW_SANITIZER_FLAGS_STRING}")
    target_compile_options(open_close_example PRIVATE ${POINTER_OVERFLOW_SANITIZER_FLAGS_LIST} PRIVATE ${STANDARD_FLAGS})
    target_link_options(open_close_example PRIVATE ${POINTER_OVERFLOW_SANITIZER_FLAGS_LIST})
endif()

if(SANITIZER_safe_stack STREQUAL "ON")
    file(STRINGS "${CMAKE_SOURCE_DIR}/.flags/${COMPILER_NAME}/safe_stack_sanitizer_flags.txt" SAFE_STACK_SANITIZER_FLAGS_STRING)
    string(REPLACE " " ";" SAFE_STACK_SANITIZER_FLAGS_LIST "${SAFE_STACK_SANITIZER_FLAGS_STRING}")
    target_compile_options(open_close_example PRIVATE ${SAFE_STACK_SANITIZER_FLAGS_LIST} PRIVATE ${STANDARD_FLAGS})
    target_link_options(open_close_example PRIVATE ${SAFE_STACK_SANITIZER_FLAGS_LIST})
endif()

if(SANITIZER_safe_stack STREQUAL "ON")
    file(STRINGS "${CMAKE_SOURCE_DIR}/.flags/${COMPILER_NAME}/shadow_call_stack_sanitizer_flags.txt" SHADOW_CALL_STACK_SANITIZER_FLAGS_STRING)
    string(REPLACE " " ";" SHADOW_CALL_STACK_SANITIZER_FLAGS_LIST "${SHADOW_CALL_STACK_SANITIZER_FLAGS_STRING}")
    target_compile_options(open_close_example PRIVATE ${SHADOW_CALL_STACK_SANITIZER_FLAGS_LIST} PRIVATE ${STANDARD_FLAGS})
    target_link_options(open_close_example PRIVATE ${SHADOW_CALL_STACK_SANITIZER_FLAGS_LIST})
endif()

if(SANITIZER_thread STREQUAL "ON")
    file(STRINGS "${CMAKE_SOURCE_DIR}/.flags/${COMPILER_NAME}/thread_sanitizer_flags.txt" THREAD_SANITIZER_FLAGS_STRING)
    string(REPLACE " " ";" THREAD_SANITIZER_FLAGS_LIST "${THREAD_SANITIZER_FLAGS_STRING}")
    target_compile_options(open_close_example PRIVATE ${THREAD_SANITIZER_FLAGS_LIST} PRIVATE ${STANDARD_FLAGS})
    target_link_options(open_close_example PRIVATE ${THREAD_SANITIZER_FLAGS_LIST})
endif()

if(SANITIZER_undefined STREQUAL "ON")
    file(STRINGS "${CMAKE_SOURCE_DIR}/.flags/${COMPILER_NAME}/undefined_sanitizer_flags.txt" UNDEFINED_SANITIZER_FLAGS_STRING)
    string(REPLACE " " ";" UNDEFINED_SANITIZER_FLAGS_LIST "${UNDEFINED_SANITIZER_FLAGS_STRING}")
    target_compile_options(open_close_example PRIVATE ${UNDEFINED_SANITIZER_FLAGS_LIST} PRIVATE ${STANDARD_FLAGS})
    target_link_options(open_close_example PRIVATE ${UNDEFINED_SANITIZER_FLAGS_LIST})
endif()

# Check if the system uses 64-bit libraries
get_property(LIB64 GLOBAL PROPERTY FIND_LIBRARY_USE_LIB64_PATHS)

# Set the library suffix based on whether it's 64-bit or not
if ("${LIB64}" STREQUAL "TRUE")
    set(LIBSUFFIX 64)
else()
    set(LIBSUFFIX "")
endif()

target_link_directories(open_close_example PRIVATE /usr/local/lib${LIBSUFFIX})
target_link_options(open_close_example PRIVATE ${INSTRUMENTATION_FLAGS_LIST})

# Link libraries
find_library(GDBM_COMPAT_LIB NAMES gdbm_compat)

if(GDBM_COMPAT_LIB)
    target_link_libraries(open_close_example PRIVATE ${GDBM_COMPAT_LIB})
endif()

# Set compiler flags for the target
target_compile_options(open_close_example PRIVATE
        ${STANDARD_FLAGS}
        ${ANALYZER_FLAGS_LIST}
        ${DEBUG_FLAGS_LIST}
        ${INSTRUMENTATION_FLAGS_LIST}
        ${OPTIMIZATION_FLAGS_LIST}
        ${WARNING_FLAGS_LIST}
)

if (NOT DEFINED CLANG_FORMAT_NAME)
    set(CLANG_FORMAT_NAME "clang-format")
endif()

if (NOT DEFINED CLANG_TIDY_NAME)
    set(CLANG_TIDY_NAME "clang-tidy")
endif()

if (NOT DEFINED CPPCHECK_NAME)
    set(CPPCHECK_NAME "cppcheck")
endif()

find_program(CLANG_FORMAT NAMES ${CLANG_FORMAT_NAME} REQUIRED)
find_program(CLANG_TIDY NAMES ${CLANG_TIDY_NAME} REQUIRED)
find_program(CPPCHECK NAMES ${CPPCHECK_NAME} REQUIRED)

# Format source files using clang-format
add_custom_target(open_close_example_format
        COMMAND ${CLANG_FORMAT} --style=file -i ${SOURCES}
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
        COMMENT "Running clang-format"
)

# Lint source files using clang-tidy
add_custom_target(open_close_example_tidy
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
        COMMAND ${CLANG_TIDY} ${SOURCES} -quiet --warnings-as-errors='*' -checks=*,-llvmlibc-restrict-system-libc-headers,-altera-struct-pack-align,-readability-identifier-length,-altera-unroll-loops,-cppcoreguidelines-init-variables,-cert-err33-c,-modernize-macro-to-enum,-bugprone-easily-swappable-parameters,-clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling,-altera-id-dependent-backward-branch,-concurrency-mt-unsafe,-misc-unused-parameters,-hicpp-signed-bitwise,-google-readability-todo,-cert-msc30-c,-cert-msc50-cpp,-readability-function-cognitive-complexity,-clang-analyzer-security.insecureAPI.strcpy,-cert-env33-c,-android-cloexec-accept,-clang-analyzer-security.insecureAPI.rand,-misc-include-cleaner,-llvm-header-guard,-cppcoreguidelines-macro-to-enum -- ${CMAKE_C_FLAGS} ${STANDARD_FLAGS} -I/usr/local/include
        COMMENT "Running clang-tidy"
)

# Add a custom target for cppcheck
add_custom_target(open_close_example_cppcheck
        COMMAND ${CPPCHECK} --error-exitcode=1 --force --quiet --inline-suppr --check-level=exhaustive --library=posix --enable=all --suppress=missingIncludeSystem --suppress=unusedFunction --suppress=unmatchedSuppression --suppress=checkersReport -I/usr/local/include ${SOURCES} ${HEADER_LIST}
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
        COMMENT "Running cppcheck"
)

# Check if CMAKE_C_COMPILER starts with "clang"
if (CMAKE_C_COMPILER MATCHES ".*/clang.*")
    # Add a custom target for clang --analyze
    add_custom_target(open_close_example_analysis
            COMMAND ${CMAKE_C_COMPILER} --analyze --analyzer-output text -Xclang -analyzer-checker=core --analyze -Xclang -analyzer-checker=deadcode -Xclang -analyzer-checker=security -Xclang -analyzer-disable-checker=security.insecureAPI.DeprecatedOrUnsafeBufferHandling -Xclang -analyzer-checker=unix -Xclang -analyzer-checker=unix ${CMAKE_C_FLAGS} ${STANDARD_FLAGS} -I${CMAKE_CURRENT_SOURCE_DIR}/include -I/usr/local/include ${SOURCES} ${HEADER_LIST}
            WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
            COMMENT "Running clang --analyze"
    )

    # Add a custom command to delete .gch files after the analysis
    add_custom_command(
            TARGET open_close_example POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E remove ${CMAKE_CURRENT_SOURCE_DIR}/include/p101_env/*.gch
            COMMENT "Removing .gch files"
    )

    # Add dependencies including 'analysis' for Clang compiler
    add_custom_target(open_close_example_all
            DEPENDS create_destroy_example create_destroy_example_analysis create_destroy_example_tidy create_destroy_example_cppcheck
            COMMENT "Running code analysis tools"
    )
else()
    # Add dependencies without 'analysis' for other compilers
    add_custom_target(open_close_example_all
            DEPENDS create_destroy_example create_destroy_example_tidy create_destroy_example_cppcheck
            COMMENT "Running code analysis tools"
    )
endif()

add_dependencies(open_close_example open_close_example_format)
