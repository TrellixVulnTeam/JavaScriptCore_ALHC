/*
 * Copyright (C) 2014 Apple Inc. All rights reserved.
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
 * THIS SOFTWARE IS PROVIDED BY APPLE INC. AND ITS CONTRIBUTORS ``AS IS''
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL APPLE INC. OR ITS CONTRIBUTORS
 * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
 * THE POSSIBILITY OF SUCH DAMAGE.
 */

#pragma once

#if USE(QUICK_LOOK)

#include "QuickLookDocumentData.h"
#include <WebCore/QuickLookHandleClient.h>
#include <wtf/text/WTFString.h>

namespace WebCore {
class QuickLookHandle;
}

namespace WebKit {

class WebFrame;

class WebQuickLookHandleClient final : public WebCore::QuickLookHandleClient {
public:
    static Ref<WebQuickLookHandleClient> create(const String& fileName, const String& uti, uint64_t pageID)
    {
        return adoptRef(*new WebQuickLookHandleClient(fileName, uti, pageID));
    }
    ~WebQuickLookHandleClient();

    static void didReceivePassword(const String&, uint64_t pageID);

private:
    WebQuickLookHandleClient(const String& fileName, const String& uti, uint64_t pageID);
    void didReceiveDataArray(CFArrayRef) override;
    void didFinishLoading() override;
    void didFail() override;
    bool supportsPasswordEntry() const override { return true; }
    void didRequestPassword(Function<void(const String&)>&&) override;

    const String m_fileName;
    const String m_uti;
    const uint64_t m_pageID;
    QuickLookDocumentData m_data;
};

} // namespace WebKit

#endif // USE(QUICK_LOOK)
