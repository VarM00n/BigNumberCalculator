project(Calculator_lib)

set(HEADER_FILES Calculator.h Number.h Interpreter.h)
set(SOURCE_FILES Calculator.cpp Number.cpp CalculatorOverloads.cpp Interpreter.cpp)

add_library(Calculator_lib STATIC ${SOURCE_FILES} ${HEADER_FILES})