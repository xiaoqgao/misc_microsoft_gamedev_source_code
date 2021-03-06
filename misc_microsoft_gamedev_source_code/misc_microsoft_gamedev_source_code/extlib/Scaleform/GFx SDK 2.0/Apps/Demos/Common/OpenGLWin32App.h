/**********************************************************************

Filename    :   OpenGLWin32App.h
Content     :   Simple OpenGL Win32 Application class
Created     :   
Authors     :   Michael Antonov
Copyright   :   (c) 2005-2006 Scaleform Corp. All Rights Reserved.

This file is provided AS IS with NO WARRANTY OF ANY KIND, INCLUDING 
THE WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR ANY PURPOSE.

**********************************************************************/

#ifndef INC_OGLWIN32APP_H
#define INC_OGLWIN32APP_H

#include <windows.h>

// ***** Open GL Includes

#include <gl/gl.h>
#include <gl/glu.h>
// These links can be downloaded and copied to the include directory:
// http://oss.sgi.com/projects/ogl-sample/ABI/glext.h
// http://oss.sgi.com/projects/ogl-sample/ABI/wglext.h
#include "glext.h"
#include "wglext.h"

// GFx Includes
#include "GTypes.h"



// ***** Application class

class OpenGLWin32App
{
public:

    // **** Public Interface

    OpenGLWin32App();
    ~OpenGLWin32App();
    
    // Creates a window & initializes the application class.
    // Returns 0 if window creation/initialization failed (the app should quit).
    bool            SetupWindow(const char *pname, SInt width, SInt height);

    // Message processing function to be called in the 
    // application loops until it returns 0, to indicate application being closed.
    bool            ProcessMessages();

    // Sleeps for the specified number of milliseconds or till message.
    void            SleepTillMessage(UInt32 ms);

    // This call cleans up the application and kills the window.
    // If not called explicitly, it will be called from the destructor.
    void            KillWindow();

    // Changes/sets window title
    void            SetWindowTitle(const char *ptitle);

    // Presents the data (swaps the back and front buffers)
    void            PresentFrame();

    // Resets the direct3D, return 1 if successful.
    // On successful reset, this function will call InitRenderer again.
    bool            RecreateRenderer();


    // *** Simple 2D painting and output, for displaying HUD/Stat overlays

    void            Clear(UInt32 color);
    // Initialize and restore 2D rendering view.
    // Push2DRenderView must be called before using 2D functions below,
    // while Pop2DRenderView MUST be called after it is finished.
    void            Push2DRenderView();
    void            Pop2DRenderView();
    // Draw a filled + blended rectangle.
    void            FillRect(SInt l, SInt t, SInt r, SInt b, UInt32 color);
    // Draw a text string (specify top-left corner of characters, NOT baseline)
    void            DrawText(SInt x, SInt y, const char *ptext, UInt32 color);
    // Compute text size that will be generated by DrawText
    void            CalcDrawTextSize(SInt *pw, SInt *ph, const char *ptext);

    // API-independednt toggle for wireframe rendering.
    void            SetWireframe(bool wireframeEnable);



    // *** Overrides

    // This override is called from SetupWindow to initialize OpenGL/Direct3D view
    virtual bool    InitRenderer();
    // Should/can be called every frame to prepare the render, user function
    virtual void    PrepareRendererForFrame();
    
    // Input overrides, invoked during the ProcessMessages call.
    virtual void    OnKey(UInt key, UInt info, bool downFlag);
    virtual void    OnChar(UInt32 wcharCode, UInt info);
    virtual void    OnMouseButton(UInt button, bool downFlag, SInt x, SInt y);
    virtual void    OnMouseWheel(SInt zdelta, SInt x, SInt y);
    virtual void    OnMouseMove(SInt x, SInt y);

    // Sizing; by default, re-initalizes the renderer
    virtual void    OnSize(SInt w, SInt h);
    // Called when sizing begins and ends.
    virtual void    OnSizeEnter(bool enterSize);
    // Handle dropped file
    virtual void    OnDropFiles(char *path);

    // Set cursor
    void            SetCursor(HCURSOR cursor);
    void            ShowCursor(bool show = true);
    void            ShowCursorInstantly(bool show);
    void            ResetCursor();

    // *** Implementation

    PFNGLMULTITEXCOORD2FARBPROC     pglMultiTexCoord2f;
    PFNGLCLIENTACTIVETEXTUREARBPROC pglActiveTexture;
    PFNGLACTIVETEXTUREARBPROC       pglClientActiveTexture;
    PFNGLPOINTPARAMETERFVEXTPROC    pglPointParameterfvEXT;
    PFNWGLSWAPINTERVALEXTPROC       pwglSwapIntervalEXT;

