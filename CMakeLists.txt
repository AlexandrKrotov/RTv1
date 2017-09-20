cmake_minimum_required(VERSION 3.7)
project(RTv1)

include_directories(includes)

set(HEADER_FILES includes/rtv1.h includes/libft.h)
set(SOURCE_FILES SRC/main.c includes/rtv1.h SRC/ft_key_hook.c SRC/ft_exit.c
    SRC/ft_mous_hook.c SRC/ft_render.c SRC/ft_init_all.c SRC/ft_vector_math_part1.c
    SRC/ft_sphere.c SRC/ft_plane.c SRC/ft_cylinder.c SRC/ft_cone.c
    SRC/ft_light.c SRC/ft_phong.c SRC/ft_blur.c
    SRC/ft_error.c SRC/ft_init_scene_part1.c SRC/ft_init_scene_part2.c
    SRC/ft_random.c SRC/ft_add_light_spot.c SRC/additional_ft.c
    SRC/ft_vector_math_part2.c SRC/ft_vector_math_part3.c)

add_executable(RTv1 ${SOURCE_FILES})

if(${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
    message(STATUS "UNIX!!!")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -framework OpenGL -framework AppKit -framework OpenCL -lmlx")
    find_library(OPENGL_LIB OpenGL)
    find_library(APPKIT_LIB AppKit)
endif()
if(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
    message(STATUS "Linux!!!")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -lmlx -lXext -lX11 -lm")
    target_link_libraries(RTv1 ${CMAKE_SOURCE_DIR}/minilibx/libmlx.a)
endif()

target_link_libraries(RTv1 ${CMAKE_SOURCE_DIR}/libft/libft.a)
