#include <iostream>
#include <string>
#include <map>

#include "Button.h"
#include "Controller.h"
#include "IGUI.h"
#include "DrawingPanel.h"
#include "Utils.h"
#include "Model.h"

using namespace std;

class GUI : public IGUI
{
public:

    GUI(std::shared_ptr<IObserver> gui_observer) :  mGUIObserver(gui_observer)
    {
        Init();
    }
    
    virtual std::shared_ptr<IObserver> GetModelObserver() override
    {
        return mPanel;
    }
    
    virtual void PressCreateButton() override
    {
        mButtons[ButtonType::CREATE_BUTTON]->Press();
    }
    
    virtual void PressImportButton() override
    {
        mButtons[ButtonType::IMPORT_BUTTON]->Press();
    }
    
    virtual void PressExportButton() override
    {
        mButtons[ButtonType::EXPORT_BUTTON]->Press();
    }
    
    virtual void PressDrawRectButton() override
    {
        mButtons[ButtonType::DRAW_RECT_BUTTON]->Press();
    }
    
    virtual void PressDrawCircleButton() override
    {
        mButtons[ButtonType::DRAW_CIRCLE_BUTTON]->Press();
    }
    
    virtual void PressDrawTriangleButton() override
    {
        mButtons[ButtonType::DRAW_TRIANGLE_BUTTON]->Press();
    }
    
    void PressDeleteButton() override
    {
        mButtons[ButtonType::DELETE_BUTTON]->Press();
    }
    
    virtual void UserDraw(const Point& click1, const Point& click2) override
    {
        mPanel->SetUserInput(click1, click2);
    }
    
private:
    
    void Init() // create all buttons
    {
        mButtons[ButtonType::CREATE_BUTTON] = make_unique<CreateButton>();
        mButtons[ButtonType::CREATE_BUTTON]->AddObserver(mGUIObserver);
        
        mButtons[ButtonType::IMPORT_BUTTON] = make_unique<ImportButton>();
        mButtons[ButtonType::IMPORT_BUTTON]->AddObserver(mGUIObserver);
        
        mButtons[ButtonType::EXPORT_BUTTON] = make_unique<ExportButton>();
        mButtons[ButtonType::EXPORT_BUTTON]->AddObserver(mGUIObserver);
        
        mButtons[ButtonType::DRAW_RECT_BUTTON] = make_unique<DrawRectButton>();
        mButtons[ButtonType::DRAW_RECT_BUTTON]->AddObserver(mGUIObserver);
        
        mButtons[ButtonType::DRAW_CIRCLE_BUTTON] = make_unique<DrawCircleButton>();
        mButtons[ButtonType::DRAW_CIRCLE_BUTTON]->AddObserver(mGUIObserver);
        
        mButtons[ButtonType::DRAW_TRIANGLE_BUTTON] = make_unique<DrawTriangleButton>();
        mButtons[ButtonType::DRAW_TRIANGLE_BUTTON]->AddObserver(mGUIObserver);
        
        mButtons[ButtonType::DELETE_BUTTON] = make_unique<DeleteButton>();
        mButtons[ButtonType::DELETE_BUTTON]->AddObserver(mGUIObserver);
        
        mPanel = make_shared<DrawingPanel>();
        mPanel->AddObserver(mGUIObserver);
    }
    
    std::shared_ptr<IObserver> mGUIObserver;
    map<ButtonType, unique_ptr<IObservableButton>> mButtons;
    std::shared_ptr<IObservableDrawingPanel> mPanel;
};


int main()
{
    shared_ptr<IController> controller = make_shared<Controller>();
    shared_ptr<IModel> model = make_shared<Model>();
    controller->SetModelObject(model);
    
    unique_ptr<IGUI> gui = make_unique<GUI>(controller);
    
    model->SetModelObserver(gui->GetModelObserver());
    
    gui->PressCreateButton();
    gui->PressImportButton();
    gui->PressExportButton();
    
    gui->PressDrawRectButton();
    gui->UserDraw({0, 0}, {1, 1});
    
    gui->PressDrawCircleButton();
    gui->UserDraw({10, 10}, {21, 21});
    
    gui->PressDrawTriangleButton();
    gui->UserDraw({50, 50}, {53, 53});
    
    gui->UserDraw({10, 10}, {21, 21});
    gui->PressDeleteButton();
}
