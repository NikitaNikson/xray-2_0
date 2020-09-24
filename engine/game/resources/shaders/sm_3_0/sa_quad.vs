#include "common.h"
	
v2p_TL main ( v_TL i)
{					
	v2p_TL result;	
	result.HPos = float4(i.P.xyz,1);
	result.Color = i.Color;
	result.Tex0 = i.Tex0;
	return result;	
}			