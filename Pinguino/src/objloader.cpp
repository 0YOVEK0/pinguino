#include "objloader.h"

bool OBJLoader::Load(const std::string& filename, std::vector<Vertex>& vertices, std::vector<unsigned int>& indices)
{
    std::ifstream file(filename);
    if (!file.is_open())
    {
        std::cerr << "Error: Couldn't open OBJ file: " << filename << std::endl;
        return false;
    }

    std::vector<XMFLOAT3> positions;
    std::vector<XMFLOAT2> texCoords;
    std::vector<unsigned int> posIndices, texCoordIndices;

    std::string line;
    while (std::getline(file, line))
    {
        std::istringstream iss(line);
        std::string prefix;
        iss >> prefix;

        if (prefix == "v")
        {
            XMFLOAT3 pos;
            iss >> pos.x >> pos.y >> pos.z;
            positions.push_back(pos);
        }
        else if (prefix == "vt")
        {
            XMFLOAT2 texCoord;
            iss >> texCoord.x >> texCoord.y;
            texCoords.push_back(texCoord);
        }
        else if (prefix == "f")
        {
            unsigned int vertexIndex[3], texCoordIndex[3];
            char slash;
            for (int i = 0; i < 3; ++i)
            {
                iss >> vertexIndex[i] >> slash >> texCoordIndex[i];
                posIndices.push_back(vertexIndex[i]);
                texCoordIndices.push_back(texCoordIndex[i]);
            }
        }
    }

    for (size_t i = 0; i < posIndices.size(); ++i)
    {
        unsigned int posIndex = posIndices[i];
        unsigned int texCoordIndex = texCoordIndices[i];
        XMFLOAT3 pos = positions[posIndex - 1];
        XMFLOAT2 texCoord = texCoords[texCoordIndex - 1];
        vertices.push_back({ pos, texCoord });
        indices.push_back(static_cast<unsigned int>(i));
    }

    return true;
}
