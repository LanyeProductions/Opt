#pragma once

class CeresWarpingSolver {
public:
	CeresWarpingSolver(SimpleMesh &_mesh)
	{
        vertexCount = (int)_mesh.n_vertices();
		edgeCount = (int)_mesh.n_edges();
        mesh = &_mesh;

        vertexPosDouble3 = new double3[_mesh.n_vertices() * 3];
        anglesDouble3 = new double3[_mesh.n_vertices() * 3];
	}

    float solveGN(
        float3* vertexPosFloat3,
        float3* anglesFloat3,
        float3* vertexPosFloat3Urshape,
        float3* vertexPosTargetFloat3,
        float weightFit,
        float weightReg);

private:
    int vertexCount, edgeCount;

    double3* vertexPosDouble3;
    double3* anglesDouble3;

    SimpleMesh *mesh;
};

#ifndef USE_CERES
inline float CeresWarpingSolver::solveGN(
    float3* vertexPosFloat3,
    float3* anglesFloat3,
    float3* vertexPosFloat3Urshape,
    float3* vertexPosTargetFloat3,
    float weightFit,
    float weightReg)
{
    return 0.0f;
}

#endif