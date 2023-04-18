#pragma once

#include "IController.h"

struct FigureData;

class Controller : public IController
{
public:
    Controller();
    
    virtual void Update(EventType type) override;
    virtual void Update(EventType type, const FigureData& data) override;
    
    virtual void SetModelObject(const std::shared_ptr<IModel>& model) override;
    
private:
    
    void CreateDocument();
    
    std::shared_ptr<IModel> mModel;
    EventType mCurrentEventType;
    FigureData mPointEvent;
};
