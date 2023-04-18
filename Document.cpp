#include <string>
#include <iostream>

#include "Document.h"
#include "FileDialog.h"
#include "Figure.h"

using namespace std;

void Document::Create()
{
    FileDialog dlg;
    string file_path = dlg.GetOpenFilePath();
    
    cout << "Created file " << file_path << endl;
}

void Document::Import()
{
    FileDialog dlg;
    string file_path = dlg.GetOpenFilePath();
    
    cout << "Import from " << file_path << endl;
    
    //todo: import all figures
}

void Document::Export()
{
    FileDialog dlg;
    string file_path = dlg.GetSaveFilePath();
    
    cout << "Export to " << file_path << endl;
    
    // todo: export all figures
}

void Document::SetObserver(const std::shared_ptr<IObserver>& figureObserver)
{
    mFigureObserver = figureObserver;
}

void Document::AddFigure(EventType event_type, const FigureData& data)
{
    switch(event_type)
    {
        case EventType::BUTTON_DRAW_RECT_PRESSED:
        {
            mFigures.emplace_back(std::make_unique<RectangleFigure>(data, mFigureObserver));
        }
        break;
        
        case EventType::BUTTON_DRAW_CIRCLE_PRESSED:
        {
            mFigures.emplace_back(std::make_unique<CircleFigure>(data, mFigureObserver));
        }
        break;
            
        case EventType::BUTTON_DRAW_TRIANGLE_PRESSED:
        {
            mFigures.emplace_back(std::make_unique<TriangleFigure>(data, mFigureObserver));
        }
        break;
            
        default:
        break;
    }
}

void Document::DeleteFigure(EventType , const FigureData& data)
{
    // find figures which intersect with data and delete them
    mFigures.remove_if([data](auto& figure){ return figure->CheckNeedDelete(data); });
}
