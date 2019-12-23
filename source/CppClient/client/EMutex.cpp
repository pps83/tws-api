/* Copyright (C) 2019 Interactive Brokers LLC. All rights reserved. This code is subject to the terms
 * and conditions of the IB API Non-Commercial License or the IB API Commercial License, as applicable. */

#include "stdafx.h"
#include "EMutex.h"

EMutex::EMutex() {
}

EMutex::~EMutex(void) {
}

bool EMutex::TryEnter() {
    return cs.try_lock();
}

void EMutex::Enter() {
    cs.lock();  
}

void EMutex::Leave() {
    cs.unlock();  
}


EMutexGuard::EMutexGuard(EMutex& m) : m_mutex(m) {
    m_mutex.Enter();
}

EMutexGuard::~EMutexGuard() {
    m_mutex.Leave();
}
