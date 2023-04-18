#pragma once

struct FigureData;

struct IFigure
{
    virtual ~IFigure() {};
    
    virtual bool CheckNeedDelete(const FigureData& data) = 0;
};
