#include <iostream>

#include "Utils.h"
#include "Controller.h"

using namespace std;

Controller::Controller() {}
    
void Controller::SetModelObject(const std::shared_ptr<IModel>& model)
{
    mModel = model;
}

void Controller::Update(EventType type)
{
    switch(type)
    {
        case EventType::BUTTON_CREATE_PRESSED:
            cout << "Controller: Create button pressed" << endl;
            if(mModel)
                mModel->DoCreateFile();
            mCurrentEventType = type;
        break;
            
        case EventType::BUTTON_IMPORT_PRESSED:
            cout << "Controller: Import button pressed" << endl;
            if(mModel)
                mModel->DoImportFromFile();
            mCurrentEventType = type;
        break;
            
        case EventType::BUTTON_EXPORT_PRESSED:
            cout << "Controller: Export button pressed" << endl;
            if(mModel)
                mModel->DoExportToFile();
            mCurrentEventType = type;
        break;
        
        case EventType::BUTTON_DELETE_PRESSED:
            cout << "Controller: Delete button pressed" << endl;
            if(mCurrentEventType == EventType::USER_DRAW_ON_PANEL)
            {
                if(mModel)
                {
                    mModel->DeleteFigureFromDocument(type, mPointEvent);
                }
            }
            mCurrentEventType = type;
        break;
            
        case EventType::BUTTON_DRAW_RECT_PRESSED:
            cout << "Controller: Draw rectangle button pressed" << endl;
            mCurrentEventType = type;
        break;
            
        case EventType::BUTTON_DRAW_CIRCLE_PRESSED:
            cout << "Controller: Draw circle button pressed" << endl;
            mCurrentEventType = type;
        break;
            
        case EventType::BUTTON_DRAW_TRIANGLE_PRESSED:
            cout << "Controller: Draw triangle button pressed" << endl;
            mCurrentEventType = type;
        break;
            
        default:
        break;
    }
}

void Controller::Update(EventType type, const FigureData& data)
{
    switch(type)
    {
        case EventType::USER_DRAW_ON_PANEL:
            cout << "Controller: User drew on panel" << endl;
            cout << "Controller: user point1: " << data.point1.x << "." << data.point1.y << "; point2: " << data.point2.x << "." << data.point2.y << endl;
                
            if(mCurrentEventType == EventType::BUTTON_DRAW_TRIANGLE_PRESSED ||
               mCurrentEventType == EventType::BUTTON_DRAW_CIRCLE_PRESSED ||
               mCurrentEventType == EventType::BUTTON_DRAW_RECT_PRESSED)
            {
                if(mModel)
                    mModel->AddFigureToDocument(mCurrentEventType, data);
            }
            else // store data
            {
                mPointEvent = data;
            }
            mCurrentEventType = type;
        break;

        default:
        break;
    }
}
