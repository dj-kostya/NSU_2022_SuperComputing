//
// Created by konstantin on 22.05.22.
//

#ifndef TASK1_RETRACEJOB_HPP
#define TASK1_RETRACEJOB_HPP

#include "IJob.h"
#include "minirt/minirt.h"
#pragma once
using namespace minirt;

struct Point {
    int x;
    int y;

    Point(int x, int y) : x(x), y(y) {}
};

class RetraceJob : public IJob {
private:


    Scene &scene;
    Image &image;
    ViewPlane &viewPlane;
    Point cur_point;
public:
    RetraceJob(Scene &scene, Image &image, ViewPlane &viewPlane, Point &curPoint);

    void Execute() override;

};


#endif //TASK1_RETRACEJOB_HPP
