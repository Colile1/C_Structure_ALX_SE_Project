#include <gtest/gtest.h>
#include "model/Node.hpp"
#include "model/Beam.hpp"

TEST(NodeTest, PositionAndForces) {
    Node node(1.0f, 2.0f, 3.0f);
    ASSERT_FLOAT_EQ(node.getPosition().x, 1.0f);
    node.applyForce(glm::vec3(100, 0, 0));
    // Test force accumulation logic
}

TEST(BeamTest, StiffnessCalculation) {
    Node n1(0, 0, 0), n2(3, 0, 0);
    Beam beam(&n1, &n2, 2e11f, 0.01f); // E=200GPa, A=0.01m²
    ASSERT_NEAR(beam.getStiffness(), (2e11 * 0.01) / 3.0, 1e-6);
}
