/*
 * Copyright 2019 Google LLC.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

/**************************************************************************************************
 *** This file was autogenerated from GrComposeLerpEffect.fp; do not modify.
 **************************************************************************************************/
#ifndef GrComposeLerpEffect_DEFINED
#define GrComposeLerpEffect_DEFINED
#include "include/core/SkTypes.h"
#include "include/core/SkM44.h"

#include "src/gpu/GrCoordTransform.h"
#include "src/gpu/GrFragmentProcessor.h"
class GrComposeLerpEffect : public GrFragmentProcessor {
public:
    static std::unique_ptr<GrFragmentProcessor> Make(std::unique_ptr<GrFragmentProcessor> child1,
                                                     std::unique_ptr<GrFragmentProcessor> child2,
                                                     float weight) {
        return std::unique_ptr<GrFragmentProcessor>(
                new GrComposeLerpEffect(std::move(child1), std::move(child2), weight));
    }
    GrComposeLerpEffect(const GrComposeLerpEffect& src);
    std::unique_ptr<GrFragmentProcessor> clone() const override;
    const char* name() const override { return "ComposeLerpEffect"; }
    int child1_index = -1;
    int child2_index = -1;
    float weight;

private:
    GrComposeLerpEffect(std::unique_ptr<GrFragmentProcessor> child1,
                        std::unique_ptr<GrFragmentProcessor> child2,
                        float weight)
            : INHERITED(kGrComposeLerpEffect_ClassID, kNone_OptimizationFlags), weight(weight) {
        if (child1) {
            child1_index = this->numChildProcessors();
            this->registerChildProcessor(std::move(child1));
        }
        if (child2) {
            child2_index = this->numChildProcessors();
            this->registerChildProcessor(std::move(child2));
        }
    }
    GrGLSLFragmentProcessor* onCreateGLSLInstance() const override;
    void onGetGLSLProcessorKey(const GrShaderCaps&, GrProcessorKeyBuilder*) const override;
    bool onIsEqual(const GrFragmentProcessor&) const override;
    GR_DECLARE_FRAGMENT_PROCESSOR_TEST
    typedef GrFragmentProcessor INHERITED;
};
#endif
