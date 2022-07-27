#ifndef MACROS
#define MACROS

#define CHECK_STRING_NOT_NULL(string, message, errcode) {\
    if (string.isEmpty ())\
    {\
        QMessageBox::information (this, "Select Files", message);\
        return errcode;\
    }\
}

#define CHANGE_TEXT(label1, label2, button, isEnabled) {\
    ui->lblLabel1->setText (label1);\
    ui->lblLabel2->setText (label2);\
    ui->pbDo->setText (button);\
    ui->lePath2->setVisible (isEnabled);\
    ui->pbBrowse2->setVisible (isEnabled);\
    ui->lePath2->setReadOnly (true);\
}

#define STATUS_BAR_INITIAL_UPDATE {\
    if (ui->rbCopy->isChecked ())\
    {\
        ui->statusBar->showMessage ("Copying file");\
    }\
    else if (ui->rbMove->isChecked ())\
    {\
        ui->statusBar->showMessage ("Moving file");\
    }\
    else if (ui->rbRemove->isChecked ())\
    {\
        ui->statusBar->showMessage ("Removing file");\
    }\
    else if (ui->rbRename->isChecked ())\
    {\
        ui->statusBar->showMessage ("Renaming file");\
    }\
    else\
    {\
        QMessageBox::information (this, "Operation Error", "Please select a File Operation");\
        return;\
    }\
}

#define STATUS_BAR_FINAL_UPDATE {\
    if (ui->rbCopy->isChecked ())\
    {\
        ui->statusBar->showMessage ("File Copied successfully");\
    }\
    else if (ui->rbMove->isChecked ())\
    {\
        ui->statusBar->showMessage ("File Moved successfully");\
    }\
    else if (ui->rbRemove->isChecked ())\
    {\
        ui->statusBar->showMessage ("File Deleted successfully");\
    }\
    else if (ui->rbRename->isChecked ())\
    {\
        ui->statusBar->showMessage ("File Renamed successfully");\
    }\
    else\
    {\
        QMessageBox::information (this, "Operation Error", "Please select a File Operation");\
        return;\
    }\
}


#endif // MACROS

