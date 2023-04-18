#include "Figure.h"

Figure::Figure(FigureType type, EventType event_type, const FigureData& data, const std::shared_ptr<IObserver>& observer) :
    mType(type),
    mEventType(event_type),
    mData(data),
    mObserver(observer)
{
    NotifyUpdate();
}

Figure::~Figure()
{
}

FigureType Figure::GetType()
{
    return mType;
}

void Figure::NotifyUpdate()
{
   if(mObserver)
       mObserver->Update(mEventType, mData);
}

bool Figure::Intersects(const FigureData& data)
{
    // just simple check for now
    return mData.point1.x == data.point1.x && mData.point1.y == data.point1.y && mData.point2.x == data.point2.x && mData.point2.y == data.point2.y;
}

bool Figure::CheckNeedDelete(const FigureData& data)
{
    bool res = Intersects(data);
    if(res)
    {
        mEventType = EventType::DELETE_FIGURE;
        NotifyUpdate();
    }
    return res;
}
