//
// Created by twak on 14/10/2019.
//

#include "responsive_window.h"
#include "responsive_layout.h"
#include "screenshot.h"
#include <iostream>
#include <QApplication>


ResponsiveWindow::ResponsiveWindow() {

    setWindowTitle("2811: Coursework 1");
    setMinimumSize(320, 320);
    setMaximumSize(1280, 720);

    createWidgets();
}

void ResponsiveWindow::createWidgets() {

    ResponsiveLayout * rl = new ResponsiveLayout();

    // add all the widgets we need to demonstrate all layouts
    rl->addWidget(new ResponsiveLabel(kNavTabs));
    rl->addWidget(new ResponsiveLabel(kSearchButton));
    // we might have more than one search results
    rl->addWidget(new ResponsiveLabel(kSearchResult));
    rl->addWidget(new ResponsiveLabel(kSearchResult));
    // note that later widgets are drawn on top of earlier widgets

    setLayout(rl);
}


