/* ========================= eCAL LICENSE =================================
 *
 * Copyright (C) 2016 - 2019 Continental Corporation
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * 
 *      http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * ========================= eCAL LICENSE =================================
*/

#include "DescriptionWidget.h"

#include "QEcalPlay.h"

DescriptionWidget::DescriptionWidget(QWidget *parent)
  : QWidget(parent)
{
  ui_.setupUi(this);

  connect(QEcalPlay::instance(), &QEcalPlay::measurementLoadedSignal, this, &DescriptionWidget::measurementLoaded);
  connect(QEcalPlay::instance(), &QEcalPlay::measurementClosedSignal, this, &DescriptionWidget::measurementClosed);

  if (QEcalPlay::instance()->isMeasurementLoaded())
  {
    measurementLoaded(QEcalPlay::instance()->measurementPath());
  }
}

DescriptionWidget::~DescriptionWidget()
{
}

void DescriptionWidget::measurementLoaded(const QString& /*path*/)
{
  ui_.textEdit->setText(QEcalPlay::instance()->description());
}

void DescriptionWidget::measurementClosed()
{
  ui_.textEdit->clear();
}
