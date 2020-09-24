//#include "common.h"

struct v_TL
{
	float4 P : POSITION;
	float4 C : COLOR;
};

struct v2p_TL
{
	float4 C : COLOR;
	float4 P : SV_Position;
};

//////////////////////////////////////////////////////////////////////////////////////////
// Vertex
v2p_TL main ( v_TL I)
{
	v2p_TL O;

	O.C = I.C;
	O.P = I.P;	

 	return O;
}