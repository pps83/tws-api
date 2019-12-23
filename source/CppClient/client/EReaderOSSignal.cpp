/* Copyright (C) 2019 Interactive Brokers LLC. All rights reserved. This code is subject to the terms
 * and conditions of the IB API Non-Commercial License or the IB API Commercial License, as applicable. */

#include "stdafx.h"
#include "EReaderOSSignal.h"


EReaderOSSignal::EReaderOSSignal(unsigned long waitTimeout)
{
    signalled = false;
    m_waitTimeout = waitTimeout;
}

EReaderOSSignal::~EReaderOSSignal(void)
{
}

void EReaderOSSignal::issueSignal() {
    std::unique_lock<std::mutex> lock(mx);
    signalled = true;
    cv.notify_one();
}

void EReaderOSSignal::waitForSignal() {
    std::unique_lock<std::mutex> lock(mx);
    if (!signalled)
        cv.wait_for(lock, std::chrono::milliseconds(m_waitTimeout), [this] { return signalled; });
    signalled = false;
}
