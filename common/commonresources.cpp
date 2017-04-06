/*
  commonresources.cpp

  This file is part of GammaRay, the Qt application inspection and
  manipulation tool.

  Copyright (C) 2014-2017 Klarälvdalens Datakonsult AB, a KDAB Group company, info@kdab.com
  Author: Filipe Azevedo <filipe.azevedo@kdab.com>

  Licensees holding valid commercial KDAB GammaRay licenses may use this file in
  accordance with GammaRay Commercial License Agreement provided with the Software.

  Contact info@kdab.com if any conditions of this licensing are not clear to you.

  This program is free software; you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 2 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "commonresources.h"

#include <QSettings>

#define GAMMARAY_ICON_THEME_NAME QLatin1String("GammaRay/IconTheme")

using namespace GammaRay;

namespace GammaRay {
static CommonResources::IconTheme s_currentTheme = CommonResources::Unknown;
}

CommonResources::IconTheme CommonResources::currentIconTheme()
{
    if (s_currentTheme == CommonResources::Unknown) {
        QSettings settings;
        s_currentTheme = static_cast<CommonResources::IconTheme>(settings.value(GAMMARAY_ICON_THEME_NAME, CommonResources::Default).toInt());
    }

    return s_currentTheme;
}

void CommonResources::setCurrentIconTheme(CommonResources::IconTheme theme)
{
    QSettings settings;
    settings.setValue(GAMMARAY_ICON_THEME_NAME, theme);
    s_currentTheme = theme;
}

QString CommonResources::themePath(CommonResources::IconTheme theme)
{
    switch (theme) {
    case CommonResources::Unknown:
        break;
    case CommonResources::Light:
        return QStringLiteral(":/gammaray/icons/ui/light");
    case CommonResources::Dark:
        return QStringLiteral(":/gammaray/icons/ui/dark");
    }

    return QString();
}

QString CommonResources::themePath()
{
    return themePath(CommonResources::currentIconTheme());
}

QString CommonResources::themedPath(CommonResources::IconTheme theme, const QString &extra)
{
    return QString::fromLatin1("%1/%2").arg(CommonResources::themePath(theme), extra);
}

QString CommonResources::themedPath(const QString &extra)
{
    return themedPath(CommonResources::currentIconTheme(), extra);
}
