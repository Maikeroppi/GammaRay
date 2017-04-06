/*
  uiresources.cpp

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

#include "uiresources.h"

#include <QFile>
#include <QPair>
#include <QHash>

using namespace GammaRay;

namespace GammaRay {
typedef QPair<CommonResources::IconTheme, QString> PairThemeFileName;
typedef QHash<PairThemeFileName, QString> HashedThemeFilePaths;
static HashedThemeFilePaths s_cachedFilePaths;
}

QIcon UIResources::themedIcon(CommonResources::IconTheme theme, const QString &filePath)
{
    const auto pair = PairThemeFileName(theme, filePath);
    auto it = s_cachedFilePaths.find(pair);

    if (it == s_cachedFilePaths.end()) {
        QString candidate = CommonResources::themedPath(theme, filePath);
        // Fallback to default theme icons
        if (theme != CommonResources::Default && !QFile::exists(candidate)) {
            candidate = CommonResources::themedPath(CommonResources::Default, filePath);
        }

        it = s_cachedFilePaths.insert(pair, candidate);
        Q_ASSERT_X(QFile::exists(*it), "themedIcon", qPrintable(*it));
    }

    return QIcon(*it);
}

QIcon UIResources::themedIcon(const QString &filePath)
{
    return themedIcon(CommonResources::currentIconTheme(), filePath);
}
