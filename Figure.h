#pragma once

#include <vector>
#include <memory>

#include "IFigure.h"
#include "Utils.h"
#include "IObserver.h"

class Figure : public IFigure
{
public:
    Figure(FigureType type, EventType event_type, const FigureData& data, const std::shared_ptr<IObserver>& observer);
    ~Figure();
    
    virtual bool CheckNeedDelete(const FigureData& data) override;
    
    FigureType GetType();

private:
    
    bool Intersects(const FigureData& data);
    void NotifyUpdate();
    
    FigureType mType;
    EventType mEventType;
    FigureData mData;     // todo: add other features like brush type, line type, color
    
    std::shared_ptr<IObserver> mObserver;
};

class RectangleFigure : public Figure
{
public:
    RectangleFigure(const FigureData& data, const std::shared_ptr<IObserver>& observer) : Figure(FigureType::RECTANGLE, EventType::DRAW_RECTANGLE_FIGURE, data, observer) {}
};

class CircleFigure : public Figure
{
public:
    CircleFigure(const FigureData& data, const std::shared_ptr<IObserver>& observer) : Figure(FigureType::CIRCLE, EventType::DRAW_CIRCLE_FIGURE, data, observer) {}
};

class TriangleFigure : public Figure
{
public:
    TriangleFigure(const FigureData& data, const std::shared_ptr<IObserver>& observer) : Figure(FigureType::TRIANGLE, EventType::DRAW_TRIANGLE_FIGURE, data, observer) {}
};
