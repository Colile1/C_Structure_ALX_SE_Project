#pragma once
#include <Eigen/Sparse>
#include <vector>
#include "model/Node.hpp"
#include "model/Beam.hpp"
#include <Eigen/Sparse>

class Simulator {
public:
    Simulator(const std::vector<Node>& nodes, const std::vector<Beam>& beams);
    
    void solve(); // Solve for displacements
    Eigen::VectorXd getDisplacements() const;
    Eigen::VectorXd getForces() const;

private:
    void assembleStiffnessMatrix();
    void applyBoundaryConditions();

    const std::vector<Node>& nodes;
    const std::vector<Beam>& beams;
    
    Eigen::SparseMatrix<double> stiffnessMatrix;
    Eigen::VectorXd displacements;
    Eigen::VectorXd forces;
};
