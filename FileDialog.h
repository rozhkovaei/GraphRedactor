#pragma once

#include "IFileDialog.h"

class FileDialog : public IFileDialog
{
public:
    
    FileDialog();
    
    virtual std::string GetOpenFilePath() override;
    virtual std::string GetSaveFilePath() override;
};
