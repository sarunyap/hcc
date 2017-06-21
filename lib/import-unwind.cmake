pkg_check_modules(LIBUNWIND REQUIRED libunwind)
add_library(unwind SHARED IMPORTED)

find_library(UNWIND_LIBRARY "${LIBUNWIND_LIBRARIES}"
  HINTS
    ${LIBUNWIND_LIBRARY_DIRS}
)

if (NOT UNWIND_LIBRARY)
    set(${CMAKE_FIND_PACKAGE_NAME}_NOT_FOUND_MESSAGE "${CMAKE_FIND_PACKAGE_NAME} could not be found because dependency libunwind could not be found.")
    set(${CMAKE_FIND_PACKAGE_NAME}_FOUND False)
    return()
endif (NOT UNWIND_LIBRARY)

set_target_properties(unwind PROPERTIES
  PUBLIC_INCLUDE_DIRECTORIES "${LIBUNWIND_INCLUDE_DIRS}"
  PUBLIC_LINK_LIBRARIES "${LIBUNWIND_LIBRARIES}"
  PUBLIC_COMPILE_OPTIONS "${LIBUNWIND_CFLAGS_OTHER}"
  PUBLIC_SYSTEM_INCLUDE_DIRECTORIES "${LIBUNWIND_INCLUDE_DIRS}"
  IMPORTED_LOCATION "${UNWIND_LIBRARY}"
)