    mutable PFNGLBINDRENDERBUFFEREXTPROC                        p_glBindRenderbufferEXT;
    mutable PFNGLDELETERENDERBUFFERSEXTPROC                     p_glDeleteRenderBuffersEXT;
    mutable PFNGLGENRENDERBUFFERSEXTPROC                        p_glGenRenderbuffersEXT;
    mutable PFNGLBINDFRAMEBUFFEREXTPROC                         p_glBindFramebufferEXT;
    mutable PFNGLDELETEFRAMEBUFFERSEXTPROC                      p_glDeleteFramebuffersEXT;
    mutable PFNGLGENFRAMEBUFFERSEXTPROC                         p_glGenFramebuffersEXT;
    mutable PFNGLRENDERBUFFERSTORAGEEXTPROC                     p_glRenderbufferStorageEXT;
    mutable PFNGLFRAMEBUFFERTEXTURE2DEXTPROC                    p_glFramebufferTexture2DEXT;
    mutable PFNGLFRAMEBUFFERRENDERBUFFEREXTPROC                 p_glFramebufferRenderbufferEXT;
    mutable PFNGLGETFRAMEBUFFERATTACHMENTPARAMETERIVEXTPROC     p_glFramebufferAttachmentParameterivEXT;
    mutable PFNGLCHECKFRAMEBUFFERSTATUSEXTPROC                  p_glCheckFramebufferStatusEXT;

    // Boolean states for the window and app
    bool        Created;
    bool        Active; 
    bool        QuitFlag;
    SInt        ExitCode;
    // Cursor states
    bool        CursorHidden;
    bool        CursorHiddenSaved;
    bool        CursorDisabled;
    bool        CursorIsOutOfClientArea;
    // Set this if the window is to accept drag and drop
    bool        SupportDropFiles;
    bool        SizableWindow;
    
    // Requested 3D state
    bool        FullScreen;
    bool        FSAntialias;
    UInt        BitDepth;
    // This flag will be set after SetupWindow to indicate that FSAA is available.
    bool        FSAASupported;

    // Handles..
    HDC         hDC;
    HGLRC       hGLRC;
    HWND        hWND;
    HINSTANCE   hInstance;
    HCURSOR     hCursor;

    // Client size
    int         Width;
    int         Height;

    // Saved viewport
    GLint       ViewportSave[4];
    // OpenGL Text state
    enum {
        TextDisplayListBase         = 1000,
        TextDisplayListCharCount    = 255
    };
    // Text metric of the font.
    TEXTMETRIC TextMetric;
    // This flag is set if text lists were created successfully.
    bool        TextListsCreated;



    // Helpers
    bool        SetupPixelFormat();
//  bool InitializeExtensions();
//  bool CheckExtension(char* extensionName);

    // Member window procedure, used so that it can access locals
    virtual     LRESULT     MemberWndProc(UINT message, WPARAM wParam, LPARAM lParam);

    void  glBindRenderbufferEXT (GLenum t, GLuint rb) const
    {
        p_glBindRenderbufferEXT(t,rb);
    }

    void  glDeleteRenderbuffersEXT (GLsizei n, const GLuint *b) const
    {
        p_glDeleteRenderBuffersEXT(n,b);
    }

    void  glGenRenderbuffersEXT (GLsizei n, GLuint *b) const
    {
        p_glGenRenderbuffersEXT(n,b);
    }

    void  glRenderbufferStorageEXT (GLenum t, GLenum f, GLsizei w, GLsizei h)
    {
        p_glRenderbufferStorageEXT(t,f,w,h);
    }

    void  glBindFramebufferEXT (GLenum t, GLuint b) const
    {
        p_glBindFramebufferEXT(t,b);
    }

    void  glDeleteFramebuffersEXT (GLsizei n, const GLuint *b) const
    {
        p_glDeleteFramebuffersEXT(n,b);
    }

    void  glGenFramebuffersEXT (GLsizei n, GLuint *b) const
    {
        p_glGenFramebuffersEXT(n,b);
    }

    GLenum  glCheckFramebufferStatusEXT (GLenum p)
    {
        return p_glCheckFramebufferStatusEXT(p);
    }
    void  glFramebufferTexture1DEXT (GLenum, GLenum, GLenum, GLuint, GLint);

    void  glFramebufferTexture2DEXT (GLenum t, GLenum a, GLenum tt, GLuint o, GLint l) const
    {
        p_glFramebufferTexture2DEXT(t,a,tt,o,l);
    }

    void  glFramebufferRenderbufferEXT (GLenum t, GLenum a, GLenum rt, GLuint r) const
    {
        p_glFramebufferRenderbufferEXT(t,a,rt,r);
    }

    void  glGetFramebufferAttachmentParameterivEXT (GLenum t, GLenum a, GLenum q, GLint *v) const
    {
        p_glFramebufferAttachmentParameterivEXT(t,a,q,v);
    }

};


#endif // INC_OGLWIN32APP_H