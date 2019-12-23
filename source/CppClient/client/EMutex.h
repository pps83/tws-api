/* Copyright (C) 2019 Interactive Brokers LLC. All rights reserved. This code is subject to the terms
 * and conditions of the IB API Non-Commercial License or the IB API Commercial License, as applicable. */

#pragma once
#ifndef TWS_API_CLIENT_EMUTEX_H
#define TWS_API_CLIENT_EMUTEX_H

#include <mutex>

class TWSAPIDLLEXP EMutex
{
    std::mutex cs;

public:
    EMutex();
    ~EMutex();
    bool TryEnter();
    void Enter();
    void Leave();
};


class TWSAPIDLLEXP EMutexGuard
{
    EMutex& m_mutex;
public:
    EMutexGuard(EMutex& m);
    ~EMutexGuard();

private:
    // disable copy ctor (compatible with pre C++11 compiler hence =delete not used)
    EMutexGuard(const EMutex&);
};

#endif