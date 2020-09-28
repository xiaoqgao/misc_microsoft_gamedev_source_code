#if 0
//
// Generated by 2.0.7776.0
//
//   fxc /T vs_2_0 /E VSFixedFunc /D DIFFUSE /D UV0 /D UV1
//    fixedFuncShaders.hlsl /Fh fixedFuncVSPosDiffuseTex2.hlsl.h /Vn
//    g_xvs_PosDiffuseTex2VS
//
//
// Parameters:
//
//   float4x4 gWorldViewProjMatrix;
//
//
// Registers:
//
//   Name                 Reg   Size
//   -------------------- ----- ----
//   gWorldViewProjMatrix c0       4
//

// Shader type: vertex 

xvs_3_0
defconst gWorldViewProjMatrix, float, matrix_columns, [4, 4], c0-3
config AutoSerialize=false
config AutoResource=false
config VsMaxReg=3
config VsResource=1
// VsExportCount=2

dcl_index r0.x
dcl_texcoord o0
dcl_texcoord1 o1
dcl_color o2


    exec
    vfetch r3, r0.x, position
    vfetch r2, r0.x, color
    vfetch r1, r0.x, texcoord
    vfetch r0, r0.x, texcoord1
    alloc position
    exec
    dp4 oPos.x, r3.wzxy, c0.wzxy
    dp4 oPos.y, r3.wzxy, c1.wzxy
    dp4 oPos.z, r3.wzxy, c2.wzxy
    dp4 oPos.w, r3.wzxy, c3.wzxy
    alloc interpolators
    exece
    mov o2, r2
    mov o0, r1
    mov o1, r0

// PDB hint 00000000-00000000-00000000

#endif

// This microcode is in native DWORD byte order.

const DWORD g_xvs_PosDiffuseTex2VS[] =
{
    0x102a1101, 0x000000e4, 0x000000b4, 0x00000000, 0x00000024, 0x00000000, 
    0x00000094, 0x00000000, 0x00000000, 0x0000006c, 0x0000001c, 0x0000005f, 
    0xfffe0300, 0x00000001, 0x0000001c, 0x00000000, 0x00000058, 0x00000030, 
    0x00020000, 0x00040000, 0x00000048, 0x00000000, 0x67576f72, 0x6c645669, 
    0x65775072, 0x6f6a4d61, 0x74726978, 0x00ababab, 0x00030003, 0x00040004, 
    0x00010000, 0x00000000, 0x76735f33, 0x5f300032, 0x2e302e37, 0x3737362e, 
    0x3000abab, 0x00000000, 0x000000b4, 0x00210003, 0x00000000, 0x00000000, 
    0x00003063, 0x00000001, 0x00000004, 0x00000003, 0x00000290, 0x00100003, 
    0x0000a004, 0x00005005, 0x00315006, 0x0000f050, 0x0001f151, 0x0002f2a0, 
    0x0000100c, 0x0000100d, 0x0000100b, 0xf0554003, 0x00001200, 0xc2000000, 
    0x00004007, 0x00001200, 0xc4000000, 0x0000300b, 0x00002200, 0x00000000, 
    0x05f83000, 0x00000688, 0x00000000, 0x05f82000, 0x00000688, 0x00000000, 
    0x05f81000, 0x00000688, 0x00000000, 0x05f80000, 0x00000688, 0x00000000, 
    0xc801803e, 0x00a7a700, 0xaf030000, 0xc802803e, 0x00a7a700, 0xaf030100, 
    0xc804803e, 0x00a7a700, 0xaf030200, 0xc808803e, 0x00a7a700, 0xaf030300, 
    0xc80f8002, 0x00000000, 0xe2020200, 0xc80f8000, 0x00000000, 0xe2010100, 
    0xc80f8001, 0x00000000, 0xe2000000, 0x00000000, 0x00000000, 0x00000000
};