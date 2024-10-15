//
// Created by twak on 07/10/2019.
//

#include "responsive_layout.h"
#include "responsive_label.h"
#include <iostream>

//using namespace std;

// you should probably make extensive changes to this function
void ResponsiveLayout::setGeometry(const QRect &r /* our layout should always fit inside r */ ) {

    QLayout::setGeometry(r);

    // get the width of the windows
    int windowWidth = r.width();

    // set layout according to different screen sizes
    if (windowWidth < 481) {
        // small screen: using a single column layout
        for (int i = 0; i < list_.size(); i++) {
            QLayoutItem *o = list_.at(i);

            try {
                // convert components into custom ResponsiveLabels
                ResponsiveLabel *label = static_cast<ResponsiveLabel *>(o->widget());

                if (label == NULL) {
                    std::cout << "warning, unknown widget class in layout" << std::endl;
                }
                else if (label->text() == kNavTabs) {
                    // top navigation bar, occupying full width
                    label->setGeometry(0 + r.x(), 0 + r.y(), r.width(), 40);
                }
                else if (label->text() == kSearchButton) {
                    // the search results are displayed in the middle
                    label->setGeometry(r.width() - 65 + r.x(), 45 + r.y(), 60, 40);
                }
                else if (label->text() == kSearchResult) {
                    // the search results are displayed in the middle
                    label->setGeometry(10 + r.x(), 100 + r.y(), r.width() - 20, 60);
                }
                else {
                    // hide unnecessary components
                    label->setGeometry(-1, -1, 0, 0);;
                }
            }
            catch (const std::bad_cast& e) {
                std::cout << "warning, unknown widget class in layout" << std::endl;
            }
        }
    }
    else if (windowWidth >= 481 && windowWidth <= 1024) {
        // medium screen: using dual row layout
        for (int i = 0; i < list_.size(); i++) {
            QLayoutItem *o = list_.at(i);

            try {
                ResponsiveLabel *label = static_cast<ResponsiveLabel *>(o->widget());

                if (label == NULL) {
                    std::cout << "warning, unknown widget class in layout" << std::endl;
                }
                else if (label->text() == kNavTabs) {
                    // top navigation bar
                    label->setGeometry(0 + r.x(), 0 + r.y(), r.width(), 40);
                }
                else if (label->text() == kSearchButton) {
                    // the search button is located on the top right side
                    label->setGeometry(r.width() - 65 + r.x(), 45 + r.y(), 60, 40);
                }
                else if (label->text() == kSearchResult) {
                    // double column layout, with each column
                    // width being half of the window width
                    int colWidth = r.width() / 2 - 20;
                    int rowHeight = 100;
                    label->setGeometry(10 + r.x(), 100 + r.y(), colWidth, rowHeight);
                }
            }
            catch (const std::bad_cast& e) {
                std::cout << "warning, unknown widget class in layout" << std::endl;
            }
        }
    }
    else {
        // large screen: using a three column layout
        for (int i = 0; i < list_.size(); i++) {
            QLayoutItem *o = list_.at(i);

            try {
                ResponsiveLabel *label = static_cast<ResponsiveLabel *>(o->widget());

                if (label == NULL) {
                    std::cout << "warning, unknown widget class in layout" << std::endl;
                }
                else if (label->text() == kNavTabs) {
                    // top navigation bar
                    label->setGeometry(0 + r.x(), 0 + r.y(), r.width(), 40);
                }
                else if (label->text() == kSearchButton) {
                    // the search button is located on the top right side
                    label->setGeometry(r.width() - 65 + r.x(), 45 + r.y(), 60, 40);
                }
                else if (label->text() == kSearchResult) {
                    // three column layout, with
                    // each column width being one-third of the window width
                    int colWidth = r.width() / 3 - 20;
                    int rowHeight = 100;
                    label->setGeometry(10 + r.x(), 100 + r.y(), colWidth, rowHeight);
                }
            }
            catch (const std::bad_cast& e) {
                std::cout << "warning, unknown widget class in layout" << std::endl;
            }
        }
    }
}


// following methods provide a trivial list-based implementation of the QLayout class
int ResponsiveLayout::count() const {
    return list_.size();
}

QLayoutItem *ResponsiveLayout::itemAt(int idx) const {
    return list_.value(idx);
}

QLayoutItem *ResponsiveLayout::takeAt(int idx) {
    return idx >= 0 && idx < list_.size() ? list_.takeAt(idx) : 0;
}

void ResponsiveLayout::addItem(QLayoutItem *item) {
    list_.append(item);
}

QSize ResponsiveLayout::sizeHint() const {
    return minimumSize();
}

QSize ResponsiveLayout::minimumSize() const {
    return QSize(320,320);
}

ResponsiveLayout::~ResponsiveLayout() {
    QLayoutItem *item;
    while ((item = takeAt(0)))
        delete item;
}
