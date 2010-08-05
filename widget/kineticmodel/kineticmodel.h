/*
  This file is part of the Ofi Labs X2 project.

  Copyright (C) 2010 Ariya Hidayat <ariya.hidayat@gmail.com>

  Redistribution and use in source and binary forms, with or without
  modification, are permitted provided that the following conditions are met:

    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above copyright
      notice, this list of conditions and the following disclaimer in the
      documentation and/or other materials provided with the distribution.
    * Neither the name of the <organization> nor the
      names of its contributors may be used to endorse or promote products
      derived from this software without specific prior written permission.

  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
  ARE DISCLAIMED. IN NO EVENT SHALL <COPYRIGHT HOLDER> BE LIABLE FOR ANY
  DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
  (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
  ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
  THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#ifndef OFILABS_KINETICMODEL
#define OFILABS_KINETICMODEL

#include <QObject>
#include <QScopedPointer>

class KineticModelPrivate;

class KineticModel: public QObject
{
    Q_OBJECT
    Q_PROPERTY(qreal maximumSpeed READ maximumSpeed WRITE setMaximumSpeed)
    Q_PROPERTY(qreal deacceleration READ deacceleration WRITE setDeacceleration)
    Q_PROPERTY(qreal position READ position WRITE setPosition)
    Q_PROPERTY(int updateInterval READ updateInterval WRITE setUpdateInterval)

public:
    KineticModel(QObject *parent = 0);
    ~KineticModel();

    qreal maximumSpeed() const;
    qreal deacceleration() const;
    int updateInterval() const;
    qreal position() const;

public slots:
    void setMaximumSpeed(qreal speed);
    void setDeacceleration(qreal deacceleration);
    void setUpdateInterval(int ms);
    void setPosition(qreal pos);
    void resetSpeed();
    void release();

signals:
    void positionChanged(qreal position);

private slots:
    void update();

private:
    QScopedPointer<KineticModelPrivate> d_ptr;
    Q_DECLARE_PRIVATE(KineticModel);
    Q_DISABLE_COPY(KineticModel);
};

#endif