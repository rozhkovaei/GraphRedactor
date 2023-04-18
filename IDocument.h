#pragma once

#include "IObserver.h"

struct FigureData;
enum class EventType;

struct IDocument
{
    virtual ~IDocument() {}
    
    virtual void Create() = 0;
    virtual void Import() = 0;
    virtual void Export() = 0;
    
    virtual void SetObserver(const std::shared_ptr<IObserver>& figureObserver) = 0;
    
    virtual void AddFigure(EventType event_type, const FigureData& data) = 0;
    virtual void DeleteFigure(EventType event_type, const FigureData& data) = 0;
};
