#include <string>
#include <iostream>

#include "Document.h"
#include "Model.h"

using namespace std;

void Model::CreateDocument()
{
    mDocument = make_unique<Document>();
    mDocument->SetObserver(mModelObserver);
}

void Model::DoCreateFile()
{
    CreateDocument();
    mDocument->Create();
}

void Model::DoImportFromFile()
{
    CreateDocument();
    mDocument->Import();
}

void Model::DoExportToFile()
{
    if(!mDocument)
        cout << "Model: No document to export!" << endl;
    else
    {
        mDocument->Export();
    }
}

void Model::SetModelObserver(std::shared_ptr<IObserver> modelObserver)
{
    mModelObserver = modelObserver;
}

void Model::AddFigureToDocument(EventType event_type, const FigureData& data)
{
    mDocument->AddFigure(event_type, data);
}

void Model::DeleteFigureFromDocument(EventType event_type, const FigureData& data)
{
    mDocument->DeleteFigure(event_type, data);
}
