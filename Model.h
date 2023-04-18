#pragma once

#include "IModel.h"
#include "Utils.h"
#include "IObserver.h"
#include "IDocument.h"

class Model : public IModel
{
public:
    virtual void DoCreateFile() override;
    virtual void DoImportFromFile() override;
    virtual void DoExportToFile() override;
    
    virtual void AddFigureToDocument(EventType event_type, const FigureData& data) override;
    virtual void DeleteFigureFromDocument(EventType event_type, const FigureData& data) override;
    
    virtual void SetModelObserver(std::shared_ptr<IObserver> modelObserver) override;
    
private:
    
    void CreateDocument();
    
    std::unique_ptr<IDocument> mDocument;
    std::shared_ptr<IObserver> mModelObserver;
};
