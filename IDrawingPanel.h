#pragma once

#include <memory>

#include "IObserver.h"

struct Point;

struct IDrawingPanel
{
    virtual ~IDrawingPanel() {};
    virtual void SetUserInput(const Point& click1, const Point& click2) = 0;
};

struct IObservableDrawingPanel : public IDrawingPanel, public IObserver
{
    virtual ~IObservableDrawingPanel() {};
    virtual void AddObserver(std::shared_ptr<IObserver>& observer) = 0;
};
