﻿#pragma once

#include "..\Common\DeviceResources.h"
#include "ShaderStructures.h"
#include "..\Common\StepTimer.h"
#include "..\ObjectLoader.h"


namespace DX11UWA
{
	// This sample renderer instantiates a basic rendering pipeline.
	class Sample3DSceneRenderer
	{
	public:
		Sample3DSceneRenderer(const std::shared_ptr<DX::DeviceResources>& deviceResources);
		void CreateDeviceDependentResources(void);
		void CreateWindowSizeDependentResources(void);
		void ReleaseDeviceDependentResources(void);
		void Update(DX::StepTimer const& timer);
		void Render(void);
		void StartTracking(void);
		void TrackingUpdate(float positionX);
		void StopTracking(void);
		inline bool IsTracking(void) { return m_tracking; }

		//skybox creation
		
	private:
		Microsoft::WRL::ComPtr<ID3D11Buffer> sphereIndexBuffer;
		Microsoft::WRL::ComPtr<ID3D11Buffer> sphereVertexBuffer;
		Microsoft::WRL::ComPtr<ID3D11VertexShader>	sky_vertexShader;
		Microsoft::WRL::ComPtr<ID3D11PixelShader> sky_pixelShader;

		ID3D11VertexShader* SKY_VS;
		ID3D11PixelShader* SKY_PS;

		//ModelViewProjectionConstantBuffer sky_constantBufferData;


		Microsoft::WRL::ComPtr<ID3D11ShaderResourceView> Sky_resource_view;

		Microsoft::WRL::ComPtr<ID3D11DepthStencilState> DSLessEqual;
		Microsoft::WRL::ComPtr<ID3D11RasterizerState> RSCcullNone;
		//Microsoft::WRL::ComPtr<ID3D11RasterizerState> RSCCcullNone;

		Microsoft::WRL::ComPtr<ID3D11RasterizerState> CCWcullMode;
		Microsoft::WRL::ComPtr<ID3D11RasterizerState> CWcullMode;
		XMMATRIX Scale;
		XMMATRIX Translation;
		Microsoft::WRL::ComPtr<ID3D11SamplerState> SkySamplerState;


	public:
		// Helper functions for keyboard and mouse input
		void SetKeyboardButtons(const char* list);
		void SetMousePosition(const Windows::UI::Input::PointerPoint^ pos);
		void SetInputDeviceData(const char* kb, const Windows::UI::Input::PointerPoint^ pos);


	private:
		void Rotate(float radians);
		void UpdateCamera(DX::StepTimer const& timer, float const moveSpd, float const rotSpd);

	private:
		// Cached pointer to device resources.
		std::shared_ptr<DX::DeviceResources> m_deviceResources;

		// Direct3D resources for cube geometry.
		Microsoft::WRL::ComPtr<ID3D11InputLayout>	m_inputLayout;
		Microsoft::WRL::ComPtr<ID3D11Buffer>		m_vertexBuffer;
		Microsoft::WRL::ComPtr<ID3D11Buffer>		m_indexBuffer;
		Microsoft::WRL::ComPtr<ID3D11VertexShader>	m_vertexShader;
		Microsoft::WRL::ComPtr<ID3D11PixelShader>	m_pixelShader;
		Microsoft::WRL::ComPtr<ID3D11Buffer>		m_constantBuffer;


		//Floor plane resources 
		Microsoft::WRL::ComPtr<ID3D11Buffer> floor_vertexBuffer;
		Microsoft::WRL::ComPtr<ID3D11Buffer> floor_indexBuffer;
		Microsoft::WRL::ComPtr<ID3D11Buffer> floor_constantBuffer;
		Microsoft::WRL::ComPtr<ID3D11SamplerState> FloorSamplerState;
		Microsoft::WRL::ComPtr<ID3D11ShaderResourceView> FloorResourceView;

		ModelViewProjectionConstantBuffer floor_constantBufferData;
		uint32 floor_indexCount;

		bool floor_loadingComplete;
		//Lamp resources
		Microsoft::WRL::ComPtr<ID3D11InputLayout>	my_inputLayout;
		Microsoft::WRL::ComPtr<ID3D11VertexShader>	my_vertexShader;
		Microsoft::WRL::ComPtr<ID3D11PixelShader>	my_pixelShader;

		Microsoft::WRL::ComPtr<ID3D11Buffer> lamp_vertexBuffer;
		Microsoft::WRL::ComPtr<ID3D11Buffer> lamp_indexBuffer;
		Microsoft::WRL::ComPtr<ID3D11Buffer> lamp_constantBuffer;
		ObjectLoader ObjectLoad;

		ModelViewProjectionConstantBuffer lamp_constantBufferData;
		uint32 lamp_indexCount;

		//Object1 reaources
		Microsoft::WRL::ComPtr<ID3D11Buffer> object1_vertexBuffer;
		Microsoft::WRL::ComPtr<ID3D11Buffer> object1_indexBuffer;
		Microsoft::WRL::ComPtr<ID3D11Buffer> object1_constantBuffer;
		ModelViewProjectionConstantBuffer object1_constantBufferData;
		Microsoft::WRL::ComPtr<ID3D11SamplerState> object1SamplerState;
		Microsoft::WRL::ComPtr<ID3D11ShaderResourceView> object1ResourceView;
		uint32 object1_indexCount;

		//Sphere
		Microsoft::WRL::ComPtr<ID3D11Buffer> sky_vertexBuffer;
		Microsoft::WRL::ComPtr<ID3D11Buffer> sky_indexBuffer;
		Microsoft::WRL::ComPtr<ID3D11Buffer> sky_constantBuffer;

		ModelViewProjectionConstantBuffer sky_constantBufferData;
		uint32 sky_indexCount;



		bool lamp_loadingComplete;
		// System resources for cube geometry.
		ModelViewProjectionConstantBuffer	m_constantBufferData;
		uint32	m_indexCount;

		// Variables used with the rendering loop.
		bool	m_loadingComplete;
		float	m_degreesPerSecond;
		bool	m_tracking;

		// Data members for keyboard and mouse input
		char	m_kbuttons[256];
		Windows::UI::Input::PointerPoint^ m_currMousePos;
		Windows::UI::Input::PointerPoint^ m_prevMousePos;

		// Matrix data member for the camera
		DirectX::XMFLOAT4X4 m_camera;
	};
}

