#pragma once

#include <vector>

#include "IButton.h"
#include "Utils.h"

class Button : public IObservableButton
{
public:

    Button(ButtonType type, EventType event_type);
    
    virtual void Press() override;
    virtual void AddObserver(const std::shared_ptr<IObserver>& observer) override;
     
    ButtonType GetType();

private:
    
    void NotifyUpdate();
    
    ButtonType mType;
    EventType mEventType;
    
    std::vector<std::shared_ptr<IObserver>> mObservers;
};

class ImportButton : public Button
{
public:
    ImportButton() : Button(ButtonType::IMPORT_BUTTON, EventType::BUTTON_IMPORT_PRESSED) {}
};

class ExportButton : public Button
{
public:
    ExportButton() : Button(ButtonType::EXPORT_BUTTON, EventType::BUTTON_EXPORT_PRESSED) {}
};

class CreateButton : public Button
{
public:
    CreateButton() : Button(ButtonType::CREATE_BUTTON, EventType::BUTTON_CREATE_PRESSED) {}
};

class DrawRectButton : public Button
{
public:
    DrawRectButton() : Button(ButtonType::DRAW_RECT_BUTTON, EventType::BUTTON_DRAW_RECT_PRESSED) {}
};

class DrawCircleButton : public Button
{
public:
    DrawCircleButton() : Button(ButtonType::DRAW_CIRCLE_BUTTON, EventType::BUTTON_DRAW_CIRCLE_PRESSED) {}
};

class DrawTriangleButton : public Button
{
public:
    DrawTriangleButton() : Button(ButtonType::DRAW_TRIANGLE_BUTTON, EventType::BUTTON_DRAW_TRIANGLE_PRESSED) {}
};

class DeleteButton : public Button
{
public:
    DeleteButton() : Button(ButtonType::DELETE_BUTTON, EventType::BUTTON_DELETE_PRESSED) {}
};
