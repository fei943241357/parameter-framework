/*
 * Copyright (c) 2011-2015, Intel Corporation
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice, this
 * list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 * this list of conditions and the following disclaimer in the documentation and/or
 * other materials provided with the distribution.
 *
 * 3. Neither the name of the copyright holder nor the names of its contributors
 * may be used to endorse or promote products derived from this software without
 * specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
#pragma once

#include "parameter_export.h"

#include "SubsystemObject.h"
#include "MappingContext.h"
#include <string>

class PARAMETER_EXPORT CSubsystemObjectCreator
{
public:
    CSubsystemObjectCreator(const std::string &strMappingKey, uint32_t uiAncestorIdMask,
                            size_t maxConfigurableElementSize);

    // Accessors
    const std::string &getMappingKey() const;
    uint32_t getAncestorMask() const;
    size_t getMaxConfigurableElementSize() const;

    // Object creation
    virtual CSubsystemObject *objectCreate(
        const std::string &strMappingValue,
        CInstanceConfigurableElement *pInstanceConfigurableElement, const CMappingContext &context,
        core::log::Logger &logger) const = 0;

    virtual ~CSubsystemObjectCreator() = default;

private:
    // Mapping key
    std::string _strMappingKey;
    // Mask of must-be-specified ancestors
    uint32_t _uiAncestorIdMask;
    // Masximum expected size for configurable elment (-1 means none)
    size_t _maxConfigurableElementSize;
};
