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
#include "WebGPUCommandQueue.h"

#if ENABLE(WEBGPU)

/* FIXME: WebGPU - Not implemented yet.
#include "GPUCommandQueue.h"
*/
#include "WebGPUCommandBuffer.h"
#include "WebGPURenderingContext.h"

namespace WebCore {

Ref<WebGPUCommandQueue> WebGPUCommandQueue::create(WebGPURenderingContext* context)
{
    return adoptRef(*new WebGPUCommandQueue(context));
}

WebGPUCommandQueue::WebGPUCommandQueue(WebGPURenderingContext* context)
    : WebGPUObject(context)
{
    m_commandQueue = context->device()->createCommandQueue();
}

WebGPUCommandQueue::~WebGPUCommandQueue()
{
}

String WebGPUCommandQueue::label() const
{
    if (!m_commandQueue)
        return emptyString();

    return m_commandQueue->label();
}

void WebGPUCommandQueue::setLabel(const String& label)
{
    if (!m_commandQueue)
        return;

    m_commandQueue->setLabel(label);
}

RefPtr<WebGPUCommandBuffer> WebGPUCommandQueue::createCommandBuffer()
{
    RefPtr<WebGPUCommandBuffer> buffer = WebGPUCommandBuffer::create(this->context(), this);
    return buffer;
}

} // namespace WebCore

#endif
