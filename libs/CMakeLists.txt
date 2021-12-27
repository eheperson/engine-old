
#--------------------------------------------------------------------------------------------------------
add_library(SDL_GENERAL INTERFACE)
#
target_include_directories(SDL_GENERAL INTERFACE 
                            ext/sdl2/include
                            ext/sdl2_image)               
#
target_link_directories(SDL_GENERAL INTERFACE
                        ext/sdl2
                        ext/sdl2_image)
#
target_link_libraries(SDL_GENERAL INTERFACE #linker
                        SDL2main 
                        # SDL2 
                        # SDL2-static
                        SDL2_image)
#
#--------------------------------------------------------------------------------------------------------
add_library( architect
                architect/architect.h
                architect/architect.cpp)

target_link_libraries(architect SDL_GENERAL)

# add the library as an include directory
target_include_directories(architect INTERFACE 
                            "${CMAKE_CURRENT_SOURCE_DIR}") #include
#--------------------------------------------------------------------------------------------------------
add_library( inputHandler 
                inputHandler/inputHandler.h
                inputHandler/inputHandler.cpp)

target_link_libraries(inputHandler SDL_GENERAL)

# add the library as an include directory
target_include_directories(inputHandler INTERFACE 
                            "${CMAKE_CURRENT_SOURCE_DIR}") #include
#--------------------------------------------------------------------------------------------------------
add_library( renderer
                renderer/renderer.h
                renderer/renderer.cpp)

target_link_libraries(renderer SDL_GENERAL)
target_link_libraries(renderer architect)


# add the library as an include directory
target_include_directories(inputHandler INTERFACE 
                            "${CMAKE_CURRENT_SOURCE_DIR}") #include