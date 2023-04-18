#pragma once

struct FigureData;
enum class EventType;

struct IObserver
{
    virtual ~IObserver() {};
    
    virtual void Update(EventType type) = 0;
    virtual void Update(EventType type, const FigureData& data) = 0;
};

