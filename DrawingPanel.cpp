#include <iostream>

#include "DrawingPanel.h"

using namespace std;

DrawingPanel::DrawingPanel() : mEventType(EventType::USER_DRAW_ON_PANEL) {}

void DrawingPanel::AddObserver(std::shared_ptr<IObserver>& observer)
{
    if(observer)
        mObservers.push_back(observer);
}

void DrawingPanel::NotifyUpdate()
{
   for (const auto& observer : mObservers)
   {
       if(observer)
           observer->Update(mEventType, {mClick1, mClick2});
   }
}

void DrawingPanel::SetUserInput(const Point& click1, const Point& click2)
{
    mClick1 = click1;
    mClick2 = click2;
    
    NotifyUpdate();
}

void DrawingPanel::Update(EventType type, const FigureData& )
{
    switch(type)
    {
        case EventType::DRAW_RECTANGLE_FIGURE:
            cout << "DrawingPanel: Drawing rectangle on panel" << endl;
        break;
        case EventType::DRAW_CIRCLE_FIGURE:
            cout << "DrawingPanel: Drawing circle on panel" << endl;
        break;
        case EventType::DRAW_TRIANGLE_FIGURE:
            cout << "DrawingPanel: Drawing triangle on panel" << endl;
        break;
        case EventType::DELETE_FIGURE: // remove figure from graphic area
            cout << "DrawingPanel: Need to delete figure" << endl;
        break;
        default:
        break;
    }
}
