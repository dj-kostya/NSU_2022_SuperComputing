//
// Created by konstantin on 22.05.22.
//

#include "RetraceJob.hpp"
//#include <iostream>




void PixelTask(const Scene &scene, Image &image, ViewPlane &viewPlane, Point point, size_t numOfSamples) {
//    std::cout << "LOG: RUN FOR " << point.x << " " << point.y << std::endl;

    const auto color = viewPlane.computePixel(scene, point.x, point.y, numOfSamples);
    image.set(point.x, point.y, color);
}


void RetraceJob::Execute() {
    PixelTask(scene, image, viewPlane, cur_point, numOfSamples);
}

RetraceJob::RetraceJob(Scene &scene, Image &image, ViewPlane &viewPlane, Point &curPoint, size_t numOfSamples)
        : scene(scene), viewPlane(viewPlane), image(image), cur_point(curPoint), numOfSamples(numOfSamples) {}
