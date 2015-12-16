/*
  paintanalyzer.h

  This file is part of GammaRay, the Qt application inspection and
  manipulation tool.

  Copyright (C) 2015 Klarälvdalens Datakonsult AB, a KDAB Group company, info@kdab.com
  Author: Volker Krause <volker.krause@kdab.com>

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

#ifndef GAMMARAY_PAINTANALYZER_H
#define GAMMARAY_PAINTANALYZER_H

#include "paintanalyzerinterface.h"

class QPaintBuffer;
class QPaintDevice;
class QRect;
class QTimer;

namespace GammaRay {

class PaintBufferModel;

/** Inspects individual operations on a QPainter. */
class PaintAnalyzer : public PaintAnalyzerInterface
{
    Q_OBJECT
    Q_INTERFACES(GammaRay::PaintAnalyzerInterface)
public:
    explicit PaintAnalyzer(const QString &name, QObject *parent = Q_NULLPTR);
    ~PaintAnalyzer();

    // call the following 4 methods in this order to trigger a paint analysis
    void beginAnalyzePainting();
    void setBoundingRect(const QRect &boundingBox);
    QPaintDevice* paintDevice() const;
    void endAnalyzePainting();

    /** Returns @c true if paint analysis is available (needs access to Qt private headers at compile time). */
    static bool isAvailable();

private slots:
    void update();
    void repaint();

private:
    PaintBufferModel *m_paintBufferModel;
    QPaintBuffer* m_paintBuffer;
    QTimer *m_repaintTimer;
};

}

#endif // GAMMARAY_PAINTANALYZER_H