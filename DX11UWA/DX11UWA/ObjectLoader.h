#pragma once
#include <vector>
using namespace std;
using namespace DirectX;

class ObjectLoader
{
public:
	struct Vertex
	{
		XMFLOAT4 position;
		XMFLOAT4 uv;
		XMFLOAT4 normals;
	};

	ObjectLoader();
	

	bool ObjLoad(const char * path, vector<Vertex> & out_vertices, vector<UINT> & out_indices);
};

