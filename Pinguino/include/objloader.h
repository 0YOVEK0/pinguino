#pragma once

#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <Windows.h>
#include <d3d11.h>
#include <xnamath.h>

struct Vertex
{
    XMFLOAT3 position;
    XMFLOAT2 texCoord;
};

class OBJLoader
{
public:
    static bool Load(const std::string& filename, std::vector<Vertex>& vertices, std::vector<unsigned int>& indices);
};