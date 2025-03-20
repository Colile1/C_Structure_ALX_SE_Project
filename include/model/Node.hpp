#pragma once
#include <glm/glm.hpp> // For vec3

class Node {
public:
    Node(float x, float y, float z);
    
    // Getters
    glm::vec3 getPosition() const;
    bool isFixed() const;
    
    // Setters
    void setFixed(bool fixed);
    void applyForce(const glm::vec3& force);
    
private:
    glm::vec3 position; // 3D coordinates (meters)
    glm::vec3 appliedForce; // Force vector (Newtons)
    bool fixed = false; // Fixed support constraint
};
