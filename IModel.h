#pragma once

#include <memory>

struct IModel
{
    virtual ~IModel() {}
    
    virtual void DoCreateFile() = 0;
    virtual void DoImportFromFile() = 0;
    virtual void DoExportToFile() = 0;
    
    virtual void SetModelObserver(std::shared_ptr<IObserver> modelObserver) = 0;
    
    virtual void AddFigureToDocument(EventType event_type, const FigureData& data) = 0;
    virtual void DeleteFigureFromDocument(EventType event_type, const FigureData& data) = 0;
};
