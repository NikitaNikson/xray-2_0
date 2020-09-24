#include "common.h"

struct v_terrain
{
	float4 hpos : POSITION;
	float3 normal : NORMAL;

	half4 c1 : COLOR0;
	half4 c2 : COLOR1;
	
	float2 tc1 : TEXCOORD0;
	float2 tc2 : TEXCOORD1;
	float2 tc3 : TEXCOORD2;
	float4 tex : TEXCOORD3;
};
/*
struct o_terrain
{
	float4 hpos 	: POSITION;

	half4 c1 	: COLOR0;
	half4 c2 	: COLOR1;
	
	float2 tc1 	: TEXCOORD0;
	float2 tc2 	: TEXCOORD1;
	float2 tc3 	: TEXCOORD2;
	float4 tex	: TEXCOORD3;
	float4 position : TEXCOORD4;
	half3 N 	: TEXCOORD5;
};
*/
struct o_terrain
{
	float4 hpos 	: SV_Position;

	half4  c1 		: COLOR0;
	half4  c2 		: COLOR1;
	
	float2 tc1 		: TEXCOORD0;
	float4 tex		: TEXCOORD1;
	float4 position : TEXCOORD2;
	half3  N 		: TEXCOORD3;
};

o_terrain main(v_terrain i)
{
	o_terrain o;

	o.hpos 		= mul(m_WVP, i.hpos);

	o.N 		= mul(m_WV, i.normal);
	float3	Pe	= mul(m_WV, i.hpos);
	o.position 	= float4(Pe,/*i.normal.w*/1);

	//copy colors and texture coordinates
	o.c1 = i.c1;
	o.c2 = i.c2;

	o.tc1 = i.tc1;
	o.tex = i.tex;

	return o;
}
FXVS;
