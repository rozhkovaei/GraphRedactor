#pragma once

// эмулирует работу с диалоговыми окнами открыть/сохранить файл
struct IFileDialog
{
    virtual ~IFileDialog() {}
    
    virtual std::string GetOpenFilePath() = 0;
    virtual std::string GetSaveFilePath() = 0;
};
