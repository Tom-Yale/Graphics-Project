#pragma once
#include <vector>
#include "Content\Sample3DSceneRenderer.h"
ref class SkyBox
{
public:
	ID3D11Buffer* sphereIndexBuffer;
	ID3D11Buffer* sphereVertexBuffer;

	ID3D11VertexShader* SKY_VS;
	ID3D11PixelShader* SKY_PS;
	ID3D10Blob* SKY_VS_Buffer;
	ID3D10Blob* SKY_PS_Buffer;

	ID3D11ShaderResourceView* Sky_resource_view;

	ID3D11DepthStencilState* DSLessEqual;
	ID3D11RasterizerState* RSCullNone;

	int NumOfSphereVertices;
	int NumOfSphereFaces;

	XMMATRIX sphereWorld;

	SkyBox();
	void Init();
	void CreateSphere(int Longitude, int Latitude);
	void CleanUp();
};

