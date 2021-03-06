#if 0
//
// Generated by 2.0.7776.0
//
//   fxc /T ps_1_1 /E PS_CxformGauraudMultiplyNoAddAlpha scaleform.hlsl /Fh
//    PS_CxformGauraudMultiplyNoAddAlpha.hlsl.h
//
//
// Parameters:
//
//   float4 cxadd;
//   float4 cxmul;
//
//
// Registers:
//
//   Name         Reg   Size
//   ------------ ----- ----
//   cxmul        c2       1
//   cxadd        c3       1
//

// Shader type: pixel 

xps_3_0
defconst cxadd, float, vector, [1, 4], c3
defconst cxmul, float, vector, [1, 4], c2
config AutoSerialize=false
config AutoResource=false
config PsMaxReg=2
// PsExportColorCount=1

dcl_color_centroid r0

def c252, 0, 0, 0, 0
def c253, 0, 0, 0, 0
def c254, 0, 0, 0, 0
def c255, -1, 1, 0, 0


    alloc colors
    exece
    mul r1, r0, c2
    add r2.xyz, c3.xyz, c255.x
  + movs r0.y, r1.w
    add r0.x, r1.w, c255.x
  + addsc r0.y, c3.w, r0.y
    add r1.xyz, r2.xyz, r1.xyz
  + addsc r1.w, c3.w, r0.x
    mad oC0, r1, r0.y, c255.y

// PDB hint 00000000-00000000-00000000

#endif

// This microcode is in native DWORD byte order.

const DWORD g_xps_PS_CxformGauraudMultiplyNoAddAlpha[] =
{
    0x102a1100, 0x000000e8, 0x00000094, 0x00000000, 0x00000024, 0x0000009c, 
    0x000000c4, 0x00000000, 0x00000000, 0x00000074, 0x0000001c, 0x00000069, 
    0xffff0300, 0x00000002, 0x0000001c, 0x00000000, 0x00000062, 0x00000044, 
    0x00020003, 0x00010000, 0x0000004c, 0x00000000, 0x0000005c, 0x00020002, 
    0x00010000, 0x0000004c, 0x00000000, 0x63786164, 0x6400abab, 0x00010003, 
    0x00010004, 0x00010000, 0x00000000, 0x63786d75, 0x6c007073, 0x5f335f30, 
    0x00322e30, 0x2e373737, 0x362e3000, 0x00000000, 0x00000001, 0x00000000, 
    0x00000000, 0x00000014, 0x01fc0010, 0x00000000, 0x00000000, 0x00000000, 
    0x00000000, 0x00000040, 0x00000054, 0x10000200, 0x00000000, 0x00000000, 
    0x00001021, 0x00000001, 0x00000001, 0x0000f0a0, 0x00000000, 0x00000000, 
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0xbf800000, 0x3f800000, 
    0x00000000, 0x00000000, 0x00000000, 0x5001c400, 0x22000000, 0xc80f0001, 
    0x00000000, 0xa1000200, 0x14270002, 0x00c06c1b, 0x2003ff01, 0xb0210000, 
    0x001b6c01, 0x8001ff03, 0xb0870101, 0x00c0c000, 0xc0020103, 0xc80f8000, 
    0x0000b1b1, 0xcb0100ff, 0x00000000, 0x00000000, 0x00000000
};
