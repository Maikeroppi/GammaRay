/*
  commonresources.h

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

#ifndef GAMMARAY_COMMONRESOURCES_H
#define GAMMARAY_COMMONRESOURCES_H

#include "gammaray_common_export.h"

#include <QString>

namespace GammaRay {
namespace CommonResources {
    enum IconTheme {
        Unknown,
        Light,
        Dark,
        Default = Light
    };

    GAMMARAY_COMMON_EXPORT CommonResources::IconTheme currentIconTheme();
    GAMMARAY_COMMON_EXPORT void setCurrentIconTheme(CommonResources::IconTheme theme);

    GAMMARAY_COMMON_EXPORT QString themePath(CommonResources::IconTheme theme);
    GAMMARAY_COMMON_EXPORT QString themePath();

    GAMMARAY_COMMON_EXPORT QString themedPath(CommonResources::IconTheme theme, const QString &extra);
    GAMMARAY_COMMON_EXPORT QString themedPath(const QString &extra);
}
}

#endif // GAMMARAY_COMMONRESOURCES_H
