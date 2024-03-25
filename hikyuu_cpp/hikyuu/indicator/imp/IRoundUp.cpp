/*
 * IRoundUp.cpp
 *
 *  Copyright (c) 2019 hikyuu.org
 *
 *  Created on: 2019-04-14
 *      Author: fasiondog
 */

#include "IRoundUp.h"

#if HKU_SUPPORT_SERIALIZATION
BOOST_CLASS_EXPORT(hku::IRoundUp)
#endif

namespace hku {

IRoundUp::IRoundUp() : IndicatorImp("ROUNDUP", 1) {
    setParam<int>("ndigits", 2);
}

IRoundUp::~IRoundUp() {}

bool IRoundUp::check() {
    return getParam<int>("ndigits") >= 0;
}

void IRoundUp::_checkParam(const string& name) const {
    if ("ndigits" == name) {
        HKU_ASSERT(getParam<int>("ndigits") >= 0);
    }
}

void IRoundUp::_calculate(const Indicator& data) {
    size_t total = data.size();
    m_discard = data.discard();
    if (m_discard >= total) {
        m_discard = total;
        return;
    }

    int n = getParam<int>("ndigits");
    auto const* src = data.data();
    auto* dst = this->data();
    for (size_t i = m_discard; i < total; ++i) {
        dst[i] = roundUp(src[i], n);
    }
}

Indicator HKU_API ROUNDUP(int ndigits) {
    IndicatorImpPtr p = make_shared<IRoundUp>();
    p->setParam<int>("ndigits", ndigits);
    return Indicator(p);
}

} /* namespace hku */
