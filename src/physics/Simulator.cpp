#include "physics/Simulator.hpp"
#include <Eigen/Sparse>
#include <iostream>



Simulator::Simulator(const std::vector<Node>& nodes, const std::vector<Beam>& beams)
    : nodes(nodes), beams(beams) {
    stiffnessMatrix.resize(3 * nodes.size(), 3 * nodes.size());
    displacements.resize(3 * nodes.size());
    forces.resize(3 * nodes.size());
    assembleStiffnessMatrix();
    applyBoundaryConditions();
}

void Simulator::assembleStiffnessMatrix() {
    stiffnessMatrix.setZero(); // Initialize the stiffness matrix
    stiffnessMatrix.setZero(); // Initialize the stiffness matrix
    stiffnessMatrix.setZero(); // Initialize the stiffness matrix
    // For each beam, add its contribution to the global stiffness matrix
    for (const auto& beam : beams) {
        int startIdx = std::distance(&nodes[0], beam.getStart());
        int endIdx = std::distance(&nodes[0], beam.getEnd());
        
        // Local stiffness matrix (6x6 for 3D)
        Eigen::MatrixXd localK = Eigen::MatrixXd::Zero(6, 6); // Placeholder for local stiffness matrix
        
        // Add to global matrix
        stiffnessMatrix.block<3, 3>(3 * startIdx, 3 * startIdx) += localK.block<3, 3>(0, 0);
        stiffnessMatrix.block<3, 3>(3 * startIdx, 3 * endIdx) += localK.block<3, 3>(0, 3);
        stiffnessMatrix.block<3, 3>(3 * endIdx, 3 * startIdx) += localK.block<3, 3>(3, 0);
        stiffnessMatrix.block<3, 3>(3 * endIdx, 3 * endIdx) += localK.block<3, 3>(3, 3);
    }
}

void Simulator::applyBoundaryConditions() {
    // Zero out rows/columns for fixed nodes
    for (size_t i = 0; i < nodes.size(); ++i) {
        if (nodes[i].isFixed()) {
            for (int j = 0; j < 3; ++j) {
                stiffnessMatrix.row(3 * i + j).setZero();
                stiffnessMatrix.col(3 * i + j).setZero();
                stiffnessMatrix.coeffRef(3 * i + j, 3 * i + j) = 1.0;
            }
        }
    }
}

void Simulator::solve() {
    Eigen::ConjugateGradient<Eigen::SparseMatrix<double>> solver;
    solver.compute(stiffnessMatrix);
    displacements = solver.solve(forces);
}

Eigen::VectorXd Simulator::getDisplacements() const {
    return displacements;
}

Eigen::VectorXd Simulator::getForces() const {
    return forces;
}
