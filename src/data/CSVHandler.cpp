#include "data/CSVHandler.hpp"
#include <fstream>
#include <sstream>

void CSVHandler::loadStructure(const std::string& path, 
                             std::vector<Node>& nodes,
                             std::vector<Beam>& beams) {
    std::ifstream file(path);
    std::string line;
    
    // Node format: x,y,z,fixed (0/1)
    // Beam format: start_index,end_index,youngs_modulus,cross_section
    while (getline(file, line)) {
        std::stringstream ss(line);
        std::string type;
        ss >> type;
        
        if (type == "NODE") {
            float x, y, z;
            int fixed;
            ss >> x >> y >> z >> fixed;
            
            nodes.emplace_back(x, y, z);
            nodes.back().setFixed(fixed);
        } 
        else if (type == "BEAM") {
            int startIdx, endIdx;
            float E, A;
            ss >> startIdx >> endIdx >> E >> A;
            
            beams.emplace_back(&nodes[startIdx], &nodes[endIdx], E, A);
        }
    }
}

void CSVHandler::saveStructure(const std::string& path, 
                             const std::vector<Node>& nodes,
                             const std::vector<Beam>& beams) {
    std::ofstream file(path);
    
    for (const auto& node : nodes) {
        file << "NODE " << node.getPosition().x << " " 
             << node.getPosition().y << " " 
             << node.getPosition().z << " " 
             << (node.isFixed() ? 1 : 0) << "\n";
    }
    
    for (const auto& beam : beams) {
        file << "BEAM " << beam.getStart() - &nodes[0] << " " 
             << beam.getEnd() - &nodes[0] << " " 
             << beam.getStiffness() << " " 
             << beam.getLength() << "\n";
    }
}
