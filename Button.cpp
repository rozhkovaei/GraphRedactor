#include <string>

#include "Button.h"

using namespace std;

Button::Button(ButtonType type, EventType event_type) :
    mType(type),
    mEventType(event_type)
{
}

void Button::Press()
{
    NotifyUpdate();
}

 ButtonType Button::GetType()
 {
     return mType;
 }

void Button::AddObserver(const std::shared_ptr<IObserver>& observer)
{
    if(observer)
        mObservers.push_back(observer);
}

void Button::NotifyUpdate()
{
   for (const auto& observer : mObservers)
   {
       if(observer)
           observer->Update(mEventType);
   }
}
