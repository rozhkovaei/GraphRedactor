#pragma once

#include <memory>

#include "IObserver.h"
#include "IModel.h"

struct IController : public IObserver
{
    virtual ~IController() {};
    
    virtual void SetModelObject(const std::shared_ptr<IModel>& model) = 0;
};
