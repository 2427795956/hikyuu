/*
 * ICos.cpp
 * 
 *  Copyright (c) 2019 hikyuu.org
 *
 *  Created on: 2019-5-1
 *      Author: fasiondog
 */

#include "ICos.h"

#if HKU_SUPPORT_SERIALIZATION
BOOST_CLASS_EXPORT(hku::ICos)
#endif


namespace hku {

ICos::ICos() : IndicatorImp("COS", 1) {

}

ICos::~ICos() {

}

bool ICos::check() {
    return true;
}

void ICos::_calculate(const Indicator& data) {
    size_t total = data.size();
    m_discard = data.discard();
    if (m_discard >= total) {
        m_discard = total;
        return;
    }

    for (size_t i = m_discard; i < total; ++i) {
        _set(std::cos(data[i]), i);
    }

}


Indicator HKU_API COS() {
    return Indicator(make_shared<ICos>());
}


} /* namespace hku */
