
include_directories(${CPFloatVars_SOURCE_DIR})

MACRO(CAR var)
  SET(${var} ${ARGV1})
ENDMACRO(CAR)

MACRO(CDR var junk)
  SET(${var} ${ARGN})
ENDMACRO(CDR)

MACRO(PARSE_ARGUMENTS prefix arg_names option_names)
  SET(DEFAULT_ARGS)
  FOREACH(arg_name ${arg_names})
    SET(${prefix}_${arg_name})
  ENDFOREACH(arg_name)
  FOREACH(option ${option_names})
    SET(${prefix}_${option} FALSE)
  ENDFOREACH(option)

  SET(current_arg_name DEFAULT_ARGS)
  SET(current_arg_list)
  FOREACH(arg ${ARGN})
    SET(larg_names ${arg_names})
    LIST(FIND larg_names "${arg}" is_arg_name)
    IF (is_arg_name GREATER -1)
      SET(${prefix}_${current_arg_name} ${current_arg_list})
      SET(current_arg_name ${arg})
      SET(current_arg_list)
    ELSE (is_arg_name GREATER -1)
      SET(loption_names ${option_names})
      LIST(FIND loption_names "${arg}" is_option)
      IF (is_option GREATER -1)
  SET(${prefix}_${arg} TRUE)
      ELSE (is_option GREATER -1)
  SET(current_arg_list ${current_arg_list} ${arg})
      ENDIF (is_option GREATER -1)
    ENDIF (is_arg_name GREATER -1)
  ENDFOREACH(arg)
  SET(${prefix}_${current_arg_name} ${current_arg_list})
ENDMACRO(PARSE_ARGUMENTS)

MACRO(CREATE_LIB)
  PARSE_ARGUMENTS(CRTLIB
    "HEADERS;LINK_LIBRARIES;OUTPUT_NAME;COMPONENT" "STATIC;SHARED;FRAMEWORK"
    ${ARGN}
    )
  CAR(CRTLIB_NAME ${CRTLIB_DEFAULT_ARGS})
  CDR(CRTLIB_SOURCES ${CRTLIB_DEFAULT_ARGS})

  MESSAGE("-- Creating library: ${CRTLIB_NAME}")
  # MESSAGE("Sources: ${CRTLIB_SOURCES}")
  # MESSAGE("Headers: ${CRTLIB_HEADERS}")
  # MESSAGE("Link libraries: ${CRTLIB_LINK_LIBRARIES}")
  MESSAGE("--  Output name: ${CRTLIB_OUTPUT_NAME}")
  # MESSAGE("Component: ${CRTLIB_COMPONENT}")
  set(ANY NO)
  set(LIB_TYPE SHARED)
  IF (CRTLIB_STATIC)
    set(ANY YES)
    set(LIB_TYPE STATIC)
    set(CRTLIB_NAME "${CRTLIB_NAME}-static")
    MESSAGE("--  Type: static")
  ENDIF (CRTLIB_STATIC)
  IF (CRTLIB_SHARED)
    set(ANY YES)
    MESSAGE("--  Type: shared")
  ENDIF (CRTLIB_SHARED)
  IF (CRTLIB_FRAMEWORK)
    set(ANY YES)
    MESSAGE(FATAL_ERROR "->produce framework: not implemented")
  ENDIF (CRTLIB_FRAMEWORK)
  if (NOT ANY)
    message(FATAL_ERROR "undefined library format for ${CRTLIB_NAME}")
  endif(NOT ANY)

  set(CRTLIB_CMPL_SRCS ${CRTLIB_SOURCES})
  list(APPEND CRTLIB_CMPL_SRCS ${CRTLIB_HEADERS})
  #message("Library: ${CRTLIB_NAME}: ${CRTLIB_CMPL_SRCS}")
  add_library(${CRTLIB_NAME} ${LIB_TYPE} ${CRTLIB_CMPL_SRCS})
  target_link_libraries(${CRTLIB_NAME} ${CRTLIB_LINK_LIBRARIES})
  set_target_properties(${CRTLIB_NAME} PROPERTIES
    OUTPUT_NAME "${CRTLIB_OUTPUT_NAME}")
  if (CRTLIB_SHARED)
    install(TARGETS ${CRTLIB_NAME} LIBRARY
      DESTINATION lib
      COMPONENT ${CRTLIB_COMPONENT})
  endif(CRTLIB_SHARED)
  if (CRTLIB_STATIC)
    install(TARGETS ${CRTLIB_NAME} ARCHIVE
      DESTINATION lib
      COMPONENT ${CRTLIB_COMPONENT})
  endif(CRTLIB_STATIC)
  # MESSAGE("***END")
ENDMACRO(CREATE_LIB)

## Source files for floats library
set(float_SRCS
  var-imp/float-imp.cpp
  var/float.cpp
  var/array.cpp)

set(float_VAR_HDRS
  var/float.hpp
  var/print.hpp
  var/array.hpp	)

set(float_VARIMP_HDRS
  var-imp/float-imp.hpp
  var-imp/iter.hpp
  var-imp/delta.hpp)

set(float_VIEW_HDRS
  view/float.hpp
  view/print.hpp
  view/minus.hpp
  view/zero.hpp
  view/expresion.hpp)

set(float_ARITH_HDRS
  arith/arith.hpp)

set(float_BRCH_HDRS
  branch/branch.hpp)

set(float_HDRS
  config.hh
  float.hh
  view.hh
  var-imp.hh
  branch.hh
  arith.hh)

set(float_HEADERS
  ${float_VAR_HDRS} ${float_VARIMP_HDRS}
  ${float_VIEW_HDRS} ${float_HDRS} ${float_ARITH_HDRS}
  ${float_BRCH_HDRS}
)

# message(STATUS "float headers: ${float_HEADERS}")
if(BUILD_SHARED_LIB)
  CREATE_LIB(
    float SHARED ${float_SRCS}
    HEADERS ${float_HEADERS}
    LINK_LIBRARIES ${GECODE_LIBRARY}
    OUTPUT_NAME "gecodefloat"
    COMPONENT devel)
endif(BUILD_SHARED_LIB)
if(BUILD_STATIC_LIB)
  CREATE_LIB(
    binrel STATIC ${float_SRCS}
    HEADERS ${float_HEADERS}
    LINK_LIBRARIES ${GECODE_LIBRARY}
    OUTPUT_NAME "gecodefloat"
    COMPONENT devel)
endif(BUILD_STATIC_LIB)

