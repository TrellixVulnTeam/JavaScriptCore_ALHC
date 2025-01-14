/*
 * Copyright (C) 2017 Apple Inc. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY APPLE INC. ``AS IS'' AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL APPLE INC. OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY
 * OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "config.h"
#include "WebGPUDepthStencilDescriptor.h"

#if ENABLE(WEBGPU)

/* FIXME: WebGPU - Not implemented yet.
#include "GPUDepthStencilDescriptor.h"
*/
#include "WebGPURenderingContext.h"

namespace WebCore {

Ref<WebGPUDepthStencilDescriptor> WebGPUDepthStencilDescriptor::create()
{
    return adoptRef(*new WebGPUDepthStencilDescriptor());
}

WebGPUDepthStencilDescriptor::WebGPUDepthStencilDescriptor()
    : WebGPUObject()
{
    m_depthStencilDescriptor = GPUDepthStencilDescriptor::create();
}

WebGPUDepthStencilDescriptor::~WebGPUDepthStencilDescriptor()
{
}

String WebGPUDepthStencilDescriptor::label() const
{
    if (!m_depthStencilDescriptor)
        return emptyString();

    return m_depthStencilDescriptor->label();
}

void WebGPUDepthStencilDescriptor::setLabel(const String& label)
{
    if (!m_depthStencilDescriptor)
        return;

    m_depthStencilDescriptor->setLabel(label);
}

bool WebGPUDepthStencilDescriptor::depthWriteEnabled() const
{
    if (!m_depthStencilDescriptor)
        return false;

    return m_depthStencilDescriptor->depthWriteEnabled();
}

void WebGPUDepthStencilDescriptor::setDepthWriteEnabled(bool newDepthWriteEnabled)
{
    if (!m_depthStencilDescriptor)
        return;

    m_depthStencilDescriptor->setDepthWriteEnabled(newDepthWriteEnabled);
}

auto WebGPUDepthStencilDescriptor::depthCompareFunction() const -> WebGPUCompareFunction
{
    return m_depthCompareFunction;
}

void WebGPUDepthStencilDescriptor::setDepthCompareFunction(CompareFunction newDepthCompareFunction)
{
    m_depthCompareFunction = newDepthCompareFunction;
    m_depthStencilDescriptor->setDepthCompareFunction(toGPUCompareFunction(m_depthCompareFunction));

// FIXME: WebGPU - not implemented yet.
//    if (Optional<WebGPUCompareFunction> compareFunction = toWebGPUCompareFunction(newDepthCompareFunction)) {
//        m_depthCompareFunction = compareFunction.value();
//        m_depthStencilDescriptor->setDepthCompareFunction(toGPUCompareFunction(m_depthCompareFunction));
//    }
}

} // namespace WebCore

#endif
