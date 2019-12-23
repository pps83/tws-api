/* Copyright (C) 2019 Interactive Brokers LLC. All rights reserved. This code is subject to the terms
 * and conditions of the IB API Non-Commercial License or the IB API Commercial License, as applicable. */

#pragma once
#ifndef TWS_API_CLIENT_EREADEROSSIGNAL_H
#define TWS_API_CLIENT_EREADEROSSIGNAL_H

#include "EReaderSignal.h"
#include <stdexcept>
#include <mutex>
#include <condition_variable>
#include "platformspecific.h"

#if !defined(INFINITE)
#define INFINITE ((unsigned long)-1)
#endif

class TWSAPIDLLEXP EReaderOSSignal : public EReaderSignal
{
    std::mutex mx;
    std::condition_variable cv;
    bool signalled;
    unsigned long m_waitTimeout; // in milliseconds

public:
	EReaderOSSignal(unsigned long waitTimeout = INFINITE);
	virtual ~EReaderOSSignal(void);

	virtual void issueSignal();
	virtual void waitForSignal();
};

#endif