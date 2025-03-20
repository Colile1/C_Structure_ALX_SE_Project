#include <SDL2/SDL.h>
#include <GL/glew.h>
#include <iostream>
#include <glm/glm.hpp>
#include <vector>
#include "model/Node.hpp"
#include "model/Beam.hpp"
#include "data/CSVHandler.hpp"

// Global structures
std::vector<Node> nodes;
std::vector<Beam> beams;

// Load test structure
void loadTestStructure() {
    nodes.emplace_back(0.0f, 0.0f, 0.0f).setFixed(true);
    nodes.emplace_back(2.0f, 0.0f, 0.0f);
    beams.emplace_back(&nodes[0], &nodes[1], 2e11f, 0.01f); // Steel beam
}

// SDL2 Initialization and main function
int main() {
    // SDL2 Initialization
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        std::cerr << "SDL_Init Error: " << SDL_GetError() << std::endl;
        return 1;
    }

    // Window Creation
    SDL_Window* window = SDL_CreateWindow("C_Structures", 
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 
        800, 600, 
        SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE);

    // OpenGL Context
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
    SDL_GLContext glContext = SDL_GL_CreateContext(window);

    // GLEW Initialization
    glewExperimental = GL_TRUE;
    if (glewInit() != GLEW_OK) {
        std::cerr << "GLEW init failed!" << std::endl;
        return 1;
    }

    // Load test structure
    loadTestStructure();

    // Main loop
    bool running = true;
    while (running) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT)
                running = false;
        }

        // Clear screen
        glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // Render nodes and beams
        for (const auto& node : nodes) {
            // Implement drawSphere(node.getPosition(), 0.1f);
        }

        for (const auto& beam : beams) {
            // Implement drawCylinder(beam.getStart()->getPosition(), beam.getEnd()->getPosition(), 0.05f);
        }

        SDL_GL_SwapWindow(window);
    }

    // Cleanup
    SDL_GL_DeleteContext(glContext);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
