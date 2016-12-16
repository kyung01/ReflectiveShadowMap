
#include "deffered_indirect.hlsl"

cbuffer global00 :register(b0)
{
	float isDisplayFailedPixels;
};
Texture2D textureDirectLight	: register(t0);
Texture2D textureIndirectLight		: register(t1);
Texture2D textureUI		: register(t2);
Texture2D textureFailedPixels		: register(t3);

SamplerState samplerDefault	: register(s0);

struct VertexToPixel
{
	float4 position		: SV_POSITION;
	float2 uv			: TEXCOORD;
};
// Out of the vertex shader (and eventually input to the PS)



float4 main(VertexToPixel input) : SV_TARGET
{
	float4 colorUI = textureUI.Sample(samplerDefault, input.uv);
	float4 colorFail = textureFailedPixels.Sample(samplerDefault, input.uv);
	float4 color =
		textureDirectLight.Sample(samplerDefault, input.uv)
		+ textureIndirectLight.Sample(samplerDefault, input.uv);
	return float4(
		saturate(color.xyz * (1 - colorUI.w) + colorUI.xyz * colorUI.w  
			+ float3(colorFail.x, -.5 * colorFail.x, -.5 * colorFail.x) * isDisplayFailedPixels
		)
		 , 1);
}