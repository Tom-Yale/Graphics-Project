#include "pch.h"
#include "ObjectLoader.h"


ObjectLoader::ObjectLoader()
{
}

bool ObjectLoader::ObjLoad(const char * path,
	vector<Vertex> & out_vertices, vector<UINT> & out_indices)
{
	vector<unsigned int> vertexIndices, uvIndices, normalIndices;
	vector<XMFLOAT4> temp_uvs;
	vector<XMFLOAT4> temp_vertices, temp_normals;

	FILE * file;
	fopen_s(&file, path, "r");
	if (file == NULL)
	{
		printf("cannot open file");
		return false;
	}

	while (true)
	{
		char lineHeader[128];
		int res = fscanf_s(file, "%s", lineHeader, 128);
		if (res == EOF)
			break;

		if (strcmp(lineHeader, "v") == 0)
		{
			XMFLOAT4 vertex;
			fscanf_s(file, "%f %f %f\n", &vertex.x, &vertex.y, &vertex.z);
			temp_vertices.push_back(vertex);
		}
		else if (strcmp(lineHeader, "vt") == 0)
		{
			XMFLOAT4 uv;
			fscanf_s(file, "%f %f\n", &uv.x, &uv.y);
			uv.y = 1 - uv.y;
			temp_uvs.push_back(uv);
		}
		else if (strcmp(lineHeader, "vn") == 0)
		{
			XMFLOAT4 normal;
			fscanf_s(file, "%f %f %f\n", &normal.x, &normal.y, &normal.z);
			temp_normals.push_back(normal);
		}
		else if (strcmp(lineHeader, "f") == 0)
		{
			string vertex1, vertex2, vertex3;
			unsigned int vertexIndex[3], uvIndex[3], normalIndex[3];
			int matches = fscanf_s(file, "%d/%d/%d %d/%d/%d %d/%d/%d\n", &vertexIndex[0],
				&uvIndex[0], &normalIndex[0], &vertexIndex[1], &uvIndex[1], &normalIndex[1],
				&vertexIndex[2], &uvIndex[2], &normalIndex[2]);
			if (matches != 9)
			{
				printf("File cannot be read by parser");
				return false;
			}
			for (size_t i = 0; i < 3; i++)
			{
				vertexIndices.push_back(vertexIndex[i]);
				uvIndices.push_back(uvIndex[i]);
				normalIndices.push_back(normalIndex[i]);
			}
		}
	}
		for (size_t i = 0; i < vertexIndices.size(); i++)
		{
			Vertex v;
			unsigned int vertexIndex = vertexIndices[i], uvIndex = uvIndices[i], normalIndex = normalIndices[i];

			XMFLOAT4 vertex = temp_vertices[vertexIndex - 1];
			XMFLOAT4 uv = temp_uvs[uvIndex - 1];
			XMFLOAT4 normal = temp_normals[normalIndex - 1];
			v.position = vertex;
			v.uv = uv;
			v.normals = normal;
			out_vertices.push_back(v);
			out_indices.push_back(i);

		}	
		vertexIndices.clear();
		uvIndices.clear();
		normalIndices.clear();
		temp_vertices.clear();
		temp_uvs.clear();
		temp_normals.clear();

}
