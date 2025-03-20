#pragma once
#include "Node.hpp"

class Beam {
public:
    Beam(Node* start, Node* end, float youngsModulus, float crossSection);
    
    Node* getStart() const;
    Node* getEnd() const;
    float getLength() const;
    float getStiffness() const; // AE/L
    
private:
    Node* startNode;
    Node* endNode;
    float youngsModulus; // Material property (Pa)
    float crossSection; // Area (m²)
};
