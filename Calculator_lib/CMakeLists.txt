project(Calculator_lib)

set(HEADER_FILES Calculator.h Number.h)
set(SOURCE_FILES Calculator.cpp Number.cpp CalculatorOverloads.cpp)

add_library(Calculator_lib STATIC ${SOURCE_FILES} ${HEADER_FILES})