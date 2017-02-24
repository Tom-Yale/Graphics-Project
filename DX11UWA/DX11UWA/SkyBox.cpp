#include "pch.h"
#include "SkyBox.h"


SkyBox::SkyBox()
{

}

void SkyBox::Init()
{

}

void SkyBox::CreateSphere(int Longitude, int Latitude)
{
	XMMATRIX RotationX;
	XMMATRIX RotationY;
	XMMATRIX RotationZ;
	HRESULT Hresult;

	NumOfSphereVertices = ((Latitude - 2) * Longitude) + 2;
	NumOfSphereFaces = ((Latitude - 3)* (Longitude) * 2) + (Longitude * 2);


	float Yaw = 0.0f;
	float Pitch = 0.0f;

	vector<ObjectLoader::Vertex> vertices(NumOfSphereVertices);

	XMVECTOR currVertexPosition = XMVectorSet(0.0f, 0.0f, 1.0f, 0.0f);

	vertices[0].position.x = 0.0f; vertices[0].position.y = 0.0f; vertices[0].position.z = 1.0f;

	for (unsigned long i = 0; i < Latitude - 2; i++)
	{
		Pitch = (i + 1) * (3.14 / (Latitude - 1));
		RotationX = XMMatrixRotationX(Pitch);
		for  (unsigned long j = 0; j < Longitude; j++)
		{
			Yaw = j * (6.28 / (Longitude));
			RotationY = XMMatrixRotationX(Yaw);
			currVertexPosition = XMVector3TransformNormal(XMVectorSet(0.0f, 0.0f, 1.0f, 0.0f), (RotationX * RotationY));
			currVertexPosition = XMVector3Normalize(currVertexPosition);
			vertices[i*Longitude + j + 1].position.x = XMVectorGetX(currVertexPosition);
			vertices[i*Longitude + j + 1].position.y = XMVectorGetY(currVertexPosition);
			vertices[i*Longitude + j + 1].position.z = XMVectorGetZ(currVertexPosition);
		}
	}

	vertices[NumOfSphereVertices - 1].position.x = 0.0f;
	vertices[NumOfSphereVertices - 1].position.y = 0.0f;
	vertices[NumOfSphereVertices - 1].position.z = -1.0f;

	D3D11_BUFFER_DESC vertexBufferDesc;
	ZeroMemory(&vertexBufferDesc, sizeof(vertexBufferDesc));
	vertexBufferDesc.Usage = D3D11_USAGE_DEFAULT;
	vertexBufferDesc.ByteWidth = sizeof(ObjectLoader::Vertex) * NumOfSphereVertices;
	vertexBufferDesc.CPUAccessFlags = 0;
	vertexBufferDesc.MiscFlags = 0;
	vertexBufferDesc.BindFlags = D3D11_BIND_VERTEX_BUFFER;

	D3D11_SUBRESOURCE_DATA vertexBufferData;
	ZeroMemory(&vertexBufferData, sizeof(vertexBufferData));
	vertexBufferData.pSysMem = &vertices[0];
	//Hresult = 

}

void SkyBox::CleanUp()
{
	SKY_VS->Release();
	SKY_PS->Release();
	SKY_VS_Buffer->Release();
	SKY_PS_Buffer->Release();
	Sky_resource_view->Release();
	DSLessEqual->Release();
	RSCullNone->Release();
}
