//
// Created by konstantin on 22.05.22.
//

#include "RetraceJob.hpp"
//#include <iostream>




void PixelTask(const Scene &scene, Image &image, ViewPlane &viewPlane, Point point) {
//    std::cout << "LOG: RUN FOR " << point.x << " " << point.y << std::endl;

    const auto color = viewPlane.computePixel(scene, point.x, point.y, 1);
    image.set(point.x, point.y, color);
}


void RetraceJob::Execute() {
    PixelTask(scene, image, viewPlane, cur_point);
}

RetraceJob::RetraceJob(Scene &scene, Image &image, ViewPlane &viewPlane, Point &curPoint)
        : scene(scene), viewPlane(viewPlane), image(image), cur_point(curPoint) {}
