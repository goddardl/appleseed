
//
// This source file is part of appleseed.
// Visit http://appleseedhq.net/ for additional information and resources.
//
// This software is released under the MIT license.
//
// Copyright (c) 2010-2013 Francois Beaune, Jupiter Jazz Limited
// Copyright (c) 2014-2015 Francois Beaune, The appleseedhq Organization
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
//

#ifndef APPLESEED_RENDERER_KERNEL_RENDERING_IFRAMERENDERER_H
#define APPLESEED_RENDERER_KERNEL_RENDERING_IFRAMERENDERER_H

// appleseed.foundation headers.
#include "foundation/core/concepts/iunknown.h"

namespace renderer
{

//
// Frame renderer interface.
//

class IFrameRenderer
  : public foundation::IUnknown
{
  public:
    // Synchronous frame rendering.
    virtual void render() = 0;

    // Asynchronous frame rendering.
    virtual bool is_rendering() const = 0;
    virtual void start_rendering() = 0;
    virtual void stop_rendering() = 0;
    virtual void pause_rendering() = 0;
    virtual void resume_rendering() = 0;
    virtual void terminate_rendering() = 0;
};


//
// Interface of a IFrameRenderer factory that can cross DLL boundaries.
//

class IFrameRendererFactory
  : public foundation::IUnknown
{
  public:
    // Return a new frame renderer instance.
    virtual IFrameRenderer* create() = 0;
};

}       // namespace renderer

#endif  // !APPLESEED_RENDERER_KERNEL_RENDERING_IFRAMERENDERER_H
