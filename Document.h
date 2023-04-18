#pragma once

#include <list>
#include <memory>

#include "IDocument.h"
#include "IFigure.h"
#include "Utils.h"

class Document : public IDocument
{
public:
    virtual void Create() override;
    virtual void Import() override;
    virtual void Export() override;
    
    virtual void AddFigure(EventType event_type, const FigureData& data) override;
    virtual void DeleteFigure(EventType event_type, const FigureData& data) override;
    
    virtual void SetObserver(const std::shared_ptr<IObserver>& figureObserver) override;
    
private:
    std::list<std::unique_ptr<IFigure>> mFigures;    
    std::shared_ptr<IObserver> mFigureObserver;
};
