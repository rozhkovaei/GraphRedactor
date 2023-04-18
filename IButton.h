#pragma once

#include <string>
#include <memory>

#include "IObserver.h"

struct IButton
{
    virtual ~IButton () {};
    
    virtual void Press() = 0;
};

struct IObservableButton : public IButton
{
    virtual ~IObservableButton() {};
    virtual void AddObserver(const std::shared_ptr<IObserver>& observer) = 0;
};
