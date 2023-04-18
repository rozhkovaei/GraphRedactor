#pragma once

#include "IObserver.h"

struct Point;

struct IGUI
{
    virtual ~IGUI() {};
    
    virtual void PressCreateButton() = 0;
    virtual void PressImportButton() = 0;
    virtual void PressExportButton() = 0;
    
    virtual void PressDrawRectButton() = 0;
    virtual void PressDrawCircleButton() = 0;
    virtual void PressDrawTriangleButton() = 0;

    virtual void PressDeleteButton() = 0;
    
    virtual void UserDraw(const Point& click1, const Point& click2) = 0;
    
    virtual std::shared_ptr<IObserver> GetModelObserver() = 0;
};
