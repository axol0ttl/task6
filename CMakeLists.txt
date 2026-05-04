cmake_minimum_required(VERSION 3.10)
project(task6_neprosto)

set(CMAKE_CXX_STANDARD 14)

# Find GLFW
find_package(glfw3 3.3 REQUIRED)

# Find OpenGL
find_package(OpenGL REQUIRED)

# Find GLUT (optional, but requested/used in the project)
find_package(GLUT REQUIRED)

include_directories(${OPENGL_INCLUDE_DIR} ${GLUT_INCLUDE_DIR} ${GLFW_INCLUDE_DIRS} .)

add_executable(task5proto
        graphlib.cpp
        graphlib.h
        main.cpp
        figure/figure_selfmade.cpp
        figure/figure_selfmade.h
        line/line_selfmade.cpp
        line/line_selfmade.h
        arc/arc_selfmade.cpp
        arc/arc_selfmade.h
        square/square_selfmade.cpp
        square/square_selfmade.h
        msector/msector.cpp
        msector/msector.h
        msegment/msegment.cpp
        msegment/msegment.h
        objects/object.cpp
        objects/object.h
        objects/MOline.h
        objects/MOarc.h
        objects/MOsquare.h
        objects/MOsector.h
        objects/MOsegment.h
)

target_link_libraries(task5proto
    glfw
    ${OPENGL_LIBRARIES}
    ${GLUT_LIBRARIES}
)

