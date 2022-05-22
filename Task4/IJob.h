//
// Created by konstantin on 22.05.22.
//

#ifndef TASK1_IJOB_H
#define TASK1_IJOB_H
#pragma once

class IJob {

public:
    virtual ~IJob() = default;


    virtual void Execute() = 0;

};


#endif //TASK1_IJOB_H
