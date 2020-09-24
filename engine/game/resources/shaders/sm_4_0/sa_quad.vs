struct _out
{
	float2 tc : TEXCOORD;
	float4 P : SV_Position;
};

_out main ( float2 P : POSITIONT, float2 tc : TEXCOORD )
{
	_out o;

	o.tc = tc;
	o.P = float4(P,0,1);

	return o;
}