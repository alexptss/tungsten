#ifndef BIDIRECTIONALPATHTRACER_HPP_
#define BIDIRECTIONALPATHTRACER_HPP_

#include "BidirectionalPathTracerSettings.hpp"
#include "PathVertex.hpp"

#include "integrators/TraceBase.hpp"

#include "sampling/Distribution1D.hpp"

namespace Tungsten {

struct PathVertex;

class BidirectionalPathTracer : public TraceBase
{
    AtomicFramebuffer *_splatBuffer;

    std::unique_ptr<Distribution1D> _lightSampler;

    std::unique_ptr<LightPath> _cameraPath;
    std::unique_ptr<LightPath> _emitterPath;

public:
    BidirectionalPathTracer(TraceableScene *scene, const BidirectionalPathTracerSettings &settings, uint32 threadId);

    Vec3f traceSample(Vec2u pixel, SampleGenerator &sampler, UniformSampler &supplementalSampler);
};

}

#endif /* BIDIRECTIONALPATHTRACER_HPP_ */
