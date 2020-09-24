#include "common.h"

//////////////////////////////////////////////////////////////////////////////////////////
// Vertex
v2p_TL0uv main ( v_TL0uv I)
{
	v2p_TL0uv O;

	O.HPos = mul( m_WVP, I.P);
	O.Color = I.Color.bgra;	//	swizzle vertex colour

 	return O;
}