#pragma once

#include <vector>

#include "IDrawingPanel.h"
#include "Utils.h"

class DrawingPanel : public IObservableDrawingPanel
{
public:
    DrawingPanel();
    
    virtual void SetUserInput(const Point& click1, const Point& click2) override;
    
    virtual void Update(EventType ) override {}
    virtual void Update(EventType type, const FigureData& data) override;
    
    virtual void AddObserver(std::shared_ptr<IObserver>& observer) override;
    
private:
    
    void NotifyUpdate();
    
    EventType mEventType;
    Point mClick1;
    Point mClick2;
    
    std::vector<std::shared_ptr<IObserver>> mObservers;
};
