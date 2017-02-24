// Per-pixel color data passed through the pixel shader.
struct PixelShaderInput
{
	float4 pos : SV_POSITION;
	float3 uv : UV;
};

Texture2D object2DTexture : register (t0);
SamplerState FloorSamplerState : register(s0);
// A pass-through function for the (interpolated) color data.
float4 main(PixelShaderInput input) : SV_TARGET
{
	return object2DTexture.Sample(FloorSamplerState, input.uv.xyz); //return float4(input.uv, 1.0f);
}
