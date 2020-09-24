#include "common.h"

struct vf
{
	float4 P: POSITION	;
	float4 C: COLOR0	;
};

vf main (vf i)
{
	vf o;
	o.P = mul(m_WVP, i.P); // xform, input in world coords
//	o.C = i.C;
	o.C = float4(1,1,1,1);

	return o;
}
