#include "common.h"

struct v_terrain
{
	float4 hpos : POSITION;
	float4 normal : NORMAL;

	half4 c1 : COLOR0;
	half4 c2 : COLOR1;
	
	float2 tc1 : TEXCOORD0;
	float2 tc2 : TEXCOORD1;
	float2 tc3 : TEXCOORD2;
	int4   tex : TEXCOORD3;
};

struct o_terrain
{
	float4 hpos 	: POSITION;

	half4 c1 	: COLOR0;
	half4 c2 	: COLOR1;
	
	float2 tc1 	: TEXCOORD0;
	float2 tc2 	: TEXCOORD1;
	float2 tc3 	: TEXCOORD2;
	int4   tex	: TEXCOORD3;
	float4 position : TEXCOORD4;
	half3 N 	: TEXCOORD5;
};

o_terrain main(v_terrain i)
{
	o_terrain o;

	o.hpos 		= mul(m_WVP, i.hpos);

	o.N 		= mul(m_WV,unpack_bx2(i.normal));
	float3	Pe	= mul(m_WV, i.hpos);
	o.position 	= float4(Pe,i.normal.w);

	//copy colors and texture coordinates
	o.c1 = i.c1;
	o.c2 = i.c2;

	o.tc1 = i.tc1;
	o.tc2 = i.tc2;
	o.tc3 = i.tc3;
	o.tex = i.tex;

	return o;
}
FXVS;
