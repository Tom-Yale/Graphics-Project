// Per-pixel color data passed through the pixel shader.
struct PixelShaderInput
{
	float4 pos : SV_POSITION;
	float4 uv : UV;
	float4 norm : NORMALS;
};

Texture2D objectTexture : register (t0);
SamplerState ObjectSamplerState : register(s0);
// A pass-through function for the (interpolated) color data.
float4 main(PixelShaderInput input) : SV_TARGET
{
	//return float4(input.uv.xyz, 1.0f);
	return objectTexture.Sample(ObjectSamplerState, input.uv.xyz);
}